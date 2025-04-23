from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from crawler.models.GuangxiBusinessEditor import Base, News
from ..config.settings import DATABASE_URI
from datetime import datetime, timedelta
# 创建数据库引擎
engine = create_engine(DATABASE_URI, echo=True)
Base.metadata.create_all(engine)  # 创建表（如果不存在）

# 创建会话
Session = sessionmaker(bind=engine)
session = Session()

def save_to_db_guangxi_business_editor_upsert(state, title, link, date, views):
    """
    覆盖式更新数据到数据库（如果存在则更新，否则插入）
    """
    # 查询是否已存在相同标题的记录
    existing_news = session.query(News).filter_by(title=title).first()

    if existing_news:
        # 如果存在，则更新记录
        existing_news.state = state
        existing_news.link = link
        existing_news.date = date
        existing_news.views = views
        session.merge(existing_news)  # 使用 merge 更新记录
        session.commit()
        print(f"更新记录: {title}")
    else:
        # 如果不存在，则插入新记录
        news = News(state=state, title=title, link=link, date=date, views=views)
        session.add(news)
        session.commit()
        print(f"新增记录: {title}")




def fetch_data_from_db():
    """
    从数据库获取状态为“报名中”且距离当前时间为一个月的数据
    """
    try:
        # 获取当前时间
        now = datetime.now()
        # 计算一个月前的时间
        one_month_ago = now - timedelta(days=30)

        # 查询状态为“报名中”且日期在一个月内的记录
        data = session.query(News).filter(
            News.state == "报名中",  # 状态为“报名中”
            News.date >= one_month_ago.strftime("%Y-%m-%d")  # 日期在一个月内
        ).all()
        return data
    except Exception as e:
        print(f"数据库查询失败: {e}")
        return []
    finally:
        session.close()
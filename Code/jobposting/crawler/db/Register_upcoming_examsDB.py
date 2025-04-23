from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from crawler.models.Register_upcoming_exams import Register_upcoming_exams, Register_upcoming_examsDb
from ..config.settings import DATABASE_URI


# 创建数据库引擎
engine = create_engine(DATABASE_URI, echo=True)
Register_upcoming_exams.metadata.create_all(engine)  # 创建表（如果不存在）

# 创建会话
Session = sessionmaker(bind=engine)
session = Session()

def save_to_db_Register_upcoming_examsDb_upsert(title, link,publish_time):
    """
    覆盖式更新数据到数据库（如果存在则更新，否则插入）
    """
    print(f"Querying for title: {title}")
    existing_news = session.query(Register_upcoming_examsDb).filter_by(title=title).first()
    print(f"Existing news: {existing_news}")
    if existing_news:
        # 如果存在，则更新记录

        existing_news.link = link
        existing_news.publish_time=publish_time
        session.merge(existing_news)  # 使用 merge 更新记录
        session.commit()
        print(f"更新记录: {title}")
    else:
        # 如果不存在，则插入新记录
        news = Register_upcoming_examsDb(title=title, link=link, publish_time=publish_time)
        session.add(news)
        session.commit()
        print(f"新增记录: {title}")


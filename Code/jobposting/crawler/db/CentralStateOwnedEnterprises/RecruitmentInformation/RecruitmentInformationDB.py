from datetime import datetime, timedelta

from sqlalchemy import create_engine, desc
from sqlalchemy.orm import sessionmaker
from sqlalchemy.exc import SQLAlchemyError

import crawler.config.settings
from crawler.models.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformation import (
    RecruitmentBase,
    RecruitmentInformationDb,
)

# 创建数据库引擎
engine = create_engine(crawler.config.settings.DATABASE_URI, echo=True)
RecruitmentBase.metadata.create_all(engine)  # 创建表（如果不存在）

# 创建会话
Session = sessionmaker(bind=engine)
session = Session()


def save_to_db_RecruitmentInformationDb_upsert(recruitment_information_db: RecruitmentInformationDb):
    """
    覆盖式更新数据到数据库（如果存在则更新，否则插入）
    :param recruitment_information_db: RecruitmentInformationDb 对象
    """
    try:
        print(f"Querying for title: {recruitment_information_db.title}")
        existing_record = session.query(RecruitmentInformationDb).filter_by(
            title=recruitment_information_db.title
        ).first()
        print(f"Existing record: {existing_record}")

        if existing_record:
            # 如果存在，则直接覆盖更新
            session.merge(recruitment_information_db)  # 使用 merge 覆盖更新
            session.commit()
            print(f"更新记录: {recruitment_information_db.title}")
        else:
            # 如果不存在，则插入新记录
            session.add(recruitment_information_db)
            session.commit()
            print(f"新增记录: {recruitment_information_db.title}")
    except SQLAlchemyError as e:
        # 回滚事务并打印错误信息
        session.rollback()
        print(f"数据库操作失败: {e}")
    finally:
        # 关闭会话
        session.close()


def query_recent_15_days_data():
    """
    查询距今 15 天内的数据，并按 create_time 降序排序（距离今天近的在前）
    """
    try:
        # 计算 15 天前的时间
        fifteen_days_ago = datetime.now() - timedelta(days=15)

        # 查询 create_time 大于等于 15 天前的记录，并按 create_time 降序排序
        recent_records = session.query(RecruitmentInformationDb).filter(
            RecruitmentInformationDb.create_time >= fifteen_days_ago
        ).order_by(desc(RecruitmentInformationDb.create_time)).all()

        # 打印查询结果
        for record in recent_records:
            print(f"ID: {record.id}, Title: {record.title}, Create Time: {record.create_time}")

        return recent_records
    except SQLAlchemyError as e:
        print(f"查询失败: {e}")
        return []
    finally:
        # 关闭会话
        session.close()
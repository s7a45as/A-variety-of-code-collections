from datetime import datetime

from sqlalchemy import Column, Integer, String, DateTime
from sqlalchemy.ext.declarative import declarative_base

# 定义基类
RecruitmentBase = declarative_base()

# 定义数据表模型
class RecruitmentInformationDb(RecruitmentBase):
    __tablename__ = "recruitment_information"  # 表名
    id = Column(Integer, primary_key=True, autoincrement=True)
    title = Column(String(255), nullable=False)
    is_hot = Column(Integer, default=0)
    click = Column(Integer, default=0)
    create_time = Column(DateTime, default=datetime.now)
    link_url = Column(String(255), nullable=False)
    cover_img = Column(String(255), default="")
    link_type = Column(Integer, default=1)

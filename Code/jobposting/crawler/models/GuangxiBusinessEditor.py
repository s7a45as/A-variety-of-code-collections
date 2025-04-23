import sqlalchemy
from sqlalchemy import create_engine, Column, Integer, String, Text
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class News(Base):
    __tablename__ = 'GuangxiBusinessEditor'
    id = Column(Integer, primary_key=True, autoincrement=True)
    state = Column(String(50), nullable=False)  # 状态
    title = Column(String(255), nullable=False, unique=True)  # 标题（唯一）
    link = Column(String(255), nullable=False)  # 链接
    date = Column(String(50), nullable=False)  # 日期
    views = Column(String(50), nullable=False)  # 阅读量

    # 添加唯一约束
    __table_args__ = (sqlalchemy.UniqueConstraint('title', name='uq_news_title'),)
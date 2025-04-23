import sqlalchemy
from sqlalchemy import create_engine, Column, Integer, String, Text
from sqlalchemy.ext.declarative import declarative_base

Register_upcoming_exams = declarative_base()

class Register_upcoming_examsDb(Register_upcoming_exams):
    __tablename__ = ' Register_upcoming_exams'
    id = Column(Integer, primary_key=True, autoincrement=True)
    title = Column(String(255), nullable=False, unique=True)  # 标题（唯一）
    link = Column(String(255), nullable=False)  # 链接
    publish_time=Column(String(255),nullable=False)# 发布时间

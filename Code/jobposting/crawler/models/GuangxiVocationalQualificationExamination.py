import sqlalchemy
from sqlalchemy import create_engine, Column, Integer, String, Text
from sqlalchemy.ext.declarative import declarative_base

GuangxiVocationalQualificationExaminationBase = declarative_base()

class GuangxiVocationalQualificationExamination(GuangxiVocationalQualificationExaminationBase):
    __tablename__ = ' GuangxiVocationalQualificationExamination'
    id = Column(Integer, primary_key=True, autoincrement=True)
    title = Column(String(255), nullable=False, unique=True)  # 标题（唯一）
    link = Column(String(255), nullable=False)  # 链接

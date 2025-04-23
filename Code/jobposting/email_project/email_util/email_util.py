import smtplib
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr
import logging
from email_project.config.settings import EMAIL_HOST, FROM_EMAIL, AUTH_CODE, FROM_USER

# 配置日志
logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")

class EmailUtil:
    def __init__(self):
        self.email_host = EMAIL_HOST
        self.from_email = FROM_EMAIL
        self.auth_code = AUTH_CODE
        self.from_user = FROM_USER
    def send_email(self, recipient_email, subject, html_content):
        """
        发送通用邮件
        """
        try:
            # 创建邮件内容
            msg = MIMEText(html_content, "html", "utf-8")
            msg["From"] = formataddr((Header(self.from_user, "utf-8").encode(), self.from_email))
            msg["To"] = recipient_email
            msg["Subject"] = Header(subject, "utf-8")
            logging.info(f"msg具体内容:{msg["From"]}")
            # 连接邮件服务器并发送邮件
            with smtplib.SMTP_SSL(self.email_host, 465) as server:
                server.login(self.from_email, self.auth_code)
                server.sendmail(self.from_email, [recipient_email], msg.as_string())
                logging.info(f"邮件发送成功: {recipient_email}")
        except Exception as e:
            logging.error(f"邮件发送失败: {recipient_email}", exc_info=True)
            raise e
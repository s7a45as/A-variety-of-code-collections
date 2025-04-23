import crawler.db.guangxi_business_editor_DB
import email_project.email_util.email_util
from crawler.db.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformationDB import \
    query_recent_15_days_data

from email_project.email_util.html_generate import generate_html_content, generate_html_content_RecruitmentInformationDb


def Send_email_main(recipient_email="457325090@qq.com"):
    """
    发送招聘信息邮件
    """
    # 从数据库获取数据
    data = crawler.db.guangxi_business_editor_DB.fetch_data_from_db()

    # 生成 HTML 内容
    html_content = generate_html_content(data)

    # 发送邮件
    email_util = email_project.email_util.email_util.EmailUtil()
    email_util.send_email(
        recipient_email=recipient_email,
        subject="广西招聘信息更新",
        html_content=html_content
    )

    html_content=generate_html_content_RecruitmentInformationDb(query_recent_15_days_data())
    # print(html_content)
    email_util.send_email(
        recipient_email=recipient_email,
        subject="央国企更新",
        html_content=html_content
    )

if __name__ == "__main__":
    Send_email_main()
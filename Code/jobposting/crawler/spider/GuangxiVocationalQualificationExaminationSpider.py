import requests
from bs4 import BeautifulSoup

import crawler.db.GuangxiVocationalQualificationExaminationDB
from ..db.guangxi_business_editor_DB import save_to_db_guangxi_business_editor_upsert
from ..utils.utils import get_headers, get_cookies, get_proxies

def guangxi_GuangxiVocationalQualificationExamination_spider(base_url):
    """
    爬取职业资格类考试信息
    :param base_url: 基础URL
    :return: 返回解析后的BeautifulSoup对象
    """
    try:
        response = requests.get(
            base_url,
            headers=get_headers(),
            cookies=get_cookies(),
            verify=False,
            timeout=10  # 设置超时时间
        )
        response.encoding = 'utf-8'  # 设置编码为 UTF-8
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')

        # 找到包含考试信息的div
        rightitem_div = soup.find('div', class_='rightitem')

        if rightitem_div:
            # 找到ul标签
            ul_list = rightitem_div.find('ul', class_='channelright')

            if ul_list:
                # 找到所有的li标签
                li_list = ul_list.find_all('li')

                for li in li_list:
                    # 提取a标签中的标题和链接
                    a_tag = li.find('a')
                    title = a_tag['title'].strip()
                    link = a_tag['href']

                    # 如果链接以 ./ 开头，去掉 ./
                    if link.startswith('./'):
                        link = link[2:]  # 去掉前两个字符（./）

                    # 如果链接不是完整的URL，拼接基础URL
                    if not link.startswith('http'):
                        link = base_url + link
                    # 将数据保存到数据库
                    crawler.db.GuangxiVocationalQualificationExaminationDB.save_to_db_GuangxiVocationalQualificationExamination_upsert(title, link)

        return soup

    except requests.exceptions.RequestException as e:
        print(f"请求失败: {e}")
        return None

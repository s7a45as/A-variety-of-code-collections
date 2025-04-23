import requests
from bs4 import BeautifulSoup

import crawler.db.Register_upcoming_examsDB
from ..utils.utils import get_headers, get_cookies, get_proxies

def guangxi_Register_upcoming_exams_spider(base_url,top_base_url):
    """

    近期考试报名
    :param top_base_url:
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
            ul_list = rightitem_div.find('ul', class_='articles')

            if ul_list:
                # 找到所有的li标签
                li_list = ul_list.find_all('li')
                print(li_list.__len__())
                for li in li_list:
                    # 提取a标签中的标题和链接
                    a_tag = li.find('a')
                    title = a_tag['title'].strip()
                    link = a_tag['href']

                    if link.startswith('../'):
                        link = link.replace('../', '')  # 去掉 '../'，替换为空字符串

                # 如果链接不是完整的URL，拼接基础URL
                    if not link.startswith('http'):
                        link = top_base_url + link

                    # 提取日期信息
                    date_span = li.find('span')
                    date = date_span.text.strip() if date_span else '未知日期'

                    # 将数据保存到数据库
                    crawler.db.Register_upcoming_examsDB.save_to_db_Register_upcoming_examsDb_upsert(title,link,date)

        return soup

    except requests.exceptions.RequestException as e:
        print(f"请求失败: {e}")
        return None
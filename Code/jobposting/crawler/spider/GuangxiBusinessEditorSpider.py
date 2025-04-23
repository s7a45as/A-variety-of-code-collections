import requests
from bs4 import BeautifulSoup
from ..db.guangxi_business_editor_DB import save_to_db_guangxi_business_editor_upsert
from ..utils.utils import get_headers, get_cookies, get_proxies


def guangxi_business_editor_spider(url):
    """
    事业编
    :param url: 要爬取的URL
    :return: 返回解析后的BeautifulSoup对象
    """
    try:
        response = requests.get(
            url,
            headers=get_headers(),
            cookies=get_cookies(),
            timeout=10  # 设置超时时间
        )
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        newslist_div = soup.find('div', id='Newslist')

        if newslist_div:
            ul_list = newslist_div.find_all('ul')
            for ul in ul_list:
                li_list = ul.find_all('li')
                for li in li_list:
                    state = li.find('span', class_='state').text.strip()
                    title_tag = li.find('a')
                    title = title_tag.text.strip()
                    link = title_tag['href']
                    if not link.startswith('http'):
                        link = "https://sydw.gxrc.com" + link
                    date_tag = li.find('div', class_='date')
                    date = date_tag.find('span').text.strip()
                    views = date_tag.text.split(']')[0].split('[')[-1].strip()

                    # 将数据保存到数据库
                    save_to_db_guangxi_business_editor_upsert(state, title, link, date, views)

        return soup

    except requests.exceptions.RequestException as e:
        print(f"请求失败: {e}")
        return None
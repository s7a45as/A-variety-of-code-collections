import time

from crawler.spider.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformationSpider import clean_data, \
    fetch_data, save_to_db


def RecruitmentInformationMain():

    base_url = "https://api4.iguopin.com/api/notice/list"
    per_page = 10
    for page in range(1,6):
        raw_data = fetch_data(page, per_page, base_url)
        time.sleep(5)

        if raw_data:
            cleaned_data = clean_data(raw_data)  # 先赋值
            save_to_db(cleaned_data)
        else:
            print("No data fetched.")


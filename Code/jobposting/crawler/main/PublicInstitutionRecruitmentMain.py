import time

import crawler.spider.PublicInstitutionRecruitmentSpider


def Public_Institution_Recruitment_Main():
    """
    主函数，用于爬取事业单位招聘考试信息
    """
    base_url = "https://www.gxpta.com.cn/ksxm/sydwzpks/"  # 基础URL
    for page in range(1, 10):  # 爬取前5页
        if page == 1:
            url = f"{base_url}index.html"  # 第一页的URL
        else:
            url = f"{base_url}index_{page-1}.html"  # 第二页及以后的URL

        print(f"正在爬取第 {page} 页: {url}")
        crawler.spider.PublicInstitutionRecruitmentSpider.guangxi_InstitutionRecruitmentExamination_spider(url,base_url)  # 调用爬虫函数
        print(f"第 {page} 页爬取完成！")
        time.sleep(5)  # 防止请求过于频繁，添加延迟
    print("所有页面爬取完成，数据已保存到数据库中。")


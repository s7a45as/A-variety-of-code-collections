import time

import crawler.models.Register_upcoming_exams
import crawler.spider.Register_upcoming_examsSpider


def Register_upcoming_exams_Main():
    """
    主函数，用于爬取事业单位招聘考试信息
    """
    top_base_url="https://www.gxpta.com.cn/"
    base_url = "https://www.gxpta.com.cn/sy/jqksbm/"  # 基础URL
    try:

        for page in range(1, 4):  # 爬取前10页
            if page == 1:
                url = f"{base_url}index.html"  # 第一页的URL
            else:
                url = f"{base_url}index_{page-1}.html"  # 第二页及以后的URL

            print(f"正在爬取第 {page} 页: {url}")
            crawler.spider.Register_upcoming_examsSpider.guangxi_Register_upcoming_exams_spider(url,top_base_url)
            print(f"第 {page} 页爬取完成！")
            time.sleep(5)  # 防止请求过于频繁，添加延迟
        print("所有页面爬取完成，数据已保存到数据库中。")
    except Exception as e:
        print(e);


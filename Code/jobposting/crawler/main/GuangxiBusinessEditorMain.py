import time
from crawler.spider.GuangxiBusinessEditorSpider import guangxi_business_editor_spider

def GuangxiBusinessEditorMain():
    base_url = "https://sydw.gxrc.com/"
    for page in range(1, 10):
        print(f"正在爬取第 {page} 页...")
        url = f"{base_url}?articleType=0&pageindex={page}"
        guangxi_business_editor_spider(url)
        print(f"第 {page} 页爬取完成！")
        time.sleep(5)
    print("所有页面爬取完成，数据已保存到数据库中。")


import time

import crawler.spider.GuangxiVocationalQualificationExaminationSpider
from crawler.spider.GuangxiBusinessEditorSpider import guangxi_business_editor_spider

def GuangxiVocationalQualificationExaminationMain():

    List_url=["https://www.gxpta.com.cn/ksxm/gwyzlks/","https://www.gxpta.com.cn/ksxm/gwylxks/","https://www.gxpta.com.cn/ksxm/zyzglks/"]
    for base_url in List_url:
        crawler.spider.GuangxiVocationalQualificationExaminationSpider.guangxi_GuangxiVocationalQualificationExamination_spider(base_url)
        time.sleep(5)


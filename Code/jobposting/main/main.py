
import time
import schedule

from crawler.main.CentralStateOwnedEnterprises.RecruitmentInformation import RecruitmentInformationMain
from crawler.main.GuangxiBusinessEditorMain import GuangxiBusinessEditorMain
from crawler.main.GuangxiVocationalQualificationExaminationMain import GuangxiVocationalQualificationExaminationMain
from crawler.main.PublicInstitutionRecruitmentMain import Public_Institution_Recruitment_Main
from crawler.main.Register_upcoming_examsMain import Register_upcoming_exams_Main


# 定义定时任务
def Spider_job():
    print("开始执行爬虫任务...")
    try:
        GuangxiBusinessEditorMain()
        RecruitmentInformationMain()
        GuangxiVocationalQualificationExaminationMain()
        Public_Institution_Recruitment_Main()
        Register_upcoming_exams_Main()
    except Exception as e:
        print(f"爬虫任务执行出错: {e}")
    print("爬虫任务执行完毕。")

def job():
    global counter
    counter += 1
    if counter % 3 == 0:  # 每3天执行一次
        Spider_job()





def main():
    print("定时任务调度程序启动...")

    # 安排任务每天执行
    schedule.every().day.at("10:00").do(job)

    # 保持脚本运行，以便定时任务可以执行
    while True:
        schedule.run_pending()
        time.sleep(1)

if __name__ == "__main__":
    main()
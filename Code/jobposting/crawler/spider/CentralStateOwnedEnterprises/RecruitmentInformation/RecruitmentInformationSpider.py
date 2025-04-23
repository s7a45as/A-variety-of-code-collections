from datetime import datetime

import requests
from typing import List, Dict

import crawler.models.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformation
from crawler.db.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformationDB import save_to_db_RecruitmentInformationDb_upsert
from crawler.models.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformation import RecruitmentInformationDb
import crawler.db.CentralStateOwnedEnterprises.RecruitmentInformation.RecruitmentInformationDB


def fetch_data(page: int, per_page: int, base_url: str) -> Dict:
    """获取单页数据"""
    params = {
        "page": page,
        "per_page": per_page,
        "type": "sasac",
        "keyword": ""
    }
    response = requests.get(base_url, params=params)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"Failed to fetch data for page {page}. Status code: {response.status_code}")
        return None

def clean_data(raw_data: Dict) -> List[Dict]:
    """清理数据，提取所需字段"""
    cleaned_data = []
    for item in raw_data["data"]["data"]:
        cleaned_item = {
            "id": item.get("id", ""),
            "title": item.get("title", "").strip(),
            "is_hot": item.get("is_hot", 0),
            "click": item.get("click", 0),
            "create_time": item.get("create_time", ""),
            "link_url": item.get("link_url", ""),
            "cover_img": item.get("cover_img", ""),
            "link_type": item.get("link_type", 1)
        }
        cleaned_data.append(cleaned_item)
    return cleaned_data

def save_to_db(cleaned_data:Dict):

    for item in cleaned_data:
        create_time = datetime.strptime(item["create_time"], "%Y-%m-%d %H:%M:%S")

        # 构造 RecruitmentInformationDb 对象
        recruitment_info = RecruitmentInformationDb(
            id=item["id"],
            title=item["title"],
            is_hot=item["is_hot"],
            click=item["click"],
            create_time=create_time,
            link_url=item["link_url"],
            cover_img=item["cover_img"],
            link_type=item["link_type"]
        )

        # 插入或更新记录
        save_to_db_RecruitmentInformationDb_upsert(recruitment_info)


import random


def get_headers():
    """
    返回请求头
    """
    return {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36",
        "Accept": "application/json, text/javascript, */*; q=0.01",
        "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8",
        "Connection": "keep-alive",
        "Referer": "https://sydw.gxrc.com/",
    }
def get_proxies():
    """
    返回随机选择的 HTTP 代理 IP
    """
    # 手动添加多个 HTTP 代理 IP
    proxy_list = [

    ]

    # 随机选择一个代理 IP
    proxy = random.choice(proxy_list)
    return {
        "http": proxy,
        "https": proxy,  # 如果需要 HTTPS 代理，可以单独配置
    }
def get_cookies():
    """
    返回 Cookie
    """
    return {
        "Hm_lvt_74c6566899b775d31c6f6cd5022ef551": "1737339724",
        "searchLog": "",
        "Hm_lvt_8b5e38a6a547f78d5f305bf6658222cd": "1736496336,1737339421,1737368946,1737428781",
        "HMACCOUNT": "F51615F9808DC69E",
        "Hm_lvt_cf8b8a32d5babca87cdf6620fa88c676": "1737339431,1737369147,1737428782",
        "Hm_lpvt_8b5e38a6a547f78d5f305bf6658222cd": "1737429326",
        "Hm_lpvt_cf8b8a32d5babca87cdf6620fa88c676": "1737429411"
    }
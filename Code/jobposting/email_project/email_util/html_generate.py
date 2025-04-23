def generate_html_content(data):
    # '广西事业单位招聘频道-2025广西最新事业单位招聘-广西人才网-sydw.gxrc.com'
    """
    将数据库中的数据生成 HTML 内容
    """
    html_content = """
    <html>
    <head>
        <style>
            body { font-family: Arial, sans-serif; }
            h2 { color: #1a73e8; }
            table { width: 100%; border-collapse: collapse; margin-top: 20px; }
            th, td { padding: 12px; text-align: left; border-bottom: 1px solid #ddd; }
            th { background-color: #f8f9fa; }
            tr:hover { background-color: #f1f1f1; }
        </style>
    </head>
    <body>
        <h2>信息</h2>
        <table>
            <tr>
                <th>状态</th>
                <th>标题</th>
                <th>链接</th>
                <th>日期</th>
                <th>阅读量</th>
            </tr>
    """

    for item in data:
        html_content += f"""
            <tr>
                <td>{item.state}</td>
                <td>{item.title}</td>
                <td><a href="{item.link}">查看详情</a></td>
                <td>{item.date}</td>
                <td>{item.views}</td>
            </tr>
        """

    html_content += """
        </table>
    </body>
    </html>
    """
    return html_content


def generate_html_content_RecruitmentInformationDb(data):
    """
    将数据库中的数据生成 HTML 内容
    :param data: 查询到的数据列表（RecruitmentInformationDb 对象列表）
    :return: 生成的 HTML 内容
    """
    html_content = """
    <html>
    <head>
        <style>
            body { font-family: Arial, sans-serif; }
            h2 { color: #1a73e8; }
            table { width: 100%; border-collapse: collapse; margin-top: 20px; }
            th, td { padding: 12px; text-align: left; border-bottom: 1px solid #ddd; }
            th { background-color: #f8f9fa; }
            tr:hover { background-color: #f1f1f1; }
        </style>
    </head>
    <body>
        <h2>广西事业单位招聘信息</h2>
        <table>
            <tr>
                <th>标题</th>
                <th>是否热门</th>
                <th>点击量</th>
                <th>发布日期</th>
                <th>链接</th>
            </tr>
    """

    for item in data:
        # 将数据库中的数据填充到 HTML 表格中
        html_content += f"""
            <tr>
                <td>{item.title}</td>
                <td>{'是' if item.is_hot else '否'}</td>
                <td>{item.click}</td>
                <td>{item.create_time.strftime('%Y-%m-%d %H:%M:%S')}</td>
                <td><a href="{item.link_url}">查看详情</a></td>
            </tr>
        """

    html_content += """
        </table>
    </body>
    </html>
    """
    return html_content
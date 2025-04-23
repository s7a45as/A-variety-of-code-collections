<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>电动车库存管理系统</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 40px;
        }
        h1 {
            color: #333;
            text-align: center;
        }
        .menu {
            width: 300px;
            margin: 0 auto;
            padding: 20px;
        }
        .menu a {
            display: block;
            margin: 10px 0;
            padding: 10px;
            text-align: center;
            background-color: #4CAF50;
            color: white;
            text-decoration: none;
            border-radius: 5px;
        }
        .menu a:hover {
            background-color: #45a049;
        }
    </style>
</head>
<body>
    <h1>库存管理主页</h1>
    <div class="menu">
        <a href="query.jsp">按生产日期查询电动车</a>
        <a href="add.jsp">添加一个电动车</a>
    </div>
</body>
</html> 
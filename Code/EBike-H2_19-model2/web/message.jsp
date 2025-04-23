<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>操作结果</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 40px;
            text-align: center;
        }
        .message {
            margin: 20px;
            padding: 20px;
            border-radius: 5px;
        }
        .success {
            background-color: #dff0d8;
            color: #3c763d;
            border: 1px solid #d6e9c6;
        }
        .error {
            background-color: #f2dede;
            color: #a94442;
            border: 1px solid #ebccd1;
        }
        .back-link {
            margin-top: 20px;
            display: inline-block;
            padding: 10px 15px;
            background-color: #4CAF50;
            color: white;
            text-decoration: none;
            border-radius: 4px;
        }
    </style>
</head>
<body>
    <%
        Boolean success = (Boolean)request.getAttribute("success");
        String message = (String)request.getAttribute("message");
    %>
    <div class="message <%= success ? "success" : "error" %>">
        <h2><%=message%></h2>
    </div>
    
    <script>
        // 3秒后自动返回主页
        setTimeout(function() {
            window.location.href = "index.jsp";
        }, 3000);
    </script>
    
    <a href="index.jsp" class="back-link">立即返回主页</a>
</body>
</html> 
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>添加电动车</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 40px;
        }
        .form-container {
            width: 400px;
            margin: 0 auto;
            padding: 20px;
        }
        .form-group {
            margin-bottom: 15px;
        }
        label {
            display: block;
            margin-bottom: 5px;
        }
        input {
            width: 100%;
            padding: 8px;
            border: 1px solid #ddd;
            border-radius: 4px;
            box-sizing: border-box;
        }
        button {
            background-color: #4CAF50;
            color: white;
            padding: 10px 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }
        button:hover {
            background-color: #45a049;
        }
    </style>
</head>
<body>
    <div class="form-container">
        <h2>输入电动车信息</h2>
        <form action="doAdd.jsp" method="post">
            <div class="form-group">
                <label for="dingdanNo">仓库编号：</label>
                <input type="text" id="dingdanNo" name="dingdanNo" required>
            </div>
            <div class="form-group">
                <label for="ebikeNo">电动车编号：</label>
                <input type="text" id="ebikeNo" name="ebikeNo" required>
            </div>
            <div class="form-group">
                <label for="ebikeName">电动车名：</label>
                <input type="text" id="ebikeName" name="ebikeName" required>
            </div>
            <div class="form-group">
                <label for="unit">单位：</label>
                <input type="text" id="unit" name="unit" required>
            </div>
            <div class="form-group">
                <label for="price">价格：</label>
                <input type="number" step="0.01" id="price" name="price" required>
            </div>
            <div class="form-group">
                <label for="quantity">数量：</label>
                <input type="number" id="quantity" name="quantity" required>
            </div>
            <div class="form-group">
                <label for="productionDate">生产日期</label>
                <input type="date" id="productionDate" name="productionDate" required>
            </div>
            <button type="submit">添加</button>
        </form>
    </div>
</body>
</html> 
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="com.java.service.impl.EBikeServiceImpl"%>
<%@ page import="com.java.service.EBikeService"%>
<%@ page import="com.java.pojo.EBike_H2_19"%>
<%@ page import="com.java.utils.DateTypeConvert_H2_19"%>
<%@ page import="java.util.List"%>
<%@ page import="java.util.Date"%>
<%@ page import="javax.servlet.http.HttpServletRequest" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>查询结果</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #4CAF50;
            color: white;
        }
        tr:nth-child(even) {
            background-color: #f2f2f2;
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
        String dateStr = request.getParameter("productionDate");
        System.out.println("Received date parameter: " + dateStr);
        
        Date date = DateTypeConvert_H2_19.stringToDate(dateStr);
        System.out.println("Converted Date object: " + date);
        
        EBikeService service = new EBikeServiceImpl();
        List<EBike_H2_19> list = service.queryByDate(date);
        System.out.println("Query result count: " + list.size());
    %>
    
    <h2>查询结果 - 生产日期：<%=dateStr%></h2>
    
    <table>
        <tr>
            <th>仓库编号</th>
            <th>电动车编号</th>
            <th>电动车名</th>
            <th>单位</th>
            <th>价格</th>
            <th>数量</th>
            <th>生产日期</th>
        </tr>
        <% for(EBike_H2_19 ebike : list) { %>
        <tr>
            <td><%=ebike.getDingdanNo()%></td>
            <td><%=ebike.getEbikeNo()%></td>
            <td><%=ebike.getEbikeName()%></td>
            <td><%=ebike.getUnit()%></td>
            <td><%=ebike.getPrice()%></td>
            <td><%=ebike.getQuantity()%></td>
            <td><%=DateTypeConvert_H2_19.dateToString(ebike.getProductionDate())%></td>
        </tr>
        <% } %>
    </table>
    
    <a href="index.jsp" class="back-link">返回主页</a>
</body>
</html> 
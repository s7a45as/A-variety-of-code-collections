<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="com.java.service.impl.EBikeServiceImpl"%>
<%@ page import="com.java.service.EBikeService"%>
<%@ page import="com.java.pojo.EBike_H2_19"%>
<%@ page import="com.java.utils.DateTypeConvert_H2_19"%>
<%
    request.setCharacterEncoding("UTF-8");
    
    // 获取表单数据
    EBike_H2_19 ebike = new EBike_H2_19();
    ebike.setDingdanNo(request.getParameter("dingdanNo"));
    ebike.setEbikeNo(request.getParameter("ebikeNo"));
    ebike.setEbikeName(request.getParameter("ebikeName"));
    ebike.setUnit(request.getParameter("unit"));
    ebike.setPrice(request.getParameter("price"));
    ebike.setQuantity(request.getParameter("quantity"));
    ebike.setProductionDate(DateTypeConvert_H2_19.stringToDate(request.getParameter("productionDate")));
    
    EBikeService service = new EBikeServiceImpl();
    boolean success = false;
    String message = "";
    
    try {
        success = service.addEBike(ebike);
        message = success ? "添加成功！" : "添加失败！";
    } catch (Exception e) {
        success = false;
        message = "添加失败：" + e.getMessage();
    }
    
    // 将结果存储在request中
    request.setAttribute("success", success);
    request.setAttribute("message", message);
    
    // 转发到消息页面
    request.getRequestDispatcher("message.jsp").forward(request, response);
%> 
package com.java.dao.impl;

import com.java.dao.EBikeDAO;
import com.java.dbc.MySQLConnection;
import com.java.pojo.EBike_H2_19;
import com.java.utils.DateTypeConvert_H2_19;

import java.sql.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.text.SimpleDateFormat;

public class EBikeDAOImpl implements EBikeDAO {
    
    // 设置SQL参数的通用方法
    private void setParams_H2_19(PreparedStatement pstmt, String[] params) throws SQLException {
        if (params != null) {
            for (int i = 0; i < params.length; i++) {
                // 如果是日期类型参数
                if (i == 6) { // 假设第7个参数是日期
                    Date date = DateTypeConvert_H2_19.stringToDate(params[i]);
                    if (date != null) {
                        pstmt.setDate(i + 1, new java.sql.Date(date.getTime()));
                    } else {
                        pstmt.setNull(i + 1, Types.DATE);
                    }
                } else {
                    pstmt.setString(i + 1, params[i]);
                }
            }
        }
    }

    @Override
    public List<EBike_H2_19> findByProductionDate(Date date) throws Exception {
        if (date == null) {
            throw new IllegalArgumentException("Date parameter cannot be null");
        }
        
        // 使用TimeZone.getDefault()获取当前时区
        Calendar cal = Calendar.getInstance();
        cal.setTime(date);
        // 重置时间部分为当天开始
        cal.set(Calendar.HOUR_OF_DAY, 12); // 设置为中午12点，避免时区问题
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);
        cal.set(Calendar.MILLISECOND, 0);
        date = cal.getTime();
        
        System.out.println("Method execution started");
        List<EBike_H2_19> list = new ArrayList<>();
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        
        try {
            conn = MySQLConnection.getConnection();
            // 修改SQL语句，使用特定的日期格式
            String sql = "SELECT * FROM dingdan_H2_19 WHERE DATE(production_date) = DATE(STR_TO_DATE(?, '%Y-%m-%d'))";
            
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
            String formattedDate = sdf.format(date);
            
            System.out.println("Executing SQL with formatted date: " + formattedDate);
            
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, formattedDate);
            
            System.out.println("Complete SQL statement: " + pstmt.toString());
            
            rs = pstmt.executeQuery();
            
            while (rs.next()) {
                EBike_H2_19 ebike = new EBike_H2_19();
                ebike.setDingdanNo(rs.getString("dingdanNo_H2_19"));
                ebike.setEbikeNo(rs.getString("EBike_No_H2_19"));
                ebike.setEbikeName(rs.getString("ebike_name"));
                ebike.setUnit(rs.getString("unit"));
                ebike.setPrice(String.valueOf(rs.getFloat("price")));
                ebike.setQuantity(String.valueOf(rs.getInt("quantity")));
                ebike.setProductionDate(rs.getDate("production_date"));
                list.add(ebike);
                
                // Debug info: print each record
                System.out.println("Record found: " + 
                    "Warehouse No=" + ebike.getDingdanNo() + 
                    ", EBike No=" + ebike.getEbikeNo() + 
                    ", Production Date=" + ebike.getProductionDate());
            }
            System.out.println("Total records found: " + list.size());
        } catch (Exception e) {
            System.err.println("Query error: " + e.getMessage());
            e.printStackTrace();
            throw e;
        } finally {
            if (rs != null) rs.close();
            if (pstmt != null) pstmt.close();
            MySQLConnection.closeConnection(conn);
        }
        return list;
    }

    @Override
    public boolean addEBike(EBike_H2_19 ebike) throws Exception {
        Connection conn = null;
        PreparedStatement pstmt = null;
        
        try {
            conn = MySQLConnection.getConnection();
            String sql = "INSERT INTO dingdan_H2_19 VALUES (?, ?, ?, ?, ?, ?, ?)";
            pstmt = conn.prepareStatement(sql);
            
            String[] params = {
                ebike.getDingdanNo(),
                ebike.getEbikeNo(),
                ebike.getEbikeName(),
                ebike.getUnit(),
                ebike.getPrice(),
                ebike.getQuantity(),
                DateTypeConvert_H2_19.dateToString(ebike.getProductionDate())
            };
            
            setParams_H2_19(pstmt, params);
            return pstmt.executeUpdate() > 0;
        } finally {
            if (pstmt != null) pstmt.close();
            MySQLConnection.closeConnection(conn);
        }
    }
} 
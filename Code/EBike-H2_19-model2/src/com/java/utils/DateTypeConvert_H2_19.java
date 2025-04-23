package com.java.utils;

import java.text.SimpleDateFormat;
import java.util.Date;

public class DateTypeConvert_H2_19 {
    private static final SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
    
    public static String dateToString(Date date) {
        return date != null ? sdf.format(date) : "";
    }
    
    public static Date stringToDate(String dateStr) {
        System.out.println("Starting date string conversion: " + dateStr);
        try {
            if (dateStr == null || dateStr.trim().isEmpty()) {
                return null;
            }
            
            // Standardize date format
            String[] parts = dateStr.split("-");
            if (parts.length == 3) {
                String year = parts[0];
                String month = parts[1].length() == 1 ? "0" + parts[1] : parts[1];
                String day = parts[2].length() == 1 ? "0" + parts[2] : parts[2];
                String standardDate = String.format("%s-%s-%s", year, month, day);
                System.out.println("Standardized date string: " + standardDate);
                
                return sdf.parse(standardDate);
            }
            return null;
        } catch (Exception e) {
            System.err.println("Date conversion failed: " + e.getMessage());
            e.printStackTrace();
            return null;
        }
    }
} 
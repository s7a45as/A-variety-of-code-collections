package com.java.service;


import com.java.pojo.EBike_H2_19;
import java.util.List;
import java.util.Date;

public interface EBikeService {
    List<EBike_H2_19> queryByDate(Date date) throws Exception;
    boolean addEBike(EBike_H2_19 ebike) throws Exception;
} 
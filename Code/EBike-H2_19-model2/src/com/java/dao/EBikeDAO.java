package com.java.dao;

import com.java.pojo.EBike_H2_19;
import java.util.List;
import java.util.Date;

public interface EBikeDAO {
    List<EBike_H2_19> findByProductionDate(Date date) throws Exception;
    boolean addEBike(EBike_H2_19 ebike) throws Exception;
} 
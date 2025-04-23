package com.java.service.impl;


import com.java.dao.EBikeDAO;
import com.java.dao.impl.EBikeDAOImpl;
import com.java.pojo.EBike_H2_19;
import com.java.service.EBikeService;

import java.util.Date;
import java.util.List;

public class EBikeServiceImpl implements EBikeService {
    private final EBikeDAO ebikeDAO = new EBikeDAOImpl();
    
    @Override
    public List<EBike_H2_19> queryByDate(Date date) throws Exception {
        return ebikeDAO.findByProductionDate(date);
    }
    
    @Override
    public boolean addEBike(EBike_H2_19 ebike) throws Exception {
        return ebikeDAO.addEBike(ebike);
    }
} 
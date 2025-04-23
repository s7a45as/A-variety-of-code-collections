package com.java.pojo;

import java.util.Date;

public class EBike_H2_19 {
    private String dingdanNo;    // 仓库编号
    private String ebikeNo;      // 电动车编号
    private String ebikeName;    // 电动车名
    private String unit;         // 单位
    private String price;        // 价格
    private String quantity;     // 数量
    private Date productionDate; // 生产日期


    public String getDingdanNo() {
        return dingdanNo;
    }

    public void setDingdanNo(String dingdanNo) {
        this.dingdanNo = dingdanNo;
    }

    public String getEbikeNo() {
        return ebikeNo;
    }

    public void setEbikeNo(String ebikeNo) {
        this.ebikeNo = ebikeNo;
    }

    public String getEbikeName() {
        return ebikeName;
    }

    public void setEbikeName(String ebikeName) {
        this.ebikeName = ebikeName;
    }

    public String getUnit() {
        return unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public String getPrice() {
        return price;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    public String getQuantity() {
        return quantity;
    }

    public void setQuantity(String quantity) {
        this.quantity = quantity;
    }

    public Date getProductionDate() {
        return productionDate;
    }

    public void setProductionDate(Date productionDate) {
        this.productionDate = productionDate;
    }
} 
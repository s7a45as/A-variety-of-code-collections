package com.pls.PLM.domain.entity;


import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.extension.activerecord.Model;
import lombok.Data;
import com.baomidou.mybatisplus.annotation.TableId;

import java.io.Serializable;

/**
 * (Yuketang)表实体类
 *
 * @author makejava
 * @since 2025-01-04 23:05:07
 */
@SuppressWarnings("serial")
@Data
@TableName("yuketang")
public class Yuketang extends Model<Yuketang> {

    @TableId(value = "_id")
    private Integer id;

    private String param2Text;

    private String param3Text;

    private String question;

    private String param5Text;

    private String param6Text;

    private String param7Text;

    private String param8Text;

    private String param9Text;

    private String param10Text;

    private String param11Text;

    private String param12Text;

    private String param13Text;

    private String param14Text;

    private String param15Text;

    private String param16Text;

    private String param17Text;

    private String param18Text;

    private String param19Text;

    private String param20Text;

    private String param21Text;

    private String param22Text;

    private String param23Text;

    private String param24Text;

    private String answer;

    private String param26Text;


    /**
     * 获取主键值
     *
     * @return 主键值
     */
    @Override
    public Serializable pkVal() {
        return this.id;
    }
}


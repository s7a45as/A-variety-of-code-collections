package com.wu.idomwx.generator.domain;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * 
 * @TableName cy
 */
@TableName(value ="cy")
@Data
public class Cy {
    /**
     * 
     */
    @TableField(value = "ID")
    private Double id;

    /**
     * 
     */
    @TableField(value = "name")
    private String name;

    /**
     * 
     */
    @TableField(value = "spell")
    private String spell;

    /**
     * 
     */
    @TableField(value = "content")
    private String content;

    /**
     * 
     */
    @TableField(value = "derivation")
    private String derivation;

    /**
     * 
     */
    @TableField(value = "samples")
    private String samples;
}
package com.pls.PLM.domain.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 简答题表
 * </p>
 *
 * @author 摸鱼
 * @since 2025-01-05
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@TableName("short_answer")

public class ShortAnswer implements Serializable {

    private static final long serialVersionUID = 1L;


    @TableId(value = "id", type = IdType.AUTO)
    private Long id;


    @TableField("question")
    private String question;


    @TableField("answer")
    private String answer;


    @TableField("analysis")
    private String analysis;


    @TableField("difficulty")
    private Integer difficulty;


    @TableField("category")
    private String category;


    @TableField("keywords")
    private String keywords;


    @TableField("score")
    private Integer score;


    @TableField("create_time")
    private LocalDateTime createTime;


    @TableField("update_time")
    private LocalDateTime updateTime;


    @TableField("is_deleted")
    private Boolean isDeleted;


}

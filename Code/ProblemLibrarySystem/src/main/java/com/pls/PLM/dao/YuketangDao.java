package com.pls.PLM.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.pls.PLM.domain.entity.Yuketang;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * (Yuketang)表数据库访问层
 *
 * @author makejava
 * @since 2025-01-04 23:05:01
 */
@Mapper
public interface YuketangDao extends BaseMapper<Yuketang> {

    /**
     * 批量新增数据（MyBatis原生foreach方法）
     *
     * @param entities List<Yuketang> 实例对象列表
     * @return 影响行数
     */
    int insertBatch(@Param("entities") List<Yuketang> entities);

    /**
     * 批量新增或按主键更新数据（MyBatis原生foreach方法）
     *
     * @param entities List<Yuketang> 实例对象列表
     * @return 影响行数
     * @throws org.springframework.jdbc.BadSqlGrammarException 入参是空List的时候会抛SQL语句错误的异常，请自行校验入参
     */
    int insertOrUpdateBatch(@Param("entities") List<Yuketang> entities);

}


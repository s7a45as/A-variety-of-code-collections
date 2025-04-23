package com.pls.PLM.controller;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.pls.PLM.common.R;
import com.pls.PLM.domain.entity.ShortAnswer;
import com.pls.PLM.domain.entity.Yuketang;
import com.pls.PLM.service.IShortAnswerService;
import com.pls.PLM.service.YuketangService;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.Serializable;
import java.util.List;

/**
 * (Yuketang)表控制层
 *
 * @author makejava
 * @since 2025-01-04 23:05:00
 */
@RestController
@RequestMapping("questions")
public class YuketangController {
    /**
     * 服务对象
     */
    @Resource
    private YuketangService yuketangService;
    @Resource
    private IShortAnswerService shortAnswerService;
    /**
     * 分页查询所有数据
     *
     * @param current  当前页
     * @param size     每页显示条数
     * @param keyword  搜索关键字
     * @param type     题目类型（0：选择题，1：简答题）
     * @return 所有数据
     */
    @GetMapping
    public R selectAll(@RequestParam(defaultValue = "1") Long current,
                      @RequestParam(defaultValue = "10") Long size,
                      @RequestParam(required = false) String keyword,
                      @RequestParam(required = false, defaultValue = "0") Integer type) {
        if (type == 0) {
            // 查询选择题表
            Page<Yuketang> page = new Page<>(current, size);
            QueryWrapper<Yuketang> queryWrapper = new QueryWrapper<>();
            if (keyword != null && !keyword.trim().isEmpty()) {
                queryWrapper.like("question", keyword);
            }
            return R.ok().data("items", this.yuketangService.page(page, queryWrapper));
        } else if (type == 1) {
            // 查询简答题表
            Page<ShortAnswer> page = new Page<>(current, size);
            QueryWrapper<ShortAnswer> queryWrapper = new QueryWrapper<>();
            if (keyword != null && !keyword.trim().isEmpty()) {
                queryWrapper.like("question", keyword);
            }
            return R.ok().data("items", this.shortAnswerService.page(page, queryWrapper));
        } else {
            return R.error("不支持的题目类型");
        }
    }

    /**
     * 通过主键查询单条数据
     *
     * @param id 主键
     * @return 单条数据
     */
    @GetMapping("{id}")
    public R selectOne(@PathVariable Serializable id) {
        return R.ok().data("item", this.yuketangService.getById(id));
    }

    /**
     * 新增数据
     *
     * @param yuketang 实体对象
     * @return 新增结果
     */
    @PostMapping
    public R insert(@RequestBody Yuketang yuketang) {
        boolean save = this.yuketangService.save(yuketang);
        if (save) {
            return R.ok();
        } else {
            return R.error("添加失败");
        }
    }

    /**
     * 修改数据
     *
     * @param yuketang 实体对象
     * @return 修改结果
     */
    @PutMapping
    public R update(@RequestBody Yuketang yuketang) {
        boolean update = this.yuketangService.updateById(yuketang);
        if (update) {
            return R.ok();
        } else {
            return R.error("修改失败");
        }
    }

    /**
     * 删除数据
     *
     * @param idList 主键结合
     * @return 删除结果
     */
    @DeleteMapping
    public R delete(@RequestParam("idList") List<Long> idList) {
        boolean remove = this.yuketangService.removeByIds(idList);
        if (remove) {
            return R.ok();
        } else {
            return R.error("删除失败");
        }
    }

    /**
     * 获取随机题目
     *
     * @param type 题目类型（0：选择题，1：简答题）
     * @return 随机题目
     */
    @GetMapping("/random")
    public R getRandomQuestion(@RequestParam(required = false, defaultValue = "0") Integer type) {
        if (type == 0) {
            // 查询选择题表
            QueryWrapper<Yuketang> queryWrapper = new QueryWrapper<>();
            queryWrapper.last("ORDER BY RAND() LIMIT 1");  // MySQL的随机查询
            Yuketang question = this.yuketangService.getOne(queryWrapper);
            return R.ok().data("item", question);
        } else if (type == 1) {
            // 查询简答题表
            QueryWrapper<ShortAnswer> queryWrapper = new QueryWrapper<>();
            queryWrapper.last("ORDER BY RAND() LIMIT 1");
            ShortAnswer question = this.shortAnswerService.getOne(queryWrapper);
            return R.ok().data("item", question);
        } else {
            return R.error("不支持的题目类型");
        }
    }
}


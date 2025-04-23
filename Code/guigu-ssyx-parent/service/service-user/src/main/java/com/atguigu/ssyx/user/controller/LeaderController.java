package com.atguigu.ssyx.user.controller;



import com.atguigu.ssyx.common.result.Result;
import com.atguigu.ssyx.enums.user.Leader;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.api.ApiController;
import com.baomidou.mybatisplus.extension.api.R;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import com.atguigu.ssyx.user.service.LeaderService;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.Serializable;
import java.util.List;

/**
 * 团长表(Leader)表控制层
 *
 * @author makejava
 * @since 2025-01-20 12:12:53
 */
@RestController
@RequestMapping("/admin/user/leader")
public class LeaderController extends ApiController {
    /**
     * 服务对象
     */
    @Resource
    private LeaderService leaderService;

    /**
     * 分页查询团长已经审核所有数据
     *
     * @param page 分页对象
     * @param leader 查询实体
     * @return 所有数据
     */
    @GetMapping("checkList/{page}/{limit}")
    public Result selectAll(Page<Leader> page, Leader leader) {
        return Result.ok(this.leaderService.page(page, new LambdaQueryWrapper<Leader>().eq(Leader::getCheckStatus,1)));
    }

    /**
     * 通过主键查询单条数据
     *
     * @param id 主键
     * @return 单条数据
     */
    @GetMapping("{id}")
    public R selectOne(@PathVariable Serializable id) {
        return success(this.leaderService.getById(id));
    }

    /**
     * 新增数据
     *
     * @param leader 实体对象
     * @return 新增结果
     */
    @PostMapping
    public R insert(@RequestBody Leader leader) {
        return success(this.leaderService.save(leader));
    }

    /**
     * 修改数据
     *
     * @param leader 实体对象
     * @return 修改结果
     */
    @PutMapping
    public R update(@RequestBody Leader leader) {
        return success(this.leaderService.updateById(leader));
    }

    /**
     * 删除数据
     *
     * @param idList 主键结合
     * @return 删除结果
     */
    @DeleteMapping
    public R delete(@RequestParam("idList") List<Long> idList) {
        return success(this.leaderService.removeByIds(idList));
    }
}


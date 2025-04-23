package com.atguigu.ssyx.user.service.impl;

import com.atguigu.ssyx.enums.user.Leader;
import com.atguigu.ssyx.user.mapper.LeaderMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.atguigu.ssyx.user.service.LeaderService;
import org.springframework.stereotype.Service;

/**
 * 团长表(Leader)表服务实现类
 *
 * @author makejava
 * @since 2025-01-20 12:12:54
 */
@Service("leaderService")
public class LeaderServiceImpl extends ServiceImpl<LeaderMapper, Leader> implements LeaderService {

}


package com.wu.idomwx.generator.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.wu.idomwx.generator.domain.Userinfo;
import com.wu.idomwx.generator.service.UserinfoService;
import com.wu.idomwx.generator.mapper.UserinfoMapper;
import org.springframework.stereotype.Service;

/**
 * @author 45732
 * @description 针对表【userinfo】的数据库操作Service实现
 * @createDate 2025-04-21 18:11:35
 */
@Service
public class UserinfoServiceImpl extends ServiceImpl<UserinfoMapper, Userinfo>
    implements UserinfoService{

    @Override
    public boolean ExistsUser(String username) {
        LambdaQueryWrapper<Userinfo> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(Userinfo::getUsername, username);

        return baseMapper.selectCount(wrapper) > 0;
    }

    // 实现新增方法：根据用户名获取用户信息
    @Override
    public Userinfo getUserByUsername(String username) {
        LambdaQueryWrapper<Userinfo> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(Userinfo::getUsername, username);

        return baseMapper.selectOne(wrapper);
    }

    @Override
    public boolean registerUser(Userinfo user) {
        // 检查用户是否已经存在
        if (ExistsUser(user.getUsername())) {
            return false;
        }

        // 插入新用户信息
        return save(user);
    }

}
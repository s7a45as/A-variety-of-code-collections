package com.wu.idomwx.generator.service;

import com.wu.idomwx.generator.domain.Userinfo;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * @author 45732
 * @description 针对表【userinfo】的数据库操作Service
 * @createDate 2025-04-21 18:11:35
 */
public interface UserinfoService extends IService<Userinfo> {

    boolean ExistsUser(String username);
    boolean registerUser(Userinfo user);
    // 新增方法：根据用户名获取用户信息
    Userinfo getUserByUsername(String username);
}
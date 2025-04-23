package com.wu.idomwx.generator.controller;

import com.wu.idomwx.generator.Utils.Result;
import com.wu.idomwx.generator.domain.Userinfo;
import com.wu.idomwx.generator.dto.UserReqGegister;
import com.wu.idomwx.generator.dto.Userreq;
import com.wu.idomwx.generator.service.UserinfoService;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

@RestController
@Slf4j
@RequiredArgsConstructor
@RequestMapping("/auth")
public class UserController {
    private final UserinfoService userinfoService;

    @PostMapping("/login")
    public Result<Userinfo> login(@RequestBody Userreq userdto) {
        try {
            log.info("用户登录请求: {}", userdto);

            // 检查用户是否存在
            if (!userinfoService.ExistsUser(userdto.getUsername())) {
                log.warn("用户不存在: {}", userdto.getUsername());
                return Result.fail(400, "未注册", "用户不存在");
            }

            // 验证密码
            Userinfo user = userinfoService.getUserByUsername(userdto.getUsername());
            if (!user.getPassword().equals(userdto.getPassword())) {
                log.warn("密码错误: {}", userdto.getUsername());
                return Result.fail(400, "密码错误", "密码不正确");
            }

            // 登录成功，返回用户信息
            log.info("用户登录成功: {}", userdto.getUsername());
            return Result.success(user);
        } catch (Exception e) {
            log.error("登录过程中发生异常: {}", e.getMessage(), e);
            return Result.fail(500, "服务器错误", "登录过程中发生异常");
        }
    }
    @PostMapping("/register")
    public Result<Userinfo> register(@RequestBody UserReqGegister userdto) {
        try {
            log.info("用户注册请求: {}", userdto);

            // 将 Userreq 转换为 Userinfo
            Userinfo user = new Userinfo();
            user.setUsername(userdto.getUsername());
            user.setPassword(userdto.getPassword()); // 注意：在实际应用中，密码需要进行加密处理
            user.setSalt("11111");
            // 调用注册方法
            boolean isRegistered = userinfoService.registerUser(user);
            if (!isRegistered) {
                log.warn("用户已存在: {}", userdto.getUsername());
                return Result.fail(400, "用户已存在", "该用户名已被注册");
            }

            // 注册成功，返回用户信息
            log.info("用户注册成功: {}", userdto.getUsername());
            return Result.success(user);
        } catch (Exception e) {
            log.error("注册过程中发生异常: {}", e.getMessage(), e);
            return Result.fail(500, "服务器错误", "注册过程中发生异常");
        }
    }

}
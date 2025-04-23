package com.wu.idomwx.generator.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.wu.idomwx.generator.Utils.Result;
import com.wu.idomwx.generator.domain.Cy;
import com.wu.idomwx.generator.service.CyService;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Slf4j
@RestController
@RequiredArgsConstructor
public class IdiomController {

    private final CyService cyService;

    @GetMapping("find")
    public Result<Cy> find(@RequestParam(value = "word",defaultValue = "一路顺风")String word) {

        LambdaQueryWrapper<Cy> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(Cy::getName, word);
        Cy cy = cyService.getOne(queryWrapper);

        log.info("find word:{}", word);
        return Result.success(cy);

    }
}

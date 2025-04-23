package com.wu.idomwx;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.wu.idomwx.generator.mapper") // 需与 CyMapper 的实际包名一致
public class IdomWxApplication {
    public static void main(String[] args) {
        SpringApplication.run(IdomWxApplication.class, args);
    }
}
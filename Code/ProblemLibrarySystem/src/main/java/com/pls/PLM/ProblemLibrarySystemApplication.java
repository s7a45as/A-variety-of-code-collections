package com.pls.PLM;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.pls.PLM.dao")
public class ProblemLibrarySystemApplication {

    public static void main(String[] args) {
        SpringApplication.run(ProblemLibrarySystemApplication.class, args);
    }

}

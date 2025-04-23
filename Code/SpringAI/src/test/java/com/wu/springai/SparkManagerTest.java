package com.wu.springai;

import com.wu.springai.xunfei.manager.SparkManager;
import jakarta.annotation.Resource;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class SparkManagerTest {

    @Resource
    private SparkManager sparkManager;


    private final String userInput ="你好";

    @Test
    public void testApi() {
        String result = sparkManager.sendMesToAIUseXingHuo(userInput);
        System.out.println(result);
    }
}

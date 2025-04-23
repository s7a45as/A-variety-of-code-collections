package com.wu.springai.xunfei.config;

import io.github.briqt.spark4j.SparkClient;
import lombok.Data;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
//@ConfigurationProperties(prefix = "spring.ai.xunfei.client")
@Data
public class XingHuoConfig {
    @Value("${spring.ai.xunfei.client.appid}")
    private String appid;
    @Value("${spring.ai.xunfei.client.apiSecret}")
    private String apiSecret;
    @Value("${spring.ai.xunfei.client.apiKey}")
    private String apiKey;

    @Bean
    public SparkClient sparkClient() {
        SparkClient sparkClient = new SparkClient();
        sparkClient.apiKey = apiKey;
        sparkClient.apiSecret = apiSecret;
        sparkClient.appid = appid;
        return sparkClient;
    }
}

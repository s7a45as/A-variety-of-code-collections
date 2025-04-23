package com.wu.springai;

import jakarta.annotation.PostConstruct;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
@Slf4j
@SpringBootApplication
public class SpringAiApplication {
    @Value("${spring.ai.openai.api-key}")
    private String apiKey;
    public static void main(String[] args) {
        SpringApplication.run(SpringAiApplication.class, args);
    }
    @PostConstruct
    public void printApiKey() {
        log.info("API Key: {}", apiKey);
    }

}

package com.wu.springai.tongyi.manager;

import com.openai.client.OpenAIClient;
import com.openai.client.okhttp.OpenAIOkHttpClient;
import com.openai.models.ChatCompletion;
import com.openai.models.ChatCompletionCreateParams;
import lombok.AllArgsConstructor;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
@Slf4j
@AllArgsConstructor
@RequiredArgsConstructor
public class TongyiManager {

    @Value("${spring.ai.tongyi.api-key}")
    private String apiKey;

    @Value("${spring.ai.tongyi.base-url}")
    private String baseUrl;

    @Value("${spring.ai.tongyi.chat.options.model}")
    private String model;


    public String getTongyiAnser(String message) {
        OpenAIClient client = OpenAIOkHttpClient.builder()
                .apiKey(apiKey)
                .baseUrl(baseUrl)
                .build();
        ChatCompletionCreateParams params = ChatCompletionCreateParams.builder()
                .addUserMessage(message)
                .model(model)
                .build();
        ChatCompletion chatCompletion = client.chat().completions().create(params);
        log.info("chat completion: {}", chatCompletion);
        return chatCompletion.choices().get(0).message().content().orElse("无返回内容");
    }
}

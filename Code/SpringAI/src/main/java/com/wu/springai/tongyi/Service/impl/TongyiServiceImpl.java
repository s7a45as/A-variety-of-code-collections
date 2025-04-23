package com.wu.springai.tongyi.Service.impl;

import com.openai.client.OpenAIClient;
import com.openai.client.okhttp.OpenAIOkHttpClient;
import com.openai.models.ChatCompletion;
import com.openai.models.ChatCompletionCreateParams;
import com.wu.springai.tongyi.Service.TongyiService;
import com.wu.springai.tongyi.manager.TongyiManager;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

@Slf4j
@Service
@RequiredArgsConstructor
public class TongyiServiceImpl implements TongyiService {

    private  final   TongyiManager tongyiManager;

    @Override
    public String getTongyiIdom(String message) {
        String tmp="请简单解释一下这个成语的意思，和发音，以及出处，字数在100字左右";
        message+=tmp;
        log.info(message);
        return tongyiManager.getTongyiAnser(message);
    }


}

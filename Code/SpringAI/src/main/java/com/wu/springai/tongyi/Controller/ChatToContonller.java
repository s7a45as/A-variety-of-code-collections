package com.wu.springai.tongyi.Controller;

import com.wu.springai.tongyi.Service.TongyiService;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.ai.openai.OpenAiChatModel;
import org.springframework.web.bind.annotation.*;
import com.wu.springai.Utils.Result;
@Slf4j
@RestController
@RequiredArgsConstructor
public class ChatToContonller {

//    private final OpenAiChatModel chatModel;
    private final TongyiService tongyiService;
    @GetMapping("tongyi/chat")
    public Result<String> generate(@RequestParam(value = "message",defaultValue = "马到成功")String message) {
        log.info(message);
        return Result.success(tongyiService.getTongyiIdom(message));
    }


}

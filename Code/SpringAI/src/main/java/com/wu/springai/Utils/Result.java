package com.wu.springai.Utils;

import com.fasterxml.jackson.annotation.JsonInclude;
import lombok.AccessLevel;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 通用响应结果封装类
 * @param <T> 响应数据类型
 */
@Data
@NoArgsConstructor(access = AccessLevel.PRIVATE)
@JsonInclude(JsonInclude.Include.NON_NULL)
public class Result<T> {

    /**
     * 状态码（推荐使用HTTP状态码+业务状态码组合）
     */
    private int code;

    /**
     * 是否成功标识
     */
    private boolean success;

    /**
     * 响应数据
     */
    private T data;

    /**
     * 错误信息（面向开发人员的调试信息）
     */
    private String devMessage;

    /**
     * 用户提示信息（面向最终用户的友好提示）
     */
    private String userMessage;

    /**
     * 请求路径（可选）
     */
    private String path;

    /**
     * 时间戳
     */
    private long timestamp = System.currentTimeMillis();

    /**
     * 成功响应（带数据）
     */
    public static <T> Result<T> success(T data) {
        Result<T> result = new Result<>();
        result.code = 200;
        result.success = true;
        result.data = data;
        return result;
    }

    /**
     * 成功响应（不带数据）
     */
    public static <T> Result<T> success() {
        return success(null);
    }

    /**
     * 业务失败响应
     * @param errorCode 错误码（推荐使用枚举定义）
     * @param devMsg    开发人员调试信息
     * @param userMsg   用户提示信息
     */
    public static <T> Result<T> fail(int errorCode, String devMsg, String userMsg) {
        Result<T> result = new Result<>();
        result.code = errorCode;
        result.success = false;
        result.devMessage = devMsg;
        result.userMessage = userMsg;
        return result;
    }

    /**
     * 系统异常响应（500错误）
     */
    public static <T> Result<T> error(String devMsg, String userMsg) {
        return fail(500, devMsg, userMsg);
    }

    /**
     * 设置请求路径（链式调用）
     */
    public Result<T> path(String path) {
        this.path = path;
        return this;
    }
}
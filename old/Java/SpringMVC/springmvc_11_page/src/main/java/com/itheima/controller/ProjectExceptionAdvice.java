package com.itheima.controller;

import com.itheima.exception.BusinessException;
import com.itheima.exception.SystemException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class ProjectExceptionAdvice {

    @ExceptionHandler(SystemException.class)
    public Result doSystemException(SystemException ex){
        // 记录日志
        // 发送消息给运维
        // 发送邮件给开发人员,ex对象发送给开发人员
        return new Result(ex.getCode() , null , ex.getMessage());
    }

    @ExceptionHandler(BusinessException.class)
    public Result doBusinessException(BusinessException ex){
        return new Result(ex.getCode() , null , ex.getMessage());
    }

    /*出现异常现象的常见位置与常见诱因如下
    *   框架内部抛出的异常：因使用不合规而导致
    *   数据层抛出的异常：因外部服务器故障导致（例如：服务器访问超时）
    *   业务层抛出的异常：因业务逻辑书写错误导致（例如：遍历业务书写操作，导致索引异常等）
    *   表现层抛出的异常：因数据收集，校验等规则导致（例如：不匹配的数据类型间导致异常）
    *   工具类抛出的异常：因工具类书写不严谨不够健壮导致（例如：必要释放的连接长期未释放等）*/
    @ExceptionHandler(Exception.class)
    /*@ExceptionHandler 设置指定异常的处理方案，功能等同于控制器方法，出现异常后终止原始控制器执行，并转入当前方法执行
    *   此方法可以根据处理的一场不同，制作多个方法分别处理对应的异常*/
    public Result doException(Exception ex){
        // 记录日志
        // 发送消息给运维
        // 发送邮件给开发人员,ex对象发送给开发人员
        return new Result(Code.SYSTEM_UNKNOW_ERR , null , "系统繁忙，请稍后再试！");
    }
}

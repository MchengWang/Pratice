package com.itheima.controller.interceptor;

import org.springframework.stereotype.Component;
import org.springframework.web.method.HandlerMethod;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@Component
/*多拦截器执行顺序
*   当配置多个拦截器是，形成拦截器链
*   拦截器链的运行顺序参照拦截器添加顺序为准
*   当拦截器中出现对原始处理器的拦截，后面的拦截器均终止运行
*   当拦截器运行中断，仅运行配置在前面的拦截器的afterCompletion操作
* 拦截器链的运行顺序
*   preHandle：与配置顺序相同，必定运行
*   postHandle：与配置顺序相反，可能不运行
*   afterCompletion：与配置顺序相反，可能不运行*/
public class ProjectInterceptor2 implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        System.out.println("preHandle ... 222");
        return true;
    }

    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        System.out.println("postHandle ... 222");
    }

    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        System.out.println("afterCompletion ... 222");
    }
}

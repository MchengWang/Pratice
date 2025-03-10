package com.itheima.controller.interceptor;

import org.springframework.stereotype.Component;
import org.springframework.web.method.HandlerMethod;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/*拦截器（Interceptor）是一种动态拦截方法调用的机制
 * 作用：
 *   在指定的方法调用前后执行预先设定后的代码
 *   组织原始方法的执行
 * 拦截器与过滤器的区别
 *   归属不同：Filter属于servlet技术，Interceptor属于SpringMVC技术
 *   拦截内容不同：Filter对所有访问进行增强，Interceptor仅针对SpringMVC的访问进行增强*/
@Component
public class ProjectInterceptor implements HandlerInterceptor {
    /*拦截器入门案例 步骤
    *   1、声明拦截器的bean，并实现HandlerInterceptor接口（注意：扫描加载bean）
    *   2、定义配置类，继承WebMvcConfigurationSupport，实现addInterceptor方法（注意：扫描加载配置）
    *   3、添加拦截器并设定拦截的访问路径，路径可通过可变参数设置多个
    *   4、使用标准接口WebMvcConfigurer简化开发（注意：侵入式较强）*/

    /*拦截器执行顺序
    *   preHandle
    *       return true
    *           controller
    *           postHandle
    *           afterCompletion
    *       return false
    *           结束*/
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        /*preHandle 前置处理
        *   参数：request请求对象
        *       response 响应对象
        *       handler：被调用的处理器对象，本质上是一个方法对象，对反射技术中的Methos对象进行了再包装
        *   返回值
        *       返回值为false，被拦截的处理器将不执行*/
        String ContextType = request.getHeader("Context-Type");
        HandlerMethod hm = (HandlerMethod) handler;
        System.out.println("preHandle ... " + ContextType);
        return true;
    }

    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        /*postHandle 后置处理
        * 参数 modelAndView：如果处理器执行完成具有返回结果，可以读取到对应数据与页面信息，并进行调整 */
        System.out.println("postHandle ... ");
    }

    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        /*afterCompletion 完成后处理
        *参数 ex：如果处理器执行过程中出现异常对象，可以针对异常情况进行单独处理*/
        System.out.println("afterCompletion ... ");
    }
}

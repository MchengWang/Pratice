package com.itheima.aop;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Component // 将此类变成Bean
@Aspect // 设置此类为切入
public class MyAdvice {

    /*AOP 步骤
    * 1、导入aop坐标
    * 2、定义dao接口与实现类
    * 3、定义通知类，制作通知
    * 4、定义切入点
    *   注意：切入点依托于一个不具有实际意义的方法进行，即无参数，无返回值，方法体与实际逻辑
    * 5、绑定切入点与通知关系，并指定通知添加到原始连接点的具体执行位置
    * 6、定义通知类受Spring容器管理，并定义当前类为切面类
    * 7、开启Spring对AOP注解驱动支持*/

    @Pointcut("execution(* com.itheima.*.*Service.save(..))")

    public void pt(){}

    @Before("pt()")
    public void method(){
        System.out.println(System.currentTimeMillis());
    }








































}

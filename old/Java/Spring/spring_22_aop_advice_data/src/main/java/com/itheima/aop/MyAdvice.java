package com.itheima.aop;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component
@Aspect
public class MyAdvice {
    @Pointcut("execution(* com.itheima.dao.BookDao.findName(..))")
    private void pt(){}

//    @Before("pt()")
    public void before(JoinPoint jp){
        /*JoinPoint 对象描述了连接点方法的运行状态，可以获取到原始方法的调用参数
        * ProceedJoinPoint是JoinPoint的子类*/
        Object[] args = jp.getArgs();
        System.out.println(Arrays.toString(args));
        System.out.println("before advice ...");
    }

//    @After("pt()")
    public void after(JoinPoint jp){
        Object[] args = jp.getArgs();
        System.out.println(Arrays.toString(args));
        System.out.println("after advice ...");
    }

//    @Around("pt()")
    public Object around(ProceedingJoinPoint pjp){
        Object[] args = pjp.getArgs();
        System.out.println(Arrays.toString(args));
        args[0] = 666;
        Object ret = null;
        try {
            ret = pjp.proceed(args);
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return ret;
    }

    @AfterReturning(value = "pt()" , returning = "ret") // 如果你的方法中有返回值，就将返回值放到形参中
    public void afterReturning(JoinPoint jp , Object ret){ // 如果有JoinPoint接入点参数，必须放在参数的第一位
        System.out.println("afterReturning advice ..." + ret);
    }

    @AfterThrowing(value = "pt()" , throwing = "t")
    public void afterThrowing(Throwable t){
        System.out.println("afterThrowing advice ..." + t);
    }
}

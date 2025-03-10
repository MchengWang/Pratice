package com.itheima.aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.Signature;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Component
@Aspect
public class ProjectAdvice {

    // 匹配业务层的所有方法
    @Pointcut("execution(* com.itheima.service.*Service.*(..))")
    public void servicePt(){};

    @Around("ProjectAdvice.servicePt()")
    public void runSpeed(ProceedingJoinPoint pjp) throws Throwable {
        Signature signature = pjp.getSignature();
//        System.out.println(signature.getDeclaringType()); // 获取执行方法的类型
        String className = signature.getDeclaringTypeName();
//        System.out.println(signature.getName()); // 获取执行方法的名称
        String methodName = signature.getName();
        long start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
            Object ret = pjp.proceed();
        }
        long end = System.currentTimeMillis();
        System.out.println("万次执行" + className + "." + methodName + "---->" + (end - start) + " ms");
    }

}

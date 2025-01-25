package com.chxd.advice;


import org.aspectj.lang.JoinPoint;

public class LogAdvice {
    public void before(JoinPoint point )
    {
        System.out.println("进入增强功能！");
        System.out.println(point.getTarget().toString());
        System.out.println("植入函数:"+point.getSignature().getName());
        System.out.println("他的参数有:");
        for (int i=0;i<point.getArgs().length;i++)
            System.out.println(point.getArgs()[i].toString());
        //System.out.println(point.getArgs());
    }

    public  void aferreturn(JoinPoint point,Object result)
    {
        System.out.println("函数的返回值:" + result);
    }
}

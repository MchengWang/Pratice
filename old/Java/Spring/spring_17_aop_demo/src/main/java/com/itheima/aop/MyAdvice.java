package com.itheima.aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;


@Component
@Aspect
public class MyAdvice {
    /*连接点（JointPoint）：程序执行过程中的任意位置，粒度为执行方法、抛出异常、设置变量等
    *   在SpringAOP中，理解为方法的执行
    * 切入点（Pointcut）：匹配连接点的式子
    *   在SpringAOP，一个切入点可以只描述一个具体方法，也可以匹配多个方法
    *       一个具体方法：com.itheima.dao包下的BookDao接口中的无形参无返回值的save方法
    *       匹配多个方法：所有的save方法，所有的get开头的方法，所有以Dao结尾的任意方法，所有带有一个参数的方法
    *通知（Advice）：在切入点出执行的操作，也就是共性功能
    * 切面（Aspect）：描述通知与切入点的对应关系 */

    @Pointcut("execution(* com.itheima.dao.BookDao.*d*(..))")
    private void pt(){}

    @Around("pt()")
    public Object around(ProceedingJoinPoint pjp) throws Throwable {
        System.out.println("------------------------------");
        Long startTime = System.currentTimeMillis();
        for (int i = 0 ; i<10000 ; i++) {
            //调用原始操作
            pjp.proceed();
        }
        Long endTime = System.currentTimeMillis();
        Long totalTime = endTime-startTime;
        System.out.println("执行万次消耗时间：" + totalTime + "ms");
        return null;
    }

}

package com.itheima.aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

@Component
@Aspect
public class MyAdvice {
    /*AOP通知描述了抽取的共性功能，根据共性功能的抽取的位置不同，最终运行代码是要将其加入到合理的位置
    * AOP通知共分为5种类型
    *   前置通知 @Before
    *   后置通知 @After
    *   环绕通知 @Around
    *   返回后通知 @AfterReturning
    *   抛出异常后通知 @AfterThrowing*/
    @Pointcut("execution(void com.itheima.dao.BookDao.update())")
    private void pt(){}
    @Pointcut("execution(int com.itheima.dao.BookDao.select())")
    private void pt2(){}

//    @Before("pt()") // 当前通知方法在原始切入点方法前执行
    public void before(){
        System.out.println("before advice ...");
    }

//    @After("pt()") // 当前通知方法在原始切入点方法后运行
    public void after(){
        System.out.println("after advice ...");
    }

//    @Around("pt()") // 当前通知方法在原始切入点方法前后运行
    /*@Around()注意事项
    * 1、环绕通知必须依赖形参ProceedingJoinPoint才能实现对原始方法的调用，进而实现原始方法调用前后同时添加通知
    * 2、通知中如何未使用ProceedingJoinPoint对原始方法惊醒调用将跳出原始方法的执行
    * 3、对原始方法的调用可以不接受返回值，通知方法设置为void即可，如果接收返回值，必须而设定为Obeject类型
    * 4、原始方法的返回值如果是void类型，通知方法的返回值类型可以设置成void，也可以设置成Object
    * 5、由于无法预知原始方法运行后是否回抛出异常，因此环绕通知必须抛出Throwable对象*/
    public Object around(ProceedingJoinPoint pjp) throws Throwable {
        System.out.println("around before advice ...");
        // 表示对原始操作的调用
        Object ret = pjp.proceed();
        System.out.println("around after advice ...");
        return ret;
    }

//    @Around("pt2()")
    public Object aroundSelect(ProceedingJoinPoint pjp) throws Throwable {
        System.out.println("around before advice ...");
        // 表示对原始操作的调用
        Object ret = pjp.proceed(); // 环绕通知可以将原始方法的返回值接收出来
        System.out.println("around after advice ...");
        return ret; // 最后一定要将结果返回出去
    }

//    @AfterReturning("pt2()") // 当前通知方法在原始切入点方法正常执行完毕后运行
    public void  afterReturning(){
        System.out.println("afterReturning advice ...");
    }

//    @AfterThrowing("pt2()") // 当前通知方法在原始切入点方法运行抛出异常后执行
    public void  afterThrowing(){
        System.out.println("afterThrowing advice ...");
    }
}

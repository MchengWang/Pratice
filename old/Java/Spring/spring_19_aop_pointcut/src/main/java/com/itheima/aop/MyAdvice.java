package com.itheima.aop;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Component
@Aspect
public class MyAdvice {
    //切入点表达式：
//    @Pointcut("execution(void com.itheima.dao.BookDao.update())")
//    @Pointcut("execution(void com.itheima.dao.impl.BookDaoImpl.update())")
//    @Pointcut("execution(* com.itheima.dao.impl.BookDaoImpl.update(*))")    //no
//    @Pointcut("execution(void com.*.*.*.update())")
//    @Pointcut("execution(* *..*(..))")
//    @Pointcut("execution(* *..*e(..))")
//    @Pointcut("execution(void com..*())")
//    @Pointcut("execution(* com.itheima.*.*Service.find*(..))")
    //执行com.itheima包下的任意包下的名称以Service结尾的类或接口中的save方法，参数任意，返回值任意
    @Pointcut("execution(* com.itheima.*.*Service.save(..))")
    /*切入点表达式标准格式：工作关键词（访问修饰符 返回值 包名.类/接口.方法名(参数) 异常名）
     * execution(void com.itheima.dao.BookDao.update())
     *   动作关键字：描述切入点的行为动作，例如execution表示执行到指定切入点
     *   访问修饰符：public,private等，可以省略
     *   返回值
     *   包名
     *   类/接口名
     *   方法名
     *   参数
     *   异常名：方法定义中抛出指定异常，可以省略
     *
     *
     * 可以使用通配符描述切入点，快速描述
     *   * :单个独立的任意符号，可以独立出现，也可以作为前缀或者后缀的匹配符出现
     *       execution (public * com.itheima.*.UserService.find*(*))
     *       匹配com.itheima包下的任意包中的UserService类或接口中的所有find开头的带有一个参数的方法
     *   .. :多个连续的任意符号，可以独立出现，常用于简化包名与参数的书写
     *       execution (public User com..UserService.fingById(..))
     *       匹配com剥下的任意包中的UserService类或者接口中的所有名称为findBuId的方法
     *   + : 专用于匹配子类类型
     *       execution (* *..*Service+.*(..))*/
    private void pt(){}

    /*书写技巧
     *   所有代码按照标准规范开发，否则一下技巧全部失效
     *   描述切入点通常描述接口，而不是描述实现类
     *   访问控制修饰符针对接口开发均采用public描述（可省略访问控制修饰符描述）
     *   返回值类型对于怎删改类使用精准类型加速匹配，对于查询类使用*通配符快速描述
     *   包名书写尽量不使用..匹配，效率过低，常用*做单个包描述匹配，或精准匹配
     *   接口名/类名书写名称与模块相关的采用*匹配，例如UserService书写成*Service，绑定业务层接口名
     *   方法名书写以动词进行精准匹配，名词采用*匹配，例如getVyId书写成getBy*，selectAll书写成selectAll
     *   参数规则较为复杂，根据业务方法灵活调整
     *   通常不使用异常作为匹配规则*/

    @Before("pt()")
    public void method(){
        System.out.println(System.currentTimeMillis());
    }
}

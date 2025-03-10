package com.itheima.service;

import org.springframework.transaction.annotation.Transactional;

public interface AccountService {
    /**
     * 转账操作
     * @param out 传出方
     * @param in 转入方
     * @param money 金额
     */
    @Transactional
    /*事务开启
    * 1、在业务层接口上添加Spring事务管理
    *   注意事项：
    *       Spring注解是事务通常添加在业务层接口中而不会添加到业务层实现类中，降低耦合
    *       注解是事务可以添加到业务方法上表示当前方法开启事务，也可以添加到接口上表示当前接口中的所有方法开启事务
    * 2、设置事务管理器
    *   注意事项
    *       事务管理器要根据实现技术进行选择
    *       MyBatis框架使用的是JDBC事务
    * 3、开启注解式事务驱动 */
    public void transfer(String out , String in , Double money);

    /*事务角色
    * 事务管理员：发起事务方，在Spring中通常指代业务层开启事务的方法
    * 事务协调员：加入事务方，在Spring中通常指代数据层方法，也可以是业务层方法*/
}

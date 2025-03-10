package com.itheima.service;

import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

public interface LogService {

    /*转账业务追加日志
    * 需求：实现任意两个账户间转账操作，并对每次转账操作在数据库进行留痕
    * 需求微缩：A账户减钱，B账户加钱，数据库记录日志
    * 分析
    *   1、基于转账操作案例添加日志模块，实现数据库中记录日志
    *   2、业务层转账操作（transfer），调用减钱，加钱与记录日志功能
    * 实现效果预期
    *   无论转账操作是否成功，均进行转账操作的日志留痕
    * 存在的问题
    *   日志的记录与转账操作隶属于同一个事物，同成功同失败
    * 实现效果预期改进
    *   无论转账操作是否成功，日志必须保留*/

    @Transactional(propagation = Propagation.REQUIRES_NEW) // 解决隶属于同一事物的方法 设置事务传播行为REQUIRES_NEW（需要新事务）
    /*事务传播行为：事务协调员对事务管理员所携带事务的处理态度*/
    void log(String out , String in , Double money);

}

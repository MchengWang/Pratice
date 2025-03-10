package com.itheima.service;

import com.itheima.config.SpringConfig;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = SpringConfig.class)
public class AccountServiceTest {

    @Autowired
    private AccountService accountService;

    @Test
    /*模拟银行账户间转账业务
    * 需求：实现任意两个账户间转账操作
    * 需求微缩：A账户减钱，B账户加钱
    * 分析
    *   1、数据层提供基础操作，指定账户减钱（outMoney），指定账户加钱（inMoney）
    *   2、业务层提供转账操作（transfer），调用减钱与加钱的操作
    *   3、提供2个账户和操作金额执行转账操作
    *   4、基于Spring整合MyBatis环境搭建上述操作
    * 结果分析
    *   1、程序正常执行时，账户金额A减B加，没有问题
    *   2、程序出现异常后，转账失败，但是异常之前操作成功，异常之后操作失败，整体业务失败*/
    public void testTransfer(){
        accountService.transfer("Tom" , "Jerry" , 100D);
    }
}

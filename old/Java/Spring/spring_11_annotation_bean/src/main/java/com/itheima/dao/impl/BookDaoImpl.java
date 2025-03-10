package com.itheima.dao.impl;

import com.itheima.dao.BookDao;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;

//@Component("bookDao")
/*注解形式定义bean
    1、使用@component定义bean 把注解加到你需要设置为bean的类上
    2、核心配置文件中通过组件扫描加载bean*/
@Repository("bookDao")
public class BookDaoImpl implements BookDao {
    public void save() {
        System.out.println("book dao save ...");
    }
}

package com.itheima.service.impl;

import com.itheima.dao.BookDao;
import com.itheima.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

@Service
public class BookServiceImpl implements BookService {
    @Autowired
    /*注意：自动装配基于放射设计创建对象并暴力反射对应属性为私有属性初始化数据，因此无需提供setter方法
    * 注意：自动装配建议使用无参构造方法创建对象（默认），如果不提供对应构造方法，请提供唯一的构造方法*/
    @Qualifier("bookDao")
    /*使用@Qualifier注解开启指定名称装配bean
    *注意：@Qualifier注解无法单独使用，必须配合Autowired注解使用*/
    private BookDao bookDao;

    public void save() {
        System.out.println("book service save ...");
        bookDao.save();
    }
}

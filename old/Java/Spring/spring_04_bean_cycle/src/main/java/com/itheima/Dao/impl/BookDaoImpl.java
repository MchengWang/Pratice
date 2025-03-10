package com.itheima.Dao.impl;

import com.itheima.Dao.BookDao;

public class BookDaoImpl implements BookDao {
    public void save(){
        System.out.println("book dao save ... ");
    }

    // 表示bean初始化对应的操作
    public void init(){
        System.out.println("init .....");
    }

    // 表示bean销毁前的对应操作
    public void destory(){
        System.out.println("destory ......");
    }
}

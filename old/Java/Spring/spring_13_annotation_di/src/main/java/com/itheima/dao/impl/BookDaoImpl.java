package com.itheima.dao.impl;

import com.itheima.dao.BookDao;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Repository;

@Repository("bookDao")
public class BookDaoImpl implements BookDao {
    @Value("${name}") // 实现简单类型注入
    private String name;

    public void save() {
        System.out.println("book dao save ..." + name);
    }
}

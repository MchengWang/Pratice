package com.itheima.Service.impl;

import com.itheima.Dao.BookDao;
import com.itheima.Dao.UserDao;
import com.itheima.Service.BookService;

public class BookServiceImpl implements BookService{
    private BookDao bookDao;
    private UserDao userDao;

    public BookServiceImpl(BookDao bookDao, UserDao userDao) {
        this.bookDao = bookDao;
        this.userDao = userDao;
    }

    public void save(){
        System.out.println("book service save ... ");
        bookDao.save();
        userDao.save();
    }
}

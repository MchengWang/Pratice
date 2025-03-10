package com.itheima.service.impl;

import com.itheima.controller.Code;
import com.itheima.dao.BookDao;
import com.itheima.domain.Book;
import com.itheima.exception.BusinessException;
import com.itheima.exception.SystemException;
import com.itheima.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookServiceImpl implements BookService {

    @Autowired
    private BookDao bookDao;

    @Override
    public boolean save(Book book) {
        bookDao.save(book);
        return true;
    }

    @Override
    public boolean delete(Integer id) {
        bookDao.delete(id);
        return true;
    }

    @Override
    public boolean update(Book book) {
        bookDao.update(book);
        return true;
    }

    @Override
    public Book getById(Integer id) {
        Book book = bookDao.getById(id);
        if(id == 1){
            throw new BusinessException(Code.BUSINESS_ERR, "请不要使用你的技术挑战我的耐性");
        }

        try {
            // 将可能出现的异常进行包装，转换成自定义异常
            int i = 1/0;
        }catch (Exception e){
            throw new SystemException(Code.SYSTEM_TIMEOUT_ERR , "服务器访问超时，请重试！"  , e);
        }
        return book;
    }

    @Override
    public List<Book> getAll() {
        List<Book> bookList = bookDao.getAll();
        return bookList;
    }
}

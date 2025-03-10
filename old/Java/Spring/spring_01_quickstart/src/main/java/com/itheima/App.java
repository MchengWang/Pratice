package com.itheima;

import com.itheima.Service.BookService;
import com.itheima.Service.impl.BookServiceImpl;

public class App {
    public static void main(String[] args) {
        BookService bookService = new BookServiceImpl();
        bookService.save();
    }
}

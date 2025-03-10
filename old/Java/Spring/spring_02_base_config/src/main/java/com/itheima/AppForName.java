package com.itheima;

import com.itheima.Dao.BookDao;
import com.itheima.Service.BookService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AppForName {
    public static void main(String[] args) {
        // 3、获取IOC容器
        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
        // 4、获取bean
        BookService bookService = (BookService) ctx.getBean("bookService");

        bookService.save();
    }
}

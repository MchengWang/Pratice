package com.itheima;

import com.itheima.Dao.BookDao;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AppForLifeCycle {
    public static void main(String[] args) {
        ClassPathXmlApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
        ctx.registerShutdownHook(); // 当容器中所有的任务结束后才会关闭
        BookDao bookDao = (BookDao) ctx.getBean("bookDao");
        bookDao.save();
//        ctx.close(); // 暴力关闭容器
    }
}

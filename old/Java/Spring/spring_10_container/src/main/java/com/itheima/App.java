package com.itheima;

import com.itheima.dao.BookDao;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

public class App {
    public static void main(String[] args) {
        // 加载类路径下的配置文件
        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
        // 从文件系统下加载配置文件
//        ApplicationContext ctx = new FileSystemXmlApplicationContext("C:\\Users\\AX\\IdeaProjects\\Spring\\spring_10_container\\src\\main\\resources\\applicationContext.xml");
        BookDao bookDao = (BookDao) ctx.getBean("bookDao"); // 使用bean名称获取
//        BookDao bookDao = ctx.getBean("bookDao" , BookDao.class); // 使用bean名称获取并指定类型
//        BookDao bookDao = ctx.getBean(BookDao.class); // 使用bean类型获取
        bookDao.save();
    }
}

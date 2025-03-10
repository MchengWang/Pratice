package com.ithiema;

import com.ithiema.dao.UserDao;
import com.ithiema.factory.UserDaoFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AppForInstanceUser {
    public static void main(String[] args) {
        // 创建实例化工厂对象
//        UserDaoFactory userDaoFactory = new UserDaoFactory();
        // 通过实例化工厂对象创建对象
//        UserDao userDao = userDaoFactory.getUserDao();
//        userDao.save();

        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");

        UserDao userDao1 = (UserDao) ctx.getBean("userDao");
        UserDao userDao2 = (UserDao) ctx.getBean("userDao");

        System.out.println(userDao1);
        System.out.println(userDao2);
    }
}

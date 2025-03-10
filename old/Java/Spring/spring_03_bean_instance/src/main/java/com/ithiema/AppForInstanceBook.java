package com.ithiema;

import com.ithiema.dao.UserDao;
import com.ithiema.factory.UserDaoFactory;

public class AppForInstanceBook {
    public static void main(String[] args) {
        // 创建实例化工厂对象
        UserDaoFactory userDaoFactory = new UserDaoFactory();
        // 通过实例化工厂对象创建对象
        UserDao userDao = userDaoFactory.getUserDao();
        userDao.save();

//        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
//
//        UserDao userDao = ctx.getBean("userDao");
//
//        userDao.save();

    }
}

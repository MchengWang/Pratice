package com.chxd.service;

import com.chxd.dao.UserDao;
import com.chxd.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;


public class UserService {

    @Autowired
    UserDao userDao;

    public int addUser(User user){


     //   System.out.println(System.currentTimeMillis()+":"+user.getUsername()+"请求插入");
        int  ret= userDao.insert(user);
      //  System.out.println("插入结果="+ret);
        return ret;
    }
}

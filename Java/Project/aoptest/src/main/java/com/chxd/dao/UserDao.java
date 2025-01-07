package com.chxd.dao;

import com.chxd.pojo.User;
import org.springframework.stereotype.Component;

@Component("userDao")
public class UserDao {

    public int insert(User user)
    {
        //System.out.println("user:"+user.getUsername()+"已经存入数据库");
        return 1;
    }
}

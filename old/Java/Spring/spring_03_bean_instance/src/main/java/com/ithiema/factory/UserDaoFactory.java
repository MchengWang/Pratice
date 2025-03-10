package com.ithiema.factory;

import com.ithiema.dao.UserDao;
import com.ithiema.dao.impl.UserDaoImpl;

public class UserDaoFactory {
    public UserDao getUserDao(){
        return new UserDaoImpl();
    }
}

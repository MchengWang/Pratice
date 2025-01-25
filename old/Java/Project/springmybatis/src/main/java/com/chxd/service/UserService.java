package com.chxd.service;

import com.chxd.dao.UserDAO;
import com.chxd.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {

    @Autowired
    UserDAO userDAO;

    public int addUser(User user)
    {
        return userDAO.insert(user);
    }
}

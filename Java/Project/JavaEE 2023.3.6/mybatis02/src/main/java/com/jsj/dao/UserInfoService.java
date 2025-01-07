package com.jsj.dao;

import com.jsj.entries.UserInfo;

import java.util.List;

public interface UserInfoService {

    List<UserInfo> selectAll();
    UserInfo selectUserById(int uid);
}

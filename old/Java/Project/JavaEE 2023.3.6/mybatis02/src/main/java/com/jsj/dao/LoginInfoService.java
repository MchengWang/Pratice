package com.jsj.dao;

import com.jsj.entries.LoginInfo;

import java.util.List;

public interface LoginInfoService {

    List<LoginInfo> selectAllInfo();
}

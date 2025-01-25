package com.jsj.dao;

import com.jsj.entries.ClassInfo;

import java.util.List;

public interface ClassInfoService {

    List<ClassInfo> selectAllInfoWithStudent();
}

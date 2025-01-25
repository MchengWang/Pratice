package com.jsj.dao;

import com.jsj.entries.StudentInfo;

import java.util.List;

public interface StudentInfoService {

    List<StudentInfo> selectStudentByCid(int cid);
    List<StudentInfo> selectInfoWithClass(int cid);
}

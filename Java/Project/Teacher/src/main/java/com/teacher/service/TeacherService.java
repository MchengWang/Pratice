package com.teacher.service;

import com.teacher.pojo.TeacherInfo;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

//@Transactional
public interface TeacherService {

    public boolean save(TeacherInfo teacherInfo);


    public boolean delete(int id);

    public boolean update(TeacherInfo teacherInfo);

    public TeacherInfo getById(Integer id);

    public List<TeacherInfo> getAll();
}

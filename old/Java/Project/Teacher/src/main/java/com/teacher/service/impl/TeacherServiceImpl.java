package com.teacher.service.impl;

import com.teacher.service.TeacherService;
import com.teacher.dao.TeacherDao;
import com.teacher.pojo.TeacherInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class TeacherServiceImpl implements TeacherService {

    @Autowired
    private TeacherDao teacherDao;

    public boolean save(TeacherInfo teacherInfo) {
        teacherDao.save(teacherInfo);
        return true;
    }

    public boolean delete(int id) {
        teacherDao.delete(id);
        return true;
    }

    public boolean update(TeacherInfo teacherInfo) {
        teacherDao.update(teacherInfo);
        return true;
    }

    public TeacherInfo getById(Integer id) {
        TeacherInfo teacherInfo = teacherDao.getById(id);
        return teacherInfo;
    }

    public List<TeacherInfo> getAll() {
        List<TeacherInfo> teacherInfoList = teacherDao.getAll();
        return teacherInfoList;
    }
}

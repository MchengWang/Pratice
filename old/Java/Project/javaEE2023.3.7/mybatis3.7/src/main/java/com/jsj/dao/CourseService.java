package com.jsj.dao;

import com.jsj.entries.Course;

import java.util.List;

public interface CourseService {

    List<Course> selectCourseBySid(int sid);
}

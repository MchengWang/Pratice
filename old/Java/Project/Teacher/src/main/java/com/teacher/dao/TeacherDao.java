package com.teacher.dao;


import com.teacher.pojo.TeacherInfo;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Update;

import java.util.List;

@Mapper
public interface TeacherDao {
    @Select("select * from teachers")
    List<TeacherInfo> getAll();

    @Select("select * from teachers where id = #{id}")
    TeacherInfo getById(int id);

    @Update("update teachers set teacherNo = #{teacherNo} , teacherName = #{teacherName} ," +
            "tel = #{tel} , email = #{email} where id = #{id}")
    void update(TeacherInfo teacherInfo);

    @Delete("delete from teachers where id = #{id}")
    void delete(Integer id);

    @Insert("insert into teachers (id , teacherNo , teacherName , tel , email) values" +
            "(null , #{teacherNo} , #{teacherName} , #{tel} , #{email})")
    void save(TeacherInfo teacherInfo);
}

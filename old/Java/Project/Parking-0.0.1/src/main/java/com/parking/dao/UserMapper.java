package com.parking.dao;

import com.parking.pojo.User;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface UserMapper {

    @Select("select * from user")
    public List<User> getAll(); // 获取全部用户的西信息

    @Insert("insert into user (username , password , role) values (#{username} , #{password} , default )")
    public void enrollInsert(String username , String password); // 注册信息

    @Select("select * from user where username = #{account} and password = #{password}")
    public User loginUser(String account , String password); // 获取数据库存在的用户信息
}

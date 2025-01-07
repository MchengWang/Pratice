package com.wangzihang.dao;

import org.apache.ibatis.annotations.*;
import com.wangzihang.pojo.MemberInfo;

import java.util.List;

@Mapper
public interface MemberInfoDao {
//    @Select("select * from exam2022.rooms")
    List<MemberInfo> getAll();

//    @Select("select * from exam2022.rooms where id = #{id}")
    MemberInfo selectById(int id);

//    @Update("update exam2022.rooms set roomNo = #{roomNo} , ownerName = #{ownerName} ," +
//            "tel = #{tel} , location = #{location},price=#{price} where id = #{id}")
    void update(MemberInfo memberInfo);

//    @Delete("delete from exam2022.rooms where id = #{id}")
    void delete(Integer id);

//    @Insert("insert into exam2022.rooms (id , roomNo , ownerName , tel ,location,price) values" +
//            "(#{id} , #{roomNo} , #{ownerName} , #{tel} , #{location},#{price})")
    void insertRooms(MemberInfo memberInfo);
}

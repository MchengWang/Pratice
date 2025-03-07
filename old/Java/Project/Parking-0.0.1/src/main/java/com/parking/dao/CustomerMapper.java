package com.parking.dao;

import com.parking.pojo.Customer;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface CustomerMapper {

    @Select("select * from customer")
    public List<Customer> getAll(); // 获取全部停车用户信息

    @Delete("delete from customer where id = #{id}")
    public void delCustomer(int id); // 删除指定id的用户信息

    @Insert("insert into customer (name, tel, licensePlate, extra)\n" +
            "        values (#{name} , #{tel} , #{licensePlate} , #{extra});")
    public void InsertCustomer(String name , String tel , String licensePlate , String extra); // 添加停车用户信息

    @Select("select * from customer where name like #{name}")
    public List<Customer> getName(String name); // 按姓名查询

    @Select("select * from customer where licensePlate like #{licensePlate}")
    public List<Customer> getLicensePlate(String licensePlate); // 按车牌查询

    @Select("select * from customer where id = #{id}")
    public List<Customer> getID(int id); // 通过ID查找信息

    @Update("update customer set name = #{name} , tel = #{tel} , licensePlate = #{licensePlate} , extra = #{extra}\n" +
            "        where id = #{id}")
    public void updateCustomer(String name , String tel , String licensePlate , String extra , int id); // 修改用户信息

    @Select("select * from customer where licensePlate = #{licensePlate}")
    public Customer getByLicensePlate(String licensePlate); // 通过车牌获取个人信息
}

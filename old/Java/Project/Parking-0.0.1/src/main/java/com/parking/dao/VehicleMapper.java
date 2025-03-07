package com.parking.dao;

import com.parking.pojo.Vehicle;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

@Mapper
public interface VehicleMapper {
    @Insert("insert into vehicle (licensePlate, local, illustrate, time)\n" +
            "        values (#{licensePlate} , #{local} , #{illustrate} , now());")
    public void insert(String licensePlate , String local , String illustrate); // 插入

    @Select("select * from vehicle where local = #{local}")
    public Vehicle getByLocal(String Local); // 通过车牌获取车位信息
}

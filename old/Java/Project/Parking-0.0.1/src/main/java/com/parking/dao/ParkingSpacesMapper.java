package com.parking.dao;

import com.parking.pojo.ParkingSpaces;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

@Mapper
public interface ParkingSpacesMapper {

    @Insert("insert into ParkingSpaces (parkingSpaces_type , parkingSpaces_state , parkingSpaces_local)\n" +
            "        values (#{type} , #{state} , #{local})")
    public void Insert(String type , String state , String local); // 插入车位

    @Select("select * from ParkingSpaces")
    public List<ParkingSpaces> getAll(); // 获取全部车位信息

    @Select("select count(*) from ParkingSpaces where ParkingSpaces_state like #{state}")
    public int parkingSpaces(String state); // 已停车车位

    @Select("select count(*) from ParkingSpaces where ParkingSpaces_type like #{type}")
    public int smallCar(String type); // 小型车车位

    @Select("select count(*) from ParkingSpaces\n" +
            "        where ParkingSpaces_type like #{type}\n" +
            "        and ParkingSpaces_state like #{parkType}")
    public int parkWithType(String parkType , String type); // 通过停车类型以及车位类型来查询

    @Select("select * from ParkingSpaces where id = #{id}")
    public ParkingSpaces getOnceById(int id); // 查询单个车位信息

    @Update("update ParkingSpaces set ParkingSpaces_type = #{type} , ParkingSpaces_state = #{state} ,\n" +
            "                                 ParkingSpaces_local = #{local} where id = #{id}")
    public void Update(String type , String state , String local , int id); // 修改车位信息

    @Select("select * from ParkingSpaces where ParkingSpaces_type like #{type};")
    public List<ParkingSpaces> getListByType(String type); // 通过车位类型查找车位

    @Select("select * from ParkingSpaces where ParkingSpaces_state like #{state};")
    public List<ParkingSpaces> getListByState(String state); // 通过车位状态查找车位

    @Select(" select * from ParkingSpaces where ParkingSpaces_local like #{local};")
    public ParkingSpaces getListByLocal(String local); // 通过车位位置查找车位

    @Update("update ParkingSpaces set ParkingSpaces_state= \"已停车\" where ParkingSpaces_local = #{local}")
    public void UpdateLocal(String local); // 修改车位状态
}

package com.household.dao;

import org.apache.ibatis.annotations.*;
import com.household.pojo.HouseHoldInfo;

import java.util.List;

@Mapper
public interface HouseHoldInfoDao {
    @Select("select * from householdInfo")
    List<HouseHoldInfo> getAll();

    @Select("select * from householdInfo where id = #{id}")
    HouseHoldInfo getById(int id);

    @Update("update householdInfo set householdNo = #{householdNo} , householdName = #{householdName} ," +
            "tel = #{tel} , location = #{location} where id = #{id}")
    void update(HouseHoldInfo houseHoldInfo);

    @Delete("delete from householdInfo where id = #{id}")
    void delete(Integer id);

    @Insert("insert into householdInfo (id , householdNo , householdName , tel , location) values" +
            "(null , #{householdNo} , #{householdName} , #{tel} , #{location})")
    void save(HouseHoldInfo houseHoldInfo);
}

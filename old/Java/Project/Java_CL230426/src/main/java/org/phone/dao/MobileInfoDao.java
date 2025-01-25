package org.phone.dao;

import org.apache.ibatis.annotations.*;
import org.phone.pojo.MobileInfo;

import java.util.List;

@Mapper
public interface MobileInfoDao {
    @Select("select * from mobileInfo")
    List<MobileInfo> getAll();

    @Select("select * from mobileInfo where id = #{id}")
    MobileInfo getById(int id);

    @Update("update mobileInfo set phoneNo = #{phoneNo} , ownerName = #{ownerName} ," +
            "color = #{color} , brand = #{brand} where id = #{id}")
    void update(MobileInfo mobileInfo);

    @Delete("delete from mobileInfo where id = #{id}")
    void delete(Integer id);

    @Insert("insert into mobileInfo (id , phoneNo , ownerName , color , brand) values" +
            "(null , #{phoneNo} , #{ownerName} , #{color} , #{brand})")
    void save(MobileInfo mobileInfo);
}

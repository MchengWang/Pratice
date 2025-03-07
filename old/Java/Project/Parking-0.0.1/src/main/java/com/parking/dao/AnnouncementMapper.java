package com.parking.dao;

import com.parking.pojo.Announcement;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
public interface AnnouncementMapper {

    @Insert("insert into announcement (title, type, content, creTime, updTIme) values(#{tille} , #{type} , #{content} , now() , now())")
    public void InsertMessage(String tille , String type , String content); // 插入通知

    @Select("select * from announcement")
    public List<Announcement> getAll(); // 获取全部通知

    @Select("select * from announcement where id = #{id}")
    public Announcement getOnce(int id); // 获取单个信息

    @Update("update announcement set title = #{title} , type = #{type} , content = #{content} , updTime = now()\n" +
            "        where id = #{id}")
    public void updateMessage(String title , String type , String content , int id); // 更新数据

    @Delete("delete from announcement where id = #{id}")
    public void delInformation(int id); // 通过id找到信息

    @Select("select * from announcement where title like #{title}")
    public List<Announcement> getMessageByType(String type);

    @Select("select * from announcement where type like #{type}")
    public List<Announcement> getMessageByTitle(String title);
}

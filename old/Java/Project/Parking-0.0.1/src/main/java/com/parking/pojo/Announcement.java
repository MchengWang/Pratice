package com.parking.pojo;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

@Data
@TableName("announcement")
public class Announcement {
    private int id;
    private String title;
    private String type;
    private String content;
    private Date creTime;
    private Date updTime;
}


package com.parking.pojo;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

@Data
@TableName("vehicle")
public class Vehicle {
    private int id;
    private String licensePlate;
    private String local;
    private String illustrate;
    private Date time;
}

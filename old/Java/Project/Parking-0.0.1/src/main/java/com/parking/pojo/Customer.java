package com.parking.pojo;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("customer")
public class Customer {
    private int id;
    private String name;
    private String tel;
    private String licensePlate;
    private String extra;
}

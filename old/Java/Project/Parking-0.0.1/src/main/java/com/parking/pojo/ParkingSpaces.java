package com.parking.pojo;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("parkingspaces")
public class ParkingSpaces {
    private int id;
    private String parkingSpaces_type;
    private String parkingSpaces_state;
    private String parkingSpaces_local;
}

package com.bysj.drm.entity;

import lombok.Data;

import java.io.Serializable;

/**
 * (Member)实体类
 *
 * @author matou
 * @since 2020-05-20 11:28:34
 */
@Data
public class Member implements Serializable {
    private static final long serialVersionUID = -20042270293905402L;

    private Integer id;

    private Integer typeId;

    private String name;

    private String phone;

    private Integer mcode;


}
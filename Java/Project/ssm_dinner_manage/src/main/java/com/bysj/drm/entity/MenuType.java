package com.bysj.drm.entity;

import lombok.Data;

import java.io.Serializable;

/**
 * (MenuType)实体类
 *
 * @author matou
 * @since 2020-05-20 11:27:48
 */
@Data
public class MenuType implements Serializable {
    private static final long serialVersionUID = -38476608987360511L;

    private Integer id;

    private String typeName;


}
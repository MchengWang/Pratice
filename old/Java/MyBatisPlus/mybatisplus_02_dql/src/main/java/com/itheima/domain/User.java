package com.itheima.domain;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.*;

//lombok

@Data
@TableName("tbl_user")
/*@TableName 设置当前类对应与数据库表关系
*   value：设置数据库表名称*/
public class User {
    private Long id;
    private String name;
    @TableField(value = "pwd" , select = false)
    /*@TableField 设置当前属性对应的数据库表中的字段关系
    *   value：设置数据库表字段名称
    *   exist：设置属性在数据库表字段中是否存在，默认为true；
    *   select：设置属性是否参与查询，此属性与select()映射配置不冲突*/
    private String password;
    private Integer age;
    private String tel;
    @TableField(exist = false)
    private Integer online;
}

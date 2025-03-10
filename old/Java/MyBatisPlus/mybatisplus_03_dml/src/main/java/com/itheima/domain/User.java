package com.itheima.domain;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

//lombok

@Data
//@TableName("tbl_user")
/*@TableName 设置当前类对应与数据库表关系
*   value：设置数据库表名称*/
public class User {
//    @TableId(type = IdType.ASSIGN_ID)
    /*@TableId id生成策略控制
    *   AUTO(0):使用数据库id自增策略控制id生成
    *   NONE(1):不设置id生成策略
    *   INPUT(2):用户手工输入id
    *   ASSIGN_ID(3):雪花算法生成id（可兼容数值型与字符串型）
    *   ASSIGN_UUID(4):以UUID生成算法作为id生成策略*/
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

    // 逻辑删除字段，标记当前记录是否被删除
//    @TableLogic(value = "0" , delval = "1")
    /*逻辑删除
    *   删除操作业务问题：业务数据从数据库中丢弃
    *   逻辑删除：为数据设置是否可用状态字段，删除时设置状态字段为不可用状态，数据保留在数据库中
    * 逻辑删除案例
    *   1、数据库表中添加逻辑删除标记字段
    *   2、实体类中添加对应字段，并设定当前字段为逻辑删除标记字段
    *   3、配置逻辑删除字面值*/
    private Integer deleted;
    @Version
    /*乐观锁：业务并发现象带来的问题：秒杀
    * 乐观锁案例
    *   1、数据库表中添加锁标记字段
    *   2、实体类中添加对应字段，并设定当前字段为逻辑删除标记字段
    *   3、配置乐观锁拦截器实现锁机制对应的动态SQL语句拼装
    *   4、使用乐观锁机制再修改前必须先获取到对应数据的version方可正常进行*/
    private Integer version;
}

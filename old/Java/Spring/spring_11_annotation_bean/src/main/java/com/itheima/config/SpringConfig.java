package com.itheima.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration // @Configuration注解用于设定当前类为配置类
@ComponentScan({"com.itheima.service" , "com.itheima.dao"}) // @ComponentScan注解用于设定扫描路径，此注解只能添加一次，多个数据请用数组格式
public class SpringConfig {
}

package com.itheima.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;

@Configuration
@ComponentScan("com.itheima")
@Import({JdbcConfig.class})
public class SpringConfig {
    //1、定义一个方法获得要管理的对象
    //2、添加@Bean，表示当前方法的返回值是一个bean

}

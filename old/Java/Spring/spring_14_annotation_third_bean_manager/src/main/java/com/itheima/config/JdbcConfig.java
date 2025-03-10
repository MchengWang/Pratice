package com.itheima.config;

import com.alibaba.druid.pool.DruidDataSource;
import com.itheima.dao.BookDao;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import javax.sql.DataSource;

//@Configuration
public class JdbcConfig {
    @Value("com.mysql.jc.jdbc.Driver") // 简单类型注入
    private String Driver;
    @Value("jdbc:mysql://localhost:3306/dh")
    private String Url;
    @Value("root")
    private String Username;
    @Value("040820")
    private String Password;
    @Bean
    public DataSource dataSource(BookDao bookDao){
        System.out.println(bookDao); // 引用类型注入只需要为bean定义方法设置形参即可，容器会根据类型自动装配对象
        DruidDataSource ds = new DruidDataSource();
        ds.setDriverClassName(Driver);
        ds.setUrl(Url);
        ds.setUsername(Username);
        ds.setPassword(Password);
        return ds;
    }
}

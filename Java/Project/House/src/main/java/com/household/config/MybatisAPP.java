package com.household.config;

import org.mybatis.spring.SqlSessionFactoryBean;
import org.mybatis.spring.mapper.MapperScannerConfigurer;
import org.springframework.context.annotation.Bean;

import javax.sql.DataSource;

public class MybatisAPP {

    @Bean
    public SqlSessionFactoryBean sqlSessionFactoryBean(DataSource dataSource){
        SqlSessionFactoryBean s = new SqlSessionFactoryBean();
        s.setTypeAliasesPackage("com.household.pojo");
        s.setDataSource(dataSource);
        return s;
    }

    @Bean
    public MapperScannerConfigurer mapperScannerConfigurer(){
        MapperScannerConfigurer m = new MapperScannerConfigurer();
        m.setBasePackage("com.household.dao");
        return m;
    }
}

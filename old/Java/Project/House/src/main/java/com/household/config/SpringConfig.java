package com.household.config;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@Configuration
@ComponentScan("com.household.controller")
@MapperScan("com.household.dao")
@EnableWebMvc
public class SpringConfig {

}

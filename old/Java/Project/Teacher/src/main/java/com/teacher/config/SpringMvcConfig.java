package com.teacher.config;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@Configuration
@ComponentScan("com.teacher.controller")
@MapperScan("com.teacher.dao")
@EnableWebMvc
public class SpringMvcConfig {

}

package org.phone.config;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@Configuration
@ComponentScan("org.phone.controller")
@MapperScan("org.phone.dao")
@EnableWebMvc
public class SpringMvcConfig {

}

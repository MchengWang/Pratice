package com.household.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;
import org.springframework.context.annotation.PropertySource;

@Configuration
@ComponentScan("com.household.service")
@PropertySource("classpath:jdbc.properties")
@Import({DatabaseConfig.class , MybatisAPP.class})
public class SpringApp {
}

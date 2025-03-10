package com.itheima.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

@Configuration // 表明这个类是配置类
@ComponentScan("com.itheima") // 扫描注解
@EnableAspectJAutoProxy
public class SpringConfig {
}

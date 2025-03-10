package com.itheima.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@ComponentScan({"com.itheima"})

/*@PropertySource注解用于加载properties文件
*  注意：路径仅支持单一文件配置，多文件请使用数组格式配置，不允许使用通配符*/
@PropertySource({"jdbc.properties"})
public class SpringConfig {
}

package com.itheima.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@Configuration
@ComponentScan("com.itheima.controller")
//开启json数据类型自动转换
@EnableWebMvc
public class SpringMvcConfig {

    /*@ResponseBody和@RequestParam区别
    * 区别:
    *   @RequestParam 用于接受url地址传参，表单传参【application/x-www-form-urlencoded】
    *   @ResponseBody 用于接受json数据【application/json】
    * 应用
    *   后期开发中，发送json核实数据为主，@ResponseBody应用广泛
    *   如果发送非json格式数据，选用@RequestParam接收请求参数*/


}

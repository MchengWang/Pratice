package com.itheima.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.filter.CharacterEncodingFilter;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

import javax.servlet.Filter;
import javax.servlet.annotation.WebFilter;

@Configuration
@ComponentScan("com.itheima.controller")
//开启json数据类型自动转换
@EnableWebMvc
public class SpringMvcConfig {

    /*@ResponseBody，@RequestParam和@PathVartable区别
    * 区别:
    *   @RequestParam 用于接受url地址传参，表单传参
    *   @ResponseBody 用于接受json数据
    *   @PathVariable 用于接受路径参数，使用{参数名称}描述路径参数
    * 应用
    *   后期开发中，发送请求参数超过1时，以json格式为主，@RequestBody应用较广
    *   如果发送非json格式数据，选用@RequestParam接收请求参数
    *   采用RESTful进行开发，当参数数量较少时，例如1个，可以采用@PathVariable接受请求路径变量，通常用于传递id值*/


}

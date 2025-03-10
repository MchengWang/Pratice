package com.itheima;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Springboot01QuickstartApplication {

    /*SpringBoot入门程序
    *   1、创建新模块，选择Spring初始化，并配置模块相关基础信息
    *   2、选择当前模块需要使用的技术集
    *   3、开发控制器类
    *   4、运行自动生成的Application类*/
    public static void main(String[] args) {
        /*SpringBoot在创建项目时，采用jar的打包方式
        * SpringBoot的引导类是项目的入口，运行main方法就可以启动项目*/
        SpringApplication.run(Springboot01QuickstartApplication.class, args);
    }

    /*SpringBoot项目快速启动
    *   1、对SpringBoot项目打包（执行Maven构建命令package）
    *   2、执行启动命令 java -jar springboot.jar
    *      注意事项：jar支持命令行启动需要依赖maven插件支持，请确认打包时是否具有SpringBoot对应的maven插件*/

    /*SpringBoot概述
    *   SpringBoot是由Pivotal团队提供的全新框架，其设计目的是用来简化Spring应用的初始搭建以及开发过程
    * Spring程序缺点
    *   配置繁琐
    *   依赖设置繁琐
    * SpringBoot程序优点
    *   自动配置
    *   起步依赖（简化依赖配置）
    *   辅助功能（内置服务器, ......）
    * SpringBoot起步依赖
    *   starter
    *       SpringBoot中常见项目名称，定义了当前项目使用的所有项目坐标，以达到减少依赖配置的目的
    *   parent
    *       所有SpringBoot项目要继承的项目，定义了若干个坐标版本号（依赖管理，而非依赖），以达到减少依赖冲突的目的
    *       spring-boot-starter-parent（2.5.0）与spring-boot-starter-parent（2.4.6）共计57处坐标版本不同
    *   实际开发
    *       使用任意坐标是，仅书写GAV中的G和A，V由SpringBoot提供
    *       如发生坐标错误，在指定version（要小心版本冲突）*/
}

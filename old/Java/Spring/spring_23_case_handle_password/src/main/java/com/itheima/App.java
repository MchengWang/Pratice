package com.itheima;

import com.itheima.config.SpringConfig;
import com.itheima.service.ResourcesService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App {
    public static void main(String[] args) {
        ApplicationContext ctx = new AnnotationConfigApplicationContext(SpringConfig.class);
        ResourcesService resourcesService = ctx.getBean(ResourcesService.class);
        boolean flag = resourcesService.openURL("http://pan.baidu.com/haha", "root ");
        /*1、在业务方法执行之前对所有的 输入参数进行格式处理--trim()
        * 2、使用处理后的参数调用原始方法--环绕通知中存在对原始方法的调用*/
        System.out.println(flag);
    }

}

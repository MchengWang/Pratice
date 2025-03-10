package com.itheima.controller;

import com.itheima.domain.Book;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/books")
public class BookController {
    /*案例：基于RESTful页面数据交互 步骤
    * 1、制作SpringMVC控制器，并通过PostMan测试接口功能
    * 2、设置对静态资源的访问放行
    * 3、前端页面通过异步提交访问后台控制器*/

    @PostMapping
    public String save(@RequestBody Book book){
        System.out.println("book save == >" + book);
        return "{'module' : 'book save success'}";
    }

    @GetMapping
    public List<Book> getAll(){
        System.out.println("book getAll is running ...");
        List<Book> list = new ArrayList<>();

        Book book1 = new Book();
        book1.setType("计算机");
        book1.setName("SpringMVC入门教程");
        book1.setDescription("小试牛刀");

        Book book2 = new Book();
        book2.setType("计算机");
        book2.setName("SpringMVC实战教程");
        book2.setDescription("一代宗师");

        Book book3 = new Book();
        book3.setType("计算机");
        book3.setName("SpringMVC实战教程进阶");
        book3.setDescription("一代宗师呕心创作");

        list.add(book1);
        list.add(book2);
        list.add(book3);
        return list;
    }
}

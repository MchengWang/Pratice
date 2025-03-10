package com.itheima.controller;

import com.itheima.domain.Book;
import com.itheima.domain.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

//@Controller
//@ResponseBody
@RestController
/*@RestController 设置当前控制器类为RESTful风格，等同于@Controller与@ResponseBody两个注解组合功能*/
@RequestMapping("/books")
public class BookController {

    /*@GetMapping @PostMapping @PutMapping @DeleteMapping
    *   设置当前控制器方法请求访问路径与请求动作，每种对应一种请求动作，例如@GetMapping对应GET请求
    * 属性
    *   value(默认)：请求访问路径*/

//    @RequestMapping(method = RequestMethod.POST)
    @PostMapping
    public String save(@RequestBody Book book){
        System.out.println("book save ..." + book);
        return "{'module':'book save'}";
    }

//    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    @DeleteMapping("/{id}")
    /*@PathVariable 绑定路径参数与处理器方法形参间的关系，要求路径参数名与形参名一一对应*/
    public String delete(@PathVariable  Integer id){
        System.out.println("book delete ..." + id);
        return "{'module':'book delete'}";
    }

//    @RequestMapping(method = RequestMethod.PUT)
    @PutMapping
    public String Update(@RequestBody User user){
        System.out.println("book update ..." + user);
        return "{'module':'book update'}";
    }

//    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    @GetMapping("/{id}")
    public String getById(@PathVariable  Integer id){
        System.out.println("book getById ..." + id);
        return "{'module':'book getById'}";
    }

//    @RequestMapping(method = RequestMethod.GET)
    @GetMapping
    public String getAll(){
        System.out.println("book getAll ...");
        return "{'module':'book getAll'}";
    }
}












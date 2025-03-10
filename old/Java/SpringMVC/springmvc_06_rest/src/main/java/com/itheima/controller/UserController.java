package com.itheima.controller;

import com.itheima.domain.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
public class UserController {

    /*REST简介
    * REST(Representational State Transfer),表现形式状态转换
    *   传统风格资源描述形式
    *       http://localhost/user/getById?id=1
    *       http://localhost/user/saveUser
    *   REST风格描述形式
    *       http://localhost/user/1
    *       http://localhost/user
    *   优点
    *       隐藏资源的访问行为，无法通过地址得知对资源是何种操作
    *       书写简化
    * REST风格简介
    *   按照REST风格访问资源时使用行为动作区分对资源进行了何种操作
    *       http://localhost/users              查询全部用户信息 GET(查询)
    *       http://localhost/users/1            查询指定用户信息 GET(查询)
    *       http://localhost/users              添加用户信息 POST(新增/保存)
    *       http://localhost/users              修改用户信息 PUT(修改/更新)
    *       http://localhost/users/1            删除用户信息 DELETE(删除)
    *   根据REST风格对资源进行访问称为RESTful
    *注意事项
    *   上述行为是约定方式，约定不是规范，可以打破，所以称为REST风格，而不是REST规范
    *   描述模块的名称通常使用复数，也就是加s的格式描述，表示此类资源，而非单个资源，例如:users、books、accounts......*/

    /*RESTful 步骤
    *   1、设定http请求动作（动词）
    *   2、设定请求参数（路径变量）*/

    @RequestMapping(value = "//books",method = RequestMethod.POST)
    @ResponseBody
    public String save(){
        System.out.println("user save ...");
        return "{'module':'user save'}";
    }

    /*@RequestMapping 设置当前控制器方法请求访问路径
    *属性
    *   value（默认）：请求访问路径
    *   method：http请求动作，标准动作（GET/POST/PUT/DELETE）*/
    @RequestMapping(value = "//books/{id}", method = RequestMethod.DELETE)
    @ResponseBody
    /*@PathVariable 绑定路径参数与处理器方法形参间的关系，要求路径参数名与形参名一一对应*/
    public String delete(@PathVariable  Integer id){
        System.out.println("user delete ..." + id);
        return "{'module':'user delete'}";
    }

    @RequestMapping(value = "//books", method = RequestMethod.PUT)
    @ResponseBody
    public String Update(@RequestBody User user){
        System.out.println("user update ..." + user);
        return "{'module':'user update'}";
    }

    @RequestMapping(value = "//books/{id}", method = RequestMethod.GET)
    @ResponseBody
    public String getById(@PathVariable  Integer id){
        System.out.println("user getById ..." + id);
        return "{'module':'user getById'}";
    }

    @RequestMapping(value = "//books", method = RequestMethod.GET)
    @ResponseBody
    public String getAll(){
        System.out.println("user getAll ...");
        return "{'module':'user getAll'}";
    }
}












package Summarize.Exception;

import java.lang.module.ResolutionException;
import java.util.Scanner;

public class DemoExceptionCustomExceptionstest {
    /*自定义异常类的练习
         要求：我们模拟注册操作，如果用户名已存在，则抛出异常提示：亲，该用户名已被注册
         分析：1、使用数组保存已经注册的用户名（数据库）
              2、Scanner获取用户输入的注册的用户名（前端，页面）
              3、定义一个方法，对用户输入中注册的用户名进行判断
                 遍历存储已经注册过的用户名的数组，获取每一个用户名
                 使用获取道德用户名和用户输入的用户名比较
                    true 用户名已存在，抛出RegisterException异常，告知用户“亲，该用户名已被注册”
                    false：继续遍历
                    如果循环结束，还没有重复的用户名，提示用户：“恭喜你，注册成功”*/

    //1、使用数组保存已经注册过的用户名（数据库）
    static String[] username = {"张三","李四","王五"};
    public static void main(String[] args) {
        //使用Scanner获取用户输入注册的用户名（前端，页面）
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入你要注册的用户名");
        String s = sc.next();
        method(s);

    }

    public static void method(String name){
        //遍历判断
        for (String s : username) {
            if(name.equals(s)){
                //判断比较是否重复
                try {
                    throw new ResolutionException("亲，该用户名已被注册");
                }catch(ResolutionException r){
                    r.printStackTrace();
                    return ;//结束方法
                }
            }
        }

        //循环结束，好没有找到，提示用户注册成功
        System.out.println("恭喜您，注册成功");
    }
    /*前提为Exception（编译期异常，解决抛出问题）
    * RuntimeException（运行期异常，抛出可以解决可以不解决交给jvm处理）*/
}

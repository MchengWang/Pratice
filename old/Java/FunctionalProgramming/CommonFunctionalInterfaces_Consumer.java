package Summarize.FunctionalProgramming;

import java.util.function.Consumer;

public class CommonFunctionalInterfaces_Consumer {
    /*常用的函数式接口
    * Consumer java.util.function.Consumer<T> 和Supplier<T> 接口相反，即消费一个数据，至于怎么消费，需要自定义（输出，计算。。。）*/

    // 定义一个方法，参数传递一个字符串的姓名，参数传递Consummer接口，泛型使用String
    // 可以使用Consumer接口，消费字符串的姓名

    public static void method(String name , Consumer<String> con){
        con.accept(name);
    }

    public static void main(String[] args) {
        // 调用method方法，传递字符串姓名，另一参数是Consumer接口，是一个函数式接口，所以传递lambda表达式
        method("胡歌" , (String name) ->{
            // 对传递的字符串进行消费
            // System.out.println(name); // 消费方式，直接输出
            // 消费方式，把字符串反转输出
            String reName = new StringBuffer(name).reverse().toString();
            System.out.println(reName);
        });
    }
}

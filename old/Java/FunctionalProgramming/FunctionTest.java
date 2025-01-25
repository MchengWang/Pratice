package Summarize.FunctionalProgramming;

import java.util.function.Function;

public class FunctionTest {
    /*Function接口练习，自定义函数模型拼接
    *   1.截取年龄部分，得到字符串
    *   2.将上字符串转换为int数字
    *   3.将int数字+100，得int数*/

    /*定义一个方法，参数传递，包含姓名，年龄字符串，再传3个Function接口，用于类型转换*/

    public static int change(String s , Function<String , String> fun1 , Function<String , Integer> fun2
            , Function<Integer , Integer> fun3){
        // 使用andThen方法把三个组合在一起
        return fun1.andThen(fun2).andThen(fun3).apply(s);
    }

    public static void main(String[] args) {
        // 定义一个字符串
        String str = "胡歌,35";
        // 调用change方法，vans胡传递字符串和3个lambda表达式
        /*int i = change(str , s -> return str.split(",") , s -> return Integer.parseInt(str) ,
        i -> return i + 100);
        System.out.println(i);*/
    }
}

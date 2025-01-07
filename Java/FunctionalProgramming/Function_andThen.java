package Summarize.FunctionalProgramming;

import java.util.function.Function;

public class Function_andThen {
    /*Function_andThen 组合操作
    *   需求：把String类型的”123“转换为Integer类型，把转换后的结果加10，把增加之后Integer类型数据，转换为
    * String类型
    * 分析：转换了两次 String -> Integer 可以使用Function转换<String , Integer> fun1
    *               Integer in = fun1.apply("123") + 10
    *               Integer -> String Function<Integer , String> fun2
    *               String s = fun2.apply(in)
    * 可以使用andThen，把两次组合在一块使用
    *   fun1.andThen(fun2).apply("123");
    * fun1 先调用apply String->Integer
    * fun2 后调用apply Integer -> String*/

    /*示例：定义一个方法，参数一个字符串类型整数，两个Function接口，泛型使用<String , Integer><Integer , String>*/
    public static void change(String s , Function<String , Integer> fun1 , Function<Integer , String> fun2){
        String ss = fun1.andThen(fun2).apply(s);
        System.out.println(ss);
    }

    public static void main(String[] args) {
        // 定义一个字符串类型的整数
        String s = "123";
        // 调用change方法，传递字符串和两个lambda表达式
        change(s , str -> Integer.parseInt(str) + 10 , i -> i + "");
    }
}

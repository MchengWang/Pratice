package Summarize.FunctionalProgramming;

import java.util.function.Function;

public class CommonFunctionalInterfaces_Function {
    /*Function接口
    *   java.util.function.Function<T,R> 用来根据一个数组类型的到另一个类型的数组，前者成为前置条件，后者成为后置条件
    * 抽象方法 apply
    *   R apply(T t)  根据类型的参数获取类型R的结果*/

    /*定义一个方法，参数传递一个Function接口，方法参数传递一个字符串，方法参数传递一个Function接口泛型使用<String ， Integer>
    * 使用Function接口中的方法apply，把字符串中类型转换为Integer类型的整数*/

    public static void change(String s , Function<String , Integer> fun){
        Integer in = fun.apply(s);
        System.out.println(in);
    }

    public static void main(String[] args) {
        // 定义一个字符串类型整数
        String s = "1234";
        // 调用change方法，传递字符串类型整数和lambda表达式
        change(s , str -> Integer.parseInt(s));
    }
}

package Summarize.FunctionalProgramming;

import java.util.function.Predicate;

public class CommonFunctionalInterfaces_Predicate {
    /*常用函数式接口 Predicate接口 java.util.function.Predicate<T> 对某种数据类型的数据进行判断，返回布尔值
    * Predicate中包含一个抽象方法
    * boolean test(T t):用于判断指定数据类型的数据进行判断的方法
    * 结果 符合 true 不符合 false*/

    /**
     * 定义一个方法，参数传递String类型字符串
     * 传递一个Predicate接口，泛型使用string
     * 使用Predicate中的方法test对字符串进行判断，并把结果返回
     * @param s
     * @param pre
     * @return
     */
    public  static boolean checkString(String s , Predicate<String> pre){
        return pre.test(s);
    }

    public static void main(String[] args) {
        // 定义一个字符串
        String s = "abc";
        // 调用checkString对字符串校验，参数传递字符串和lambda表达式
        boolean b = checkString(s , (String str) -> {
            // 对参数传递的字符串进行判断，判断字符串长度是否大于5，并把结果返回
            return str.length() > 5;
        });

        System.out.println(b);
    }
}

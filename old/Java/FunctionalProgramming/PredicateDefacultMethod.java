package Summarize.FunctionalProgramming;

import java.util.function.Predicate;

public class PredicateDefacultMethod {
    /*Predicate接口默认方法and
    * 逻辑表达式：可以连接多个判断条件
    * && 与 有false则false
    * || 或 有true则true
    * ！ 非 非真即假 ， 非假即真*/

    public static void main(String[] args) {
        // 定义一个字符串
        String s = "abcdef";
        // 调用checkString方法
        boolean b = checkString(s , (String str) -> {
            return str.length() > 5;
        } , (String str) -> {
            return str.contains("a");
        });
        System.out.println(b);
    }

    /*需求：判断一个字符串，有两个判断的条件
    *   1.判断长度是否大于5
    *   2.判断字符串中是否包含a
    * 两个条件必须同时满足，我们就可以使用&&连接两个事件
    *
    * Predicate接口中有一个方法and，表示并且关系，也可以用于连接两个判断条件
    * default Predicate<T> and(Predicate<? super T> other) {
        Objects.requireNonNull(other);
        return (t) -> test(t) && other.test(t);
    } 方法内部的连个条件，也是用&&连接起来的*/

    /*Predicate-or或-Negate非
    * or源码default Predicate<T> or(Predicate<? super T> other) {
        Objects.requireNonNull(other);
        return (t) -> test(t) || other.test(t);
    }*/

    public static boolean checkString(String s , Predicate<String> pre1 , Predicate<String> pre2) {
        // return pre1.test(s) && pre2.test(s);
        // return pre1.and(pre2).test(s);
        // return pre1.test(s) || pre2.test(s);
        return pre1.or(pre2).test(s);
    }

    public static boolean checkString(String s , Predicate<String> pre) {
        // return !pre.test(s);
        return pre.negate().test(s);
    }
}

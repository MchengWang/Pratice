package Summarize.Exception;

import java.util.Objects;

public class DemoExceptionObjectNotNull {
    /*static <T> T	requireNonNull​(T obj) 检查指定的对象引用不是 。null*/
    public static void method(Object obj){
        //对传递的参数进行合法性判断，判断是否为null
        if(obj == null){
            throw new NullPointerException("传递的参数值为null");
        }

        Objects.requireNonNull(obj);//会进行判断
        Objects.requireNonNull(obj ,"传递的对象值为null");//重载
    }
}

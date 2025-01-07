package Summarize.FunctionalProgramming;

import java.util.Locale;
import java.util.function.Consumer;

public class ConsumerDefaultMethod {
    /*Consumer中的默认方法andThen
    *   作用：需两个Consumer接口，把两个
    * Consumer<String> con1 Consumer<String> con2
    * String s = "Hello" con1.accept(s) con2.accept(s)
    * con1.andThen(con2).accept(s) // 连接两个Consumer接口，再进行消费，谁写前，谁先消费*/

    public static void method(String s, Consumer<String> con1 , Consumer<String> con2){
        // 使用andThen
        con1.andThen(con2).accept(s); // con1连接con2，先执行con1，在执行con2
    }

    public static void  printInfo(String[] arr , Consumer<String> con1 , Consumer<String> con2){
        // 遍历字符串数组
        for (String messsage : arr) {
            // 使用andThen来凝结两个Consumer接口，消费字符串
            con1.andThen(con2).accept(messsage);
        }
    }

    public static void main(String[] args) {
        method("Hello" , (t)->{
            // 消费方式,把字符串转换为大写输出
            System.out.println(t.toUpperCase()); // HELLO
        },
            (t)->{
            //消费方式：把字符串转化为小写输出
                System.out.println(t.toLowerCase()); // hello
            });

        // 定义一个字符串数组
        String[] arr = {"迪丽热巴" , "女" , "古力娜扎" , "女" , "马尔扎哈" , "男"};
        // 调用printInfo方法，传递一个字符串和两个lambda表达式
        printInfo(arr , (message) -> {
            // 消费方式：对message进行切割。获取姓名，按照指定格式输出
            String name = message.split(",")[0];
            System.out.println("姓名" + name);
        },(message) -> {
            // 消费方式：对message进行切割。获取性别，按照指定格式输出
            String sex = message.split(",")[1];
            System.out.println("姓名" + sex);
        });
    }
}

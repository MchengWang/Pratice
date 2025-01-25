package Summarize.FunctionalProgramming;

import java.util.ArrayList;
import java.util.function.Predicate;

public class InformationFiltering {
    /*信息筛选
    *   数组中有多条”姓名+性别“的信息如下：
    *   String[] arr = {"迪丽热巴" , "女" , "古力娜扎" , "女" , "马尔扎哈" , "男" , "胡歌" , "男"}
    *   请通过Predicate接口的拼接符合要求的字符串筛选到ArrayList中
    *   需要同时满足两个条件
    *       1.必须为女生
    *       2.姓名长度为4个
    * 分析：
    *   1.定义一个方法参数传递一个字符串，两个Predicate接口（因为有两个判断条件）
    *   2.必须同时满足，所以可以使用and方法连接两个判断条件
    *   传递两个Predicate接口，用于对数据中的信息并过滤
    *   把满足条件的信息存在ArrayList中并返回*/

    public static ArrayList<String> filter(String[] arr , Predicate<String> pre1 , Predicate<String> pre2){
        // 定义一个ArrayList集合存储过滤之后的数据
        ArrayList<String> list = new ArrayList<>();
        // 遍历数组，获取数组中的每一条信息
        for (String s : arr) {
            // 使用Predicate接口中的方法test对获取的字符串进行判断
            boolean b = pre1.and(pre2).test(s);
            // 对布尔值进行判断
            if (b){
                // 条件成立，两个条件都满足，把信息存储到ArrayList集合中
                list.add(s);
            }
        }
        return list;
    }

    public static void main(String[] args) {
        // 定义一个存储字符串的数组
        String[] arr = {"迪丽热巴" , "女" , "古力娜扎" , "女" , "马尔扎哈" , "男" , "胡歌" , "男"};
        // 调用filter方法，传递字符串数组和两个lambda表达式
        ArrayList<String> list = filter(arr , (String s) -> {
            // 获取字符串中的性别，判断是否为女
            return s.split(",")[0].equals("女");
        } , (String s) -> {
            // 获取字符串中的姓名，判断长度是否为4个字符
            return s.split(",")[0].length() == 4;
        });
        // 遍历集合
        for (String s : list) {
            System.out.println(s);
        }
    }
}

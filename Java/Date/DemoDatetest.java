package Summarize.Date;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class DemoDatetest {
    /*练习：使用日期和相关API，计算一个人已经出生多少天
    分析：
    1、使用Scanner类中的方法next获取当天日期
    2、使用DateFormat类中的方法parse，把字符串的出生日期解析为Date格式
    3、把Date格式的出生日期转换为毫秒值
    4、获取当前日期毫秒值
    5、使用当前毫秒值—出生日期毫秒值
    6、把毫秒值转化为天（秒/1000/60，60/24）*/

    public static void main(String[] args) throws ParseException {
        //1、使用Scanner类中的方法next获取当天日期
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入你的生日 格式为yyyy-MM-dd ");
        String a = sc.next();
        //2、使用DateFormat类中的方法parse，把字符串的出生日期解析为Date格式
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        Date d1 = sdf.parse(a);
        //3、把Date格式的出生日期转换为毫秒值
        long t1 = d1.getTime();
        //4、获取当前日期毫秒值
        long day = new Date().getTime();
        //5、使用当前毫秒值—出生日期毫秒值
        long l = day - t1;
        //6、把毫秒值转化为年（秒/1000/6060/24/365）
        System.out.println(l/1000/60/60/24/365+"年");
    }
}

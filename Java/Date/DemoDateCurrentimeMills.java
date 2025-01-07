package Summarize.Date;

import java.util.Date;

public class DemoDateCurrentimeMills {
    public static void main(String[] args) {
        //long start = System.currentTimeMillis();
        /*Date类
        作用：可以对时间和日期进行计算*/
        System.out.println(System.currentTimeMillis());//获取当前系统到1970年1月1日00：00：00经历了多少毫秒
        //注意，中国属于东八区，会把时间增加8个小时

        //Date()  分配 Date 对象并初始化此对象，以表示分配它的时间（精确到毫秒）。
        Date d1 = new Date();
        System.out.println(d1);

        //Date(long date)  分配 Date 对象并初始化此对象，以表示自从标准基准时间（称为“历元（epoch）”，
        // 即 1970 年 1 月 1 日 00:00:00 GMT）以来的指定毫秒数。
        Date d2 = new Date(02);
        System.out.println(d2);

        // long getTime()  返回自 1970 年 1 月 1 日 00:00:00 GMT 以来此 Date 对象表示的毫秒数。
        Date d3 = new Date();
        long time = d3.getTime();
        System.out.println(time);

        //System.out.println(System.currentTimeMillis() - start);
    }
}

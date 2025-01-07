package Summarize.Calendar;

import java.util.Calendar;
import java.util.Date;

public class DemoCalendartest {
    /*Calendar类是一个日历抽象类
    Calendar类提供了很多操作日历字段的方法（YEAR , MOUTH , DAY_OF_MOUTH , HOUR）
    Calendar无法直接创建对象，里面有一个静态方法getInstance()返回了Calenter类的子类对象
    */
    public static void main(String[] args) {
        /*static Calendar getInstance() 使用默认时区和语言环境获得一个日历。
        static Calendar getInstance(Locale aLocale) 使用默认时区和指定语言环境获得一个日历。
        static Calendar getInstance(TimeZone zone) 使用指定时区和默认语言环境获得一个日历。
        static Calendar getInstance(TimeZone zone, Locale aLocale) 使用指定时区和语言环境获得一个日历。*/
        Calendar c = Calendar.getInstance();//多态
        System.out.println(c);

        /*Calendar类的成员方法
        int get(int field) 返回给定日历字段的值。
        void set(int field, int value) 将给定的日历字段设置为给定值。
        void set(int year, int month, int date) 设置日历字段 YEAR、MONTH 和 DAY_OF_MONTH 的值。
        void set(int year, int month, int date, int hourOfDay, int minute) 设置日历字段 YEAR、MONTH、DAY_OF_MONTH、HOUR_OF_DAY 和 MINUTE 的值。
        void set(int year, int month, int date, int hourOfDay, int minute, int second) 设置字段 YEAR、MONTH、DAY_OF_MONTH、HOUR、MINUTE 和 SECOND 的值。
        Date getTime() 返回一个表示此 Calendar 时间值（从历元至现在的毫秒偏移量）的 Date 对象。
        abstract  void add(int field, int amount) 根据日历的规则，为给定的日历字段添加或减去指定的时间量。
        成员参数：int field 日历类的字段，指定的，YEAR,MOUTH,DATE,DATE_OF_MOUTH*/
        //使用get方法
        Calendar Cal1 = Calendar.getInstance();
        int year = Cal1.get(Calendar.YEAR);
        System.out.println(year);

        //使用set方法
        Cal1.set(Calendar.YEAR ,1999);
        int year1 = Cal1.get(Calendar.YEAR);
        System.out.println(year1);

        //使用add方法
        Cal1.add(Calendar.YEAR , 2);
        int year2 = Cal1.get(Calendar.YEAR);
        System.out.println(year2);

        //使用getTime方法
        Date date = Cal1.getTime();
        System.out.println(date);

    }
}

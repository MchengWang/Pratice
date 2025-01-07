package Summarize.Date;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.Date;

public class DemoLocalDate {
   /* 3.1、JDK7 Date缺点

        1、所有的日期类都是可变的，因此他们都不是线程安全的，这是Java日期类最大的问题之一

        2、Java的日期/时间类的定义并不一致，在java.util和java.sql的包中都有日期类，此外用于格式化和解析的类在java.text包中定义

        3、java.util.Date同时包含日期和时间，而java.sql.Date仅包含日期，将其纳入java.sql包并不合理。另外这两个类都有相同的名字，这本身就是一个非常糟糕的设计。
        对于时间、时间戳、格式化以及解析，并没有一些明确定义的类。对于格式化和解析的需求，我们有java.text.DateFormat抽象类，但通常情况下，
        SimpleDateFormat类被用于此类需求

        4、日期类并不提供国际化，没有时区支持，因此Java引入了java.util.Calendar和java.util.TimeZone类，但他们同样存在上述所有的问题
    3.2、JDK8 Date优势

        1、不变性：新的日期/时间API中，所有的类都是不可变的，这对多线程环境有好处。

        2、关注点分离：新的API将人可读的日期时间和机器时间（unix timestamp）明确分离，它为日期（Date）、
            时间（Time）、日期时间（DateTime）、时间戳（unix timestamp）以及时区定义了不同的类。

        3、清晰：在所有的类中，方法都被明确定义用以完成相同的行为。举个例子，要拿到当前实例我们可以使用now()方法，在所有的类中都定义了format()和parse()方法，
        而不是像以前那样专门有一个独立的类。为了更好的处理问题，所有的类都使用了工厂模式和策略模式，一旦你使用了其中某个类的方法，与其他类协同工作并不困难。

        4、实用操作：所有新的日期/时间API类都实现了一系列方法用以完成通用的任务，如：加、减、格式化、解析、从日期/时间中提取单独部分，等等。

        5、可扩展性：新的日期/时间API是工作在ISO-8601日历系统上的，但我们也可以将其应用在非IOS的日历上。
    3.3、JDK8 Date新增字段

      Java.time包中的是类是不可变且线程安全的。新的时间及日期API位于java.time中，java8 time包下关键字段解读。
        属性	                含义
        Instant	            代表的是时间戳
        LocalDate	        代表日期，比如2020-01-14
        LocalTime	        代表时刻，比如12:59:59
        LocalDateTime	    代表具体时间 2020-01-12 12:22:26
        ZonedDateTime	    代表一个包含时区的完整的日期时间，偏移量是以UTC/  格林威治时间为基准的
        Period	            代表时间段
        ZoneOffset	        代表时区偏移量，比如：+8:00
        Clock	            代表时钟，比如获取目前美国纽约的时间
        */

    public static void main(String[] args) {
        //3.4、获取当前时间

        Instant instant = Instant.now(); //获取当前时间戳

        LocalDate localDate = LocalDate.now();  //获取当前日期

        LocalTime localTime = LocalTime.now();  //获取当前时刻

        LocalDateTime localDateTime = LocalDateTime.now();  //获取当前具体时间

        ZonedDateTime zonedDateTime = ZonedDateTime.now();   //获取带有时区的时间

        //3.5、字符串转换

        //jdk8：
        String str = "2019-01-11";//设置字符串
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");//设置时间的转化格式
        LocalDate localDate1 = LocalDate.parse(str, formatter);//把str按照formatter的格式转化为时间日期对象
        System.out.println(localDate1);//2019-01-11

        //jdk7:
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");//设置时间的转化格式
        try {
            Date date = simpleDateFormat.parse(str);//按照格式将str转化为时间
            System.out.println(date);//Fri Jan 11 00:00:00 GMT+08:00 2019
        } catch (ParseException e){
            e.printStackTrace();
        }
       // 3.6、Date转换LocalDate

        Date date = new Date();
        Instant instant1 = date.toInstant();
        ZoneId zoneId = ZoneId.systemDefault();

        // atZone()方法返回在指定时区从此Instant生成的ZonedDateTime。
        LocalDate localDate2 = instant.atZone(zoneId).toLocalDate();
        System.out.println("Date = " + date); //Date = Mon Apr 12 10:59:19 GMT+08:00 2021
        System.out.println("LocalDate = " + localDate);//LocalDate = 2021-04-12
        //3.7、LocalDate转Date
        ZoneId zoneId1 = ZoneId.systemDefault();
        LocalDate localDate3 = LocalDate.now();
        ZonedDateTime zdt = localDate.atStartOfDay(zoneId);

        Date date2 = Date.from(zdt.toInstant());

        System.out.println("LocalDate = " + localDate);//LocalDate = 2021-04-12
        System.out.println("Date = " + date); //Date = Mon Apr 12 10:59:19 GMT+08:00 2021
        //3.8、时间戳转LocalDateTime

        long timestamp = System.currentTimeMillis();

        Instant instant2 = Instant.ofEpochMilli(timestamp);

        LocalDateTime.ofInstant(instant, ZoneId.systemDefault());

        //3.9、LocalDateTime转时间戳

        LocalDateTime dateTime = LocalDateTime.now();

        dateTime.toInstant(ZoneOffset.ofHours(8)).toEpochMilli();

        dateTime.toInstant(ZoneOffset.of("+08:00")).toEpochMilli();

        dateTime.atZone(ZoneId.systemDefault()).toInstant().toEpochMilli();

       /*3.10、LocalDate方法总结

        getYear()                         int        获取当前日期的年份
        getMonth()                        Month      获取当前日期的月份对象
        getMonthValue()                   int        获取当前日期是第几月
        getDayOfWeek()                    DayOfWeek  表示该对象表示的日期是星期几
        getDayOfMonth()                   int        表示该对象表示的日期是这个月第几天
        getDayOfYear()                    int        表示该对象表示的日期是今年第几天
        withYear(int year)                LocalDate  修改当前对象的年份
        withMonth(int month)              LocalDate  修改当前对象的月份
        withDayOfMonth(intdayOfMonth)     LocalDate  修改当前对象在当月的日期
        isLeapYear()                      boolean    是否是闰年
        lengthOfMonth()                   int        这个月有多少天
        lengthOfYear()                    int        该对象表示的年份有多少天（365或者366）
        plusYears(longyearsToAdd)         LocalDate  当前对象增加指定的年份数
        plusMonths(longmonthsToAdd)       LocalDate  当前对象增加指定的月份数
        plusWeeks(longweeksToAdd)         LocalDate  当前对象增加指定的周数
        plusDays(longdaysToAdd)           LocalDate  当前对象增加指定的天数
        minusYears(longyearsToSubtract)   LocalDate  当前对象减去指定的年数
        minusMonths(longmonthsToSubtract) LocalDate  当前对象减去注定的月数
        minusWeeks(longweeksToSubtract)   LocalDate  当前对象减去指定的周数
        minusDays(longdaysToSubtract)     LocalDate  当前对象减去指定的天数
        compareTo(ChronoLocalDateother)   int        比较当前对象和other对象在时间上的大小，返回值如果为正，则当前对象时间较晚，
        isBefore(ChronoLocalDateother)    boolean    比较当前对象日期是否在other对象日期之前
        isAfter(ChronoLocalDateother)     boolean    比较当前对象日期是否在other对象日期之后
        isEqual(ChronoLocalDateother)     boolean    比较两个日期对象是否相等*/
    }
}

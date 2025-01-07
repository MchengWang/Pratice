package Summarize.Date;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DemoDateDateFormat {
    /*DateFormat类 是日期/时间格式化子类的抽象类，即Date对象和String对象之间来回转换
    格式化 日期-->文本 解析 文本-->日期
    成员方法：
    String format(Date date)  将一个 Date 格式化为日期/时间字符串。
    Date parse(String source)  从给定字符串的开始解析文本，以生成一个日期。
    注意：此类为抽象类，无法直接创建对象使用，可以使用DateFormat的子类
    SimpleDateFormat extends DateFormat
    构造方法：SimpleDateFormat(String pattern)用给定的模式和默认语言环境的日期格式符号构造 SimpleDateFormat。
        参数 String pattern ：传递指定的模式
        模式区分大小写 年（y） 月（M） 日（d） 时（H） 分（m） 秒（s）
        写对应的模式，会把模式替换为对应的日期和时间
        两种格式 ：
        1、yyyy-MM-dd HH:mm:ss
        2、yyyy年MM月dd日 HH时mm分ss秒
        注意：模式中的字母不能更改，连续模式的符号可以改*/
    public static void main(String[] args)  {
        Date date = new Date();
        /*DateFormat类中的format方法
         String format(Date date) 将一个 Date 格式化为日期/时间字符串。
         使用步骤
         1、创建SimDateformat对象，构造方法中传递指定的模式
         2、调用SimpleDateFormat按照指定的模式，把Date日期格式化为符合模式的字符串文本*/
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        System.out.println(sdf.format(date.getTime()));//2020-07-17 16:40:23

        /*使用DateFormat类中的parse方法
        Date parse(String source) 从给定字符串的开始解析文本，以生成一个日期。
        使用步骤：
        1、创建SimDateformat对象，构造方法中传递指定的模式
        2、调用SimpleDateFormat类中的方法parse，把符合构造方法中的模式的字符串解析为Date日期
        注意：
        1、parse方法声明了一个异常叫ParseException 解析异常
        2、如果字符串和构造方法中的模式不一样，那么程序就会抛出异常
        3、调用一个抛出异常的方法，就必须处理这个异常，要么throw派出一个异常，要么try...catch自己处理这个异常*/

        Date d1 = null;
        try {
            d1 = sdf.parse("2020-07-17 16:47:28");
        } catch (ParseException e) {
            e.printStackTrace();
        }
        System.out.println(d1);
    }
}

package Summarize.String;

import java.util.Date;

public class DomeString {
    public static void main(String[] args) {
        /*获取指定索引处的字符
         char charAt(int index)返回指定索引处的 char 值。*/
        String a = "peter";
        System.out.println(a.charAt(4));//字符串中索引为4的字符：r

       /* 获取子字符串
         int indexOf(String str)返回指定子字符串在此字符串中第一次出现处的索引。
         int indexOf(String str, int fromIndex)返回指定子字符串在此字符串中第一次出现处的索引，从指定的索引开始。*/
        String  b = "ihfuadsbgayukhfashjdfbakhf";
        int c = b.indexOf("f");//获取f第一次出现的索引：2
        System.out.println(c);
        int d = b.indexOf("f",3);//从索引为3的字符（包括索引为3）往后获取f的索引：14
        System.out.println(d);

        //获取字符的索引值
       /* int lastIndexOf(String str) 返回指定子字符串在此字符串中最右边出现处的索引。
         int lastIndexOf(String str, int fromIndex)返回指定子字符串在此字符串中最后一次出现处的索引，从指定的索引开始反向搜索。*/
        int e = b.lastIndexOf("h");//获取最后一次出现h的索引：24
        System.out.println(e);
        int f = b.lastIndexOf("h",14);//从索引为0-14之间获取最后一次出现h的索引
        System.out.println(f);

       /* 从身份证截取出生日期
          String substring(int beginIndex)返回一个新的字符串，它是此字符串的一个子字符串。
          String substring(int beginIndex, int endIndex)返回一个新字符串，它是此字符串的一个子字符串。*/
        String g = "332102202007070521";
        String h = g.substring(6,14);//从索引范围为6-24之间获取字符(包括6和24)
        System.out.println(h);

        /*获取字符串i的长度
         int length() 返回此字符串的长度。*/
        String i = "hduasgbkajsgfkuasdjhbgvhjkasdvfhjk";
        System.out.println(i.length());

        /*判断未见后缀名是否为.java
         boolean endsWith(String suffix) 测试此字符串是否以指定的后缀结束。*/
        String j = "ashfa.javc";
        System.out.println(j.endsWith(".java"));//正确：true 错误：false

        /*判断句首内容是否为147
         boolean startsWith(String prefix) 测试此字符串是否以指定的前缀开始。
         boolean startsWith(String prefix, int toffset)  测试此字符串从指定索引开始的子字符串是否以指定前缀开始。*/
        String k = "147ahg.java";
        System.out.println(k.startsWith("147"));//正确：true 错误：false

       /* 判断用户是否存在
         boolean equals(Object anObject) 将此字符串与指定的对象比较。*/
        String l = "afh";
        String m = "afh";
        System.out.println(l.equals(m));//正确：true 错误：false

      /*  忽略大小写对比
         boolean equalsIgnoreCase(String anotherString)将此 String 与另一个 String 比较，不考虑大小写。*/
        String n = "asdfg";
        String o = "ASDFG";
        System.out.println(n.equalsIgnoreCase(o));//正确：true 错误：false

       /* 去除首尾空格
         String trim() 返回字符串的副本，忽略前导空白和尾部空白。*/
        String p = "  asin   ";
        System.out.println(p.trim());//asin

       /* 去除字符串中所有的空格
         String replaceAll(String regex, String replacement) 使用给定的 replacement 替换此字符串所有匹配给定的正则表达式的子字符串。*/
        String q = " d af  jh d";//dafjhd
        System.out.println(q.replaceAll("\\s",""));//"\\s"为转换符，“”为转换格式

        //字符串的格式化
      /* static String format(Locale l, String format, Object... args) 使用指定的语言环境、格式字符串和参数返回一个格式化字符串。
        static String format(String format, Object... args) 使用指定的格式字符串和参数返回一个格式化字符串。*/
        String str=String.format("Hi,%s", "飞龙");
        System.out.println(str);

       /* PrintStream printf(Locale l, String format, Object... args)使用指定格式字符串和参数将格式化的字符串写入此输出流的便捷方法。
        PrintStream printf(String format, Object... args)使用指定格式字符串和参数将格式化的字符串写入此输出流的便捷方法。*/
        Date date=new Date();                     // 创建日期对象
        System.out.printf("全部日期和时间信息：%tc%n",date);                // 格式化输出日期或时间
        System.out.printf("年-月-日格式：%tF%n",date);
        System.out.printf("月/日/年格式：%tD%n",date);
        System.out.printf("HH:MM:SS PM格式（12时制）：%tr%n",date);
        System.out.printf("HH:MM:SS格式（24时制）：%tT%n",date);
        System.out.printf("HH:MM格式（24时制）：%tR",date);
        System.out.println();

       /* String[] split(String regex)根据给定正则表达式的匹配拆分此字符串。
        String[] split(String regex, int limit)根据匹配给定的正则表达式来拆分此字符串。*/
        String huu = "192.168.0.1";
        String[] chararray = huu .split("\\.");
        String[] Stringarray = huu.split("\\.",2);
        System.out.println(chararray.toString());
        System.out.println(Stringarray.toString());

        //替换字符方法
       /* String replace(char oldChar, char newChar)返回一个新的字符串，它是通过用 newChar 替换此字符串中出现的所有 oldChar 得到的。
        String replace(CharSequence target, CharSequence replacement)使用指定的字面值替换序列替换此字符串所有匹配字面值目标序列的子字符串。
        String replaceAll(String regex, String replacement)使用给定的 replacement 替换此字符串所有匹配给定的正则表达式的子字符串。
        String replaceFirst(String regex, String replacement)使用给定的 replacement 替换此字符串匹配给定的正则表达式的第一个子字符串。*/
        String gu = "angaagagjkhjkf";
        gu.replace('a','d');
        System.out.println(gu);

        //字符串大小写转换
        /*String toLowerCase()使用默认语言环境的规则将此 String 中的所有字符都转换为小写。
        String toLowerCase(Locale locale)使用给定 Locale 的规则将此 String 中的所有字符都转换为小写。
        String toUpperCase()使用默认语言环境的规则将此 String 中的所有字符都转换为大写。
        String toUpperCase(Locale locale)使用给定 Locale 的规则将此 String 中的所有字符都转换为大写。*/
        String  hi = "fdsga";
        System.out.println(hi.toUpperCase());


    }
}

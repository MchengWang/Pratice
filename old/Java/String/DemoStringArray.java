package Summarize.String;

import java.util.Scanner;

public class DemoStringArray {
    public static void main(String[] args) {
        //空参构造
        String str1 = new String();
        System.out.println(str1);

        //根据字符数组
        char[] charArray = {'A','B','C','D'};
        String str2 = new String(charArray);
        System.out.println(str2);

        //根据字节数组
        byte[] byteArray = {97,98,99};
        String str3 = new String(byteArray);
        System.out.println(str3);

        //直接创建
        String str4 = "Hello";
        System.out.println(str4);

        //创建字符串组
        String[] str = new String[]{"胡歌","宋智孝","李沁","古力娜扎","刘诗诗"};

        //获取字符串长度
        // int length() 返回此字符串的长度。
        System.out.println(str.length);

        //拼接字符串
        // String concat(String str) 将指定字符串连接到此字符串的结尾。
        String str5 = ",杨幂";
        String str6 = str4.concat(str5);
        System.out.println(str6);

        //获取指定位置的单个字符
        // char charAt(int index) 返回指定索引处的 char 值。
        char a = str5.charAt(0);
        System.out.println(a);

        //查找参数
       /* int indexOf(int ch) 返回指定字符在此字符串中第一次出现处的索引。
        int indexOf(int ch, int fromIndex) 返回在此字符串中第一次出现指定字符处的索引，从指定的索引开始搜索。
        int indexOf(String str) 返回指定子字符串在此字符串中第一次出现处的索引。
        int indexOf(String str, int fromIndex) 返回指定子字符串在此字符串中第一次出现处的索引，从指定的索引开始。*/
        int b = str5.indexOf(",");
        System.out.println(b);

        //字符串转换相关方法
        //String --> char
        String a1 = "Hello world";
        char[] charArray1 = a1.toCharArray();
        System.out.println(charArray1);

        //String --> byte
        byte[] byteArray1 = a1.getBytes();
        System.out.println(byteArray1);

        //统计输入的字符串和字符个数
        int ENGLISH = 0;//定义大写字母的数量
        int english = 0;//定义小写字母的数量
        int number = 0;//定义数字的数量
        int other = 0;//定义其他字符的数量
        System.out.println("请输入一串字符");
        String a2 = new Scanner(System.in).next();//定义输出的交互语句Scanner，由于只需要用一次，可以省略创建对象
        char[] charArray3 = a2.toCharArray();
        for (char c : charArray3) {
            if('A'<=c && c>='Z'){
                ENGLISH++;
            }else if('a'<=c && c>='z'){
                english++;
            }else if('0'<=c && c>='9'){
                number++;
            }else{
                other++;
            }
        }
        System.out.println(charArray3.length);
        System.out.println("大写字符有："+ENGLISH);
        System.out.println("小写字符有："+english);
        System.out.println("数字有："+number);
        System.out.println("其他字符有："+other);
    }
}

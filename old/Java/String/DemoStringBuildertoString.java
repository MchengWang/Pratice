package Summarize.String;

public class DemoStringBuildertoString {
    /*
    String --> StringBuilder 可以使用StringBuilder类的方法
    StringBuilder(String str) 构造一个字符串生成器，并初始化为指定的字符串内容。
    StringBuilder --> Stirng 可以使用toString方法
    public String toString();将当前Stringbuilder对象转化为String对象*/
    public static void main(String[] args) {
        // String --> StringBuilder
        String str = "abc";
        System.out.println("str:"+str);
        StringBuilder bu = new StringBuilder(str);
        //往StringBuilder中添加数据
        bu.append("Hello");
        System.out.println("bu:"+bu);
        //StringBuilder --> Stirng
        String str2 = bu.toString();
        System.out.println("str2:"+str2);
    }
}

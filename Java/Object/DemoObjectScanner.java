package Summarize.Object;

import java.util.Scanner;

public class DemoObjectScanner {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("请输入任意字符");
        String a = sc.next();
        //如果sc只调用一次，可以简写为String a = new Scanner(System.in).next();
        if("你好".equals(a)){
            System.out.println("Hello world");
        }

        //使用匿名对象进行传承
        method(new Scanner(System.in));
    }

    public static void method(Scanner sc){
        int a = sc.nextInt(10);
        System.out.println(a);
    }
}

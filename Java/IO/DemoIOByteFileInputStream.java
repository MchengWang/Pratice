package Summarize.IO;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;

public class DemoIOByteFileInputStream {
    /*java.Io.InputStream自己输入流 定义了所有子类共性的方法
        abstract int	read()	从输入流读取下一个字节的数据。
        int	read​(byte[] b)	从输入流读取一些字节，并将它们存储到缓冲区数组中。b
        void	close()	关闭此输入流并释放与流关联的任何系统资源。
    java.Io.FileInputStream extends InputStream
    FileInputStream：文件字节输入流
    作用：把硬盘文件中的数据，读取到内存中使用
    构造方法：
        FileInputStream​(File file)	通过打开与实际文件的连接（由文件系统中的对象命名的文件）创建 。FileInputStreamFilefile
        FileInputStream​(String name)	通过打开与实际文件的连接（由文件系统中的路径名称命名的文件）创建 。FileInputStreamname
    参数：读取文件的数据源
       String name:文件的路径         File file：文件
    构造方法的作用
       1、会创建一个FileInputStream对象
       2、会把FileInputStream对象指定构造方法中要读取的文件
    字节输入流读取字节数组
      读取字节数据的原理（硬盘--> 内存）
      java程序-->jvm（java虚拟机）-->os（操作系统）-->os调用读取数据的方法-->读取文件
    字节输入流的使用步骤（重点）：
      1、创建FileInputStream对象，构造方法中绑定要读取的数据源
      2、使用FileInputStream对象中的方法read读取文件
      3、释放资源*/
    public static void main(String[] args) throws IOException {

        //1、创建FileInputStream对象，构造方法中绑定要读取的数据源
        FileInputStream fis = new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");

        //2、使用FileInputStream对象中的方法read读取文件
        /*int i = fis.read();//只能单独读一个数字并返回
        System.out.println(i);*/

        /*发现以上读取文件时一个重复的过程，所以可以使用循环优化
        不知循环多少次用While 值多少次用for*/
       /* int len = 0;
        while((len = fis.read())!=-1){
            System.out.print(len+"");
            *//*布尔表达式(len = fis.read())!=-1
                      1、fis.read()读取一个字节
                      2、len=fis.read()把读取到的字节赋值给变量len
                      3、(len = fis.read())!=-1判断变量len是否不等于-1*//*
        }
        System.out.println();*/

        /*字节输入流一次获取多个字节
        方法：int	read​(byte[] b)	从输入流读取一些字节，并将它们存储到缓冲区数组中。b
        明确的事情
             1、方法的参数byte[]的作用起到缓冲作用，存储每次读取到的多个字节，一般定义1024或1024的整数倍
             2、返回值是什么？每次读取的有效字节*/
        byte[] bytes = new byte[1024];
        int len = 0;
        while((len=fis.read())!=-1) {
            System.out.println(new String(bytes , 0 , len));
        }

        //3、释放资源
        fis.close();
    }
}

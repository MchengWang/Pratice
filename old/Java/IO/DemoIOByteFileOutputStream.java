package Summarize.IO;

import java.io.FileOutputStream;
import java.io.IOException;

public class DemoIOByteFileOutputStream {
    /*字节流：一切皆字节
    OutputStream类介绍  java.io.OutputStream
    定义了一些子类共性的成员方法
    void	close()关闭此输出流并释放与此流关联的任何系统资源。
    void	flush()刷新此输出流并强制写入任何缓冲输出字节。
    void	write​(byte[] b)	将字节从指定的字节数组写入此输出流。b.length
    void	write​(byte[] b, int off, int len)	从指定的字节数组写入字节，从偏移量到此输出流。lenoff
    abstract void	write​(int b)	将指定的字节写入此输出流。
    java.io.FileOutputStream extends OutputStream
    FileOutputStream:文件字节输出流
    作用：把内存中的数据写入硬盘的文件中
    构造方法：
    FileOutputStream​(String name)	创建文件输出流以写入具有指定名称的文件。
    FileOutputStream​(File file)	创建文件输出流以写入指定对象表示的文件。File
    参数：写入数据的目的地
         File file 目的地是一个文件
         String name 目的地是一个文件的路径
    构造方法的作用
         1、创建一个FileOutputStream对象
         2、会根据构造方法中传递的文件/文件路径，创建一个空文件
         3、会把FileOutpurStream对象指向创建好的文件
    字节数据输出流写入数据到文件
    写入数据的原理（内存-->硬盘）
    java程序-->jvm（java虚拟机）-->os（操作系统）-->os调用写数据的方法-->把数据写入到文件中
    字节输出流的使用步骤
        1、创建一个FileoutputStream对象，构造方法中传递写入数据的目的地
        2、调用FileOutputStream对象中的额方法write，把数据写入文件中
        3、释放资源（流程使用完会占用一定的内存，使用完毕要把内容清空，提高程序的效率）*/
    public static void main(String[] args) throws IOException {
        /*文件存储的原理和记事本打开的原理
        硬盘中存储的数据是字节
        字节输入流写多个字节*/

        //1、创建一个FileoutputStream对象，构造方法中传递写入数据的目的地
        FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");

        //2、调用FileOutputStream对象中的额方法write，把数据写入文件中
        //fos.write(97);
        //在文件中显示100 三个字节
        /*fos.write(49);
        fos.write(48);
        fos.write(48);*/

        /*如果写的第一个字节是正数，那么显示的时候会查询ASCII表
        如果写的第一个字节是负数，那么第一个字节回合第二个字节，两个字节合成一个中文，查询默认码表（GBK）*/
        byte[] bytes = {65,66,67,68,69};//ABCDE
        fos.write(bytes);
        byte[] bytess = {-65,-66,-67,68,69};//烤紻E
        fos.write(bytess);

        /*把数组的一部分写入到文件中
         *int off：数组的开始索引
         * int len：写几个字节*/
        fos.write(bytes,1,2);
        /*写入字符串的方法，可以使用String转化字符数组 getytes（）*/

        byte[] byees = "你好".getBytes();
        fos.write(byees);

        //3、释放资源（流程使用完会占用一定的内存，使用完毕要把内容清空，提高程序的效率）
        fos.close();


    }
}

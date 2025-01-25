package Summarize.IO;

import java.io.FileWriter;
import java.io.IOException;

public class DemoIOFileWriter {
    /*字符输出流（Writer 抽象类 超类）java.Io.Writer
      共性的成员方法
      void	write​(char[] cbuf)	编写字符数组。
      abstract void	write​(char[] cbuf, int off, int len)	写入字符数组的一部分。
      void	write​(int c)	编写单个字符。
      void	write​(String str)	写入字符串。
      void	write​(String str, int off, int len)	写入字符串的一部分。
      abstract void	close()	关闭流，先刷新它。
      abstract void	flush()	冲洗流。
    java.Io.FileWriter extends Writer extends OutputStream
    FileWriter：文件字符输出流
    作用：吧内存中的字符数据写入到文件中
    构造方法：
    FileWriter​(File file)	使用平台的默认字符集构造给定的 写入FileWriterFile
    FileWriter​(String fileName)	使用平台的默认字符集构造给定的文件名FileWriter
    参数：写入数据的目的地
       String fileName：文件的路径
       File file：一个文件
    构造方法的作用
       1、会创建一个FileWriter对象
       2、会根据构造方法中传递的文件/文件夹的路径，创建文件
       3、会把FileWriter对象指向创建好的文件
    字符输出流_写出单个字符到文件中
       使用步骤
          1、创建FileWriter对象，构造方法中绑定写入的数据目的地
          2、使用FileWriter中的方法writer，把数据写入到内存的缓冲区中（字符转化为字节的过程）
          3、使用FileWriter中的方法flush，把内存缓冲区的数据，刷新到文件中
          4、释放资源（会先把内存缓冲区中的数据刷新到文件中）*/
    public static void main(String[] args) throws IOException {
        //1、创建FileWriter对象，构造方法中绑定写入的数据目的地
        FileWriter fw = new FileWriter("C:\\Users\\GoodMe\\Desktop\\test.txt");

        //2、使用FileWriter中的方法writer，把数据写入到内存的缓冲区中（字符转化为字节的过程）
        fw.write(97);

        //3、使用FileWriter中的方法flush，把内存缓冲区的数据，刷新到文件中
        fw.flush();

        //字符输出数据的其他方法
        char[] cs = {'a','b','c','d'};
        fw.write(cs);

        //写入数组的一部分
        fw.write(cs , 1 ,3);

        //写字符串
        fw.write("传智播客");

        //写字符串的一部分
        fw.write("黑马程序员",2,3);

        //4、释放资源（会先把内存缓冲区中的数据刷新到文件中）
        fw.close();

        /*flush和close方法的区别
        flush：刷新缓冲区，流对象可以继续使用
        close：先刷新缓冲区，然后通知系统释放资源，流对象不可以在被使用*/



    }
}

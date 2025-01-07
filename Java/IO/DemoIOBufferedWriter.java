package Summarize.IO;

import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class DemoIOBufferedWriter {
    /*字符缓冲输出流
    java.io.BufferedWriter extends Writer
    BufferedWriter字符缓冲输出流
    继承自父类的共性成员方法
       void	write​(char[] cbuf)	编写字符数组。
      abstract void	write​(char[] cbuf, int off, int len)	写入字符数组的一部分。
      void	write​(int c)	编写单个字符。
      void	write​(String str)	写入字符串。
      void	write​(String str, int off, int len)	写入字符串的一部分。
      abstract void	close()	关闭流，先刷新它。
      abstract void	flush()	冲洗流。
   构造方法
      BufferedWriter​(Writer out)	创建使用默认大小的输出缓冲区的缓冲字符输出流。
      BufferedWriter​(Writer out, int sz)	创建新的缓冲区字符输出流，该流使用给定大小的输出缓冲区。
   参数：Writer out 字符输出流
       我们可以传递FileWriter，缓冲流会给FileWriter增加一个缓冲区，提高FileWriter的写入效率
        int sz指定缓冲区的大小，不写默认大小
   特有的成员方法
       void	newLine()	写入行分隔符。
   使用步骤：
       1、创建字符缓冲输出流对象，构造方法中传递字符输出流
       2、调用字符缓冲输出流的方法writer，把数据写入缓冲区中
       3、使用flush把内存缓冲区的数据刷新到文件中
       4、释放资源*/
    public static void main(String[] args) throws IOException {
        //1、创建字符缓冲输出流对象，构造方法中传递字符输出流
        BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //2、调用字符缓冲输出流的方法writer，把数据写入缓冲区中
        bw.write(97);

        //3、使用flush把内存缓冲区的数据刷新到文件中
        bw.flush();

        //4、释放资源
        bw.close();
    }
}

package Summarize.CharacterSetsAndCharacterEncoding;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class DemoCharacterSetsAndCharacterEncodingTheprincipleofconvertingastreamOutputStreamWriter {
   /* OutputStreamWriter介绍&代码实现
    java.io.OutputStreamWriter extends Writer
    OutputStreamWriter是字符流向字节流的桥梁，可以使用指定的charst将要写入流中的字符编码成字节。
            （编码把能看懂的变成看不懂的）
    继承自父类的方法
      void	write​(char[] cbuf)	编写字符数组。
      abstract void	write​(char[] cbuf, int off, int len)	写入字符数组的一部分。
      void	write​(int c)	编写单个字符。
      void	write​(String str)	写入字符串。
      void	write​(String str, int off, int len)	写入字符串的一部分。
      abstract void	close()	关闭流，先刷新它。
      abstract void	flush()	冲洗流。
    构造方法：
      OutputStreamWriter​(OutputStream out)	建使用默认字符编码的输出流编写器。
      OutputStreamWriter​(OutputStream out, String charsetName)	创建使用命名字符集的输出流编写器。
    参数：OutputStream out字节输出流，可以用来写转换之后的字节到文件中
         String charsetName：指定的编码表名称，不区分大小写，可以是utf-8，也可以是UTF-8，gbk/GBK...不指定默认UTF-8
    使用步骤：
         1、创建一个OutputStreamWriter对象，构造方法中传递字节输出流和指定编码表名称
         2、使用OutputStreamWriter对象中的方法writer，把字符转换为字节存储缓冲区中（编码）
         3、使用OutputStreamWriter对象中的方法flush，把内存缓冲区中的字节刷新到文件中（使用字节流写字节的过程）
         4、释放资源
    */

    public static void main(String[] args) throws IOException {
       //show01();
        show02();
    }

    private static void show02() throws IOException {
        //1、创建一个OutputStreamWriter对象，构造方法中传递字节输出流和指定编码表名称
        OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"),"gbk");

        //2、使用OutputStreamWriter对象中的方法writer，把字符转换为字节存储缓冲区中（编码）
        osw.write("你好");

        //3、使用OutputStreamWriter对象中的方法flush，把内存缓冲区中的字节刷新到文件中（使用字节流写字节的过程）
        osw.flush();

        //4、释放资源
        osw.close();
    }

    private static void show01() throws IOException {
        //1、创建一个OutputStreamWriter对象，构造方法中传递字节输出流和指定编码表名称
        OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"),"utf-8");

        //2、使用OutputStreamWriter对象中的方法writer，把字符转换为字节存储缓冲区中（编码）
        osw.write("你好");

        //3、使用OutputStreamWriter对象中的方法flush，把内存缓冲区中的字节刷新到文件中（使用字节流写字节的过程）
        osw.flush();

        //4、释放资源
        osw.close();
    }
}

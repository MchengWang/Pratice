package Summarize.IO;

import java.io.FileReader;
import java.io.IOException;

public class DemoIOStringFileReader {
    /*字符流（字符输入流Reader）
    使用字节流，读取中文文件
       1个字节中文   GBK 占用两个字节
                   UTF-8 占用三个字节
    Reader和FileReader介绍  java.Io.Reder(字符输入流)定义了一些共性成员方法
    Reader抽象类（超类）
       int	read()	读取单个字符。
       int	read​(char[] cbuf)	将字符读取到数组中。
       abstract void	close()	关闭流并释放与其关联的任何系统资源。
   FileReader读取文件字符的输入流
       java.Io.FileReader extends Reader
    作用：把硬盘文件中的数以字符的方式读取到内存中
   构造方法：
   FileReader​(File file)	使用平台的默认字符集创建新 的 ，给定要读取的。FileReaderFile
   FileReader​(String fileName)	创建一个新的 ，给定要读取的文件的名称，使用平台的默认字符集。FileReader
   参数：读取文件的数据源
        String fileNam：文件的路径
        File file：一个文件
   字符输入流读取字符数据的使用步骤
        1、创建FileReader对象，构造方法中绑定要读取的数据源
        2、使用FileReader对象中的方法，read读取文件
        3、释放资源
  */
    public static void main(String[] args) throws IOException {
        //1、创建FileReader对象，构造方法中绑定要读取的数据源
        FileReader fr = new FileReader("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");

        //2、使用FileReader对象中的方法，read读取文件
        /*int len = 0;
        while((len = fr.read())!= -1){
            System.out.println((char)len);
        }*/

        //第二种方法
        char[] c = new char[1024];//存储读取到的多个字符
        int len = 0;//记录的是每次读取的有效字节个数
        while((len = fr.read(c))!= -1){
            /*String的构造方法
            String​(char[] value)	分配一个新字符，以便它表示字符数组参数中当前包含的字符序列。String
            String​(char[] value, int offset, int count)	把字符数组一部分转换为字符串off数组的开始索引count准换的个数*/
            System.out.println(new String(c , 0 , len));
        }

        //3、释放资源
        fr.close();


    }
}

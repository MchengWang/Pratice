package Summarize.CharacterSetsAndCharacterEncoding;

import java.io.*;

public class DemoCharacterSetsAndCharacterEncodingConvertthefileencoding {
    /*转换文件编码
    将Gbk转化为UTF-8
    分析：
      1、创建InputStreamReader对象，构造方法中传递字节输入流和指定编码表名称GBK
      2、创建OutputstreamWriter对象，构造方法中传递字节输出流和指定编码表名称UTF-8
      3、使用InoutStreamReader对象中的方法read()方法，读取文件
      4、使用OutputStreamWriter对象中的方法Writer()方法，把数据写入到文件中
      5、释放资源
    */
    public static void main(String[] args) throws IOException {

        //1、创建InputStreamReader对象，构造方法中传递字节输入流和指定编码表名称GBK
        InputStreamReader isr = new InputStreamReader(new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"),"gbk");

        //2、创建OutputstreamWriter对象，构造方法中传递字节输出流和指定编码表名称UTF-8
        OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("C:\\Users\\GoodMe\\Desktop\\test.txt"),"utf-8");

        //3、使用InoutStreamReader对象中的方法read()方法，读取文件
        char[] chars =new char[1024];
        int len = 0;
        while((len = isr.read(chars)) != -1){
            //4、使用OutputStreamWriter对象中的方法Writer()方法，把数据写入到文件中
            osw.write(len);
        }

        //5、释放资源
        osw.close();
        isr.close();
    }
}

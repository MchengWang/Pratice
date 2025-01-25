package Summarize.IO;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class DemoIOFileCopy {
    //文件复制 一读一写
    public static void main(String[] args) throws IOException {
        /*明确源：C:\\Users\\ZSH\\IdeaProjects\\untitled\\src\\TEST\\test.txt
          目的地：C:\\Users\\ZSH\\Desktop\\test.txt
        复制步骤：
           1、创建一个输入流对象，构造方法中绑定源文件路径
           2、创建一个输出流对象，构造方法中绑定目的地路径
           3、使用字节输入流的read的方法读取文件
           4、使用字节输出流的Write方法写入到目的地的文件中
           5、释放资源*/

        long l = System.currentTimeMillis();

        //1、创建一个输入流对象，构造方法中绑定源文件路径
        FileInputStream fis = new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");

        //2、创建一个输出流对象，构造方法中绑定目的地路径
        FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\Desktop\\test.txt");

        byte[] bytes = new byte[1024];
        int len = 0;
        //3、使用字节输入流的read的方法读取文件
        while((len=fis.read())!=-1){
            //4、使用字节输出流的Write方法写入到目的地的文件中
            fos.write(bytes , 0 , len);
        }

        //5、释放资源先关写入后关读取
        fos.close();
        fis.close();

        long l1 = System.currentTimeMillis();
        System.out.println(l1 - l);
    }
}

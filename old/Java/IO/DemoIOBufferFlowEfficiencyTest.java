package Summarize.IO;

import java.io.*;

public class DemoIOBufferFlowEfficiencyTest {
    /*缓冲流的效率测试_文件复制
    使用步骤：
       1、创建字节缓冲输入流对象，构造方法中传递字节输入流
       2、创建字节缓冲输出流对象，构造方法中传递字节输出流
       3、使用字节缓冲输如流中的方法read，读取文件
       4、使用字节缓冲输出流中的方法write，把读取的数据写入到内部的缓冲区中
       5、释放资源（会把缓冲区的数据，刷新到文件中）*/
    public static void main(String[] args) throws IOException {
        long l = System.currentTimeMillis();

        //1、创建字节缓冲输入流对象，构造方法中传递字节输入流
        BufferedInputStream bis = new BufferedInputStream(new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //2、创建字节缓冲输出流对象，构造方法中传递字节输出流
        BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream("C:\\Users\\GoodMe\\Desktop\\test.txt"));

        //3、使用字节缓冲输如流中的方法read，读取文件
        byte[] bytes = new byte[1024];
        int len = 0;
        while((len = bis.read()) != -1){
            //4、使用字节缓冲输出流中的方法write，把读取的数据写入到内部的缓冲区中
            bos.write(bytes , 0 ,len);
        }

        //5、释放资源（会把缓冲区的数据，刷新到文件中）
        bos.close();
        bis.close();

        long l1 = System.currentTimeMillis();
        System.out.println(l1 - l);
    }
}

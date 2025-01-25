package Summarize.IO;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class DemoIOTheByteBufferInputStream {
    /*BufferedInputStream_字节缓冲输入流
    java.io.BufferedInputStream extends InputStream
    继承自父类的成员方法
       abstract int	read()	从输入流读取下一个字节的数据。
        int	read​(byte[] b)	从输入流读取一些字节，并将它们存储到缓冲区数组中。b
        void	close()	关闭此输入流并释放与流关联的任何系统资源。
    构造方法：
        BufferedInputStream​(InputStream in)	创建 和 保存其参数，输入流 ，供以后使用。BufferedInputStreamin
        BufferedInputStream​(InputStream in, int size)	创建具有指定缓冲区大小的 ，并保存其参数，输入流 ，供以后使用。BufferedInputStreamin
    参数：
       InputStream in ：字节输入流
       我们可以传递FileInputStream，缓冲流中传递FileInputStream增加一个缓冲区，提高FileInputStream的读取效率
       int size 指定缓冲区的大小，不指定默认
   使用步骤（重点）
       1、创建FileInputStream对象，构造方法中绑定要读取的数据源
       2、创建BufferedInputStream对象，构造中传递FileInputStream对象，提高FileInputStream对象的效率
       3、使用BufferedInputStream对象中的方法read，读取文件
       4、释放资源
   */
    public static void main(String[] args) throws IOException {
        //1、创建FileInputStream对象，构造方法中绑定要读取的数据源
        FileInputStream fis = new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");

        //2、创建BufferedInputStream对象，构造中传递FileInputStream对象，提高FileInputStream对象的效率
        BufferedInputStream bis = new BufferedInputStream(fis);

        //3、使用BufferedInputStream对象中的方法read，读取文件
        byte[] bytes = new byte[1024];
        int len = 0;
        while((len = bis.read())!=-1){
            System.out.println(new String(bytes,0,len));
        }

        //4、释放资源
        bis.close();
    }
}

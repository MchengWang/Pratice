package Summarize.IO;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class DemoIOTheByteBufferedOutputStream {
    /*java.io.BufferedOutputStream extends OutputStream
    BufferedOutputStream:字节缓冲输出流
            继承自父类的共性成员方法
    void	close()关闭此输出流并释放与此流关联的任何系统资源。
    void	flush()刷新此输出流并强制写入任何缓冲输出字节。
    void	write​(byte[] b)	将字节从指定的字节数组写入此输出流。b.length
    void	write​(byte[] b, int off, int len)	从指定的字节数组写入字节，从偏移量到此输出流。lenoff
    abstract void	write​(int b)	将指定的字节写入此输出流。
    构造方法
    BufferedOutputStream​(OutputStream out)	创建新的缓冲输出流，将数据写入指定的基础输出流。
    BufferedOutputStream​(OutputStream out, int size)	创建新的缓冲输出流，以将数据写入具有指定缓冲区大小的指定基础输出流。
    参数：
    OutputStream out 字节输出流
    我们可以传递FileOutputStream，缓冲流会给FileOutputStream增加一个缓冲区，提高FileOutputStream的写入效率
    int size：指定缓冲流内部缓冲区的大小，不指定默认
    使用步骤（重点）
            1、创建FileOutputStream对象，构造方法中绑定要输入出的目的地
       2、创建BufferedOutputStream对象构造方法中传递FileOutputStream对象，提高FileOutputStream对象的效率
       3、使用BufferedOutputStream对象中的方法writer，把数据写入到内部缓冲区中
       4、使用BufferedOutputStream对象中的方法flush，把内部缓冲区的数据刷新到文件中
       5、释放资源（会先调用flush，刷新数据，第4步可以省略）*/
    public static void main(String[] args) throws IOException {
        //1、创建FileOutputStream对象，构造方法中绑定要输入出的目的地
        FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\Desktop\\test.txt");

        //2、创建BufferedOutputStream对象构造方法中传递FileOutputStream对象，提高FileOutputStream对象的效率
        BufferedOutputStream bos = new BufferedOutputStream(fos);

        //3、使用BufferedOutputStream对象中的方法writer，把数据写入到内部缓冲区中
        bos.write(97);

        //4、使用BufferedOutputStream对象中的方法flush，把内部缓冲区的数据刷新到文件中
        bos.flush();

        //5、释放资源（会先调用flush，刷新数据，第4步可以省略）
        bos.close();
    }
}

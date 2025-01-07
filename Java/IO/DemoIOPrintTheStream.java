package Summarize.IO;

import java.io.FileNotFoundException;
import java.io.PrintStream;

public class DemoIOPrintTheStream {
    /*打印流_概述和使用 PrintStream(打印流)
    java.io.PrintStream 打印流
       为其他输出流添加了功能，她能够更方便的打印各种数表示形式
    PrintStream特点
      1、只负责数据的输出，不负责数据的读取
      2、与其他输出不同，PrintStream永远不会抛出IoException异常
      3、有特有方法print println
         void print（任意数据类型）
         void println（任意数据类型）
    构造方法：
      PrintStream​(File file)	使用指定的文件创建新的打印流，无需自动行刷新
      PrintStream​(OutputStream out)	创建新的打印流。
      PrintStream​(String fileName, String csn)	使用指定的文件名和字符集创建新的打印流，无需自动行刷新。
    PrintStream extends OutputStream
    继承自父类的成员方法
         void	close()关闭此输出流并释放与此流关联的任何系统资源。
        void	flush()刷新此输出流并强制写入任何缓冲输出字节。
        void	write​(byte[] b)	将字节从指定的字节数组写入此输出流。b.length
        void	write​(byte[] b, int off, int len)	从指定的字节数组写入字节，从偏移量到此输出流。lenoff
        abstract void	write​(int b)	将指定的字节写入此输出流。
    注意：如果使用继承自父类的Write方法写数据，那么查看数据的时候会先查询编码表97--a
         如果使用自己特有的方法Print/Println写数据，写的数据原样97--97
     */

    public static void main(String[] args) throws FileNotFoundException {
        System.out.println("我是控制台输出");
        //创建打印输出流，printStream对象构造方法中绑定要输出的目的地‘
        PrintStream ps = new PrintStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");

        System.setOut(ps);//把输出语句目的地，改变为打印流的目的地
        //如果使用继承自父类的Write方法写数据，那么查看数据的时候会先查询编码表
        ps.write(97);
        System.out.println("我在打输出的目的地中输出");
        //如果使用自己特有的方法Print/Println写数据，写的数据原样
        ps.print(97);

        ps.close();

        /*可以改变输出语句的目的地（打印流流向）
        使用System.Setout方法改变输出语句目的地改为参数传流的打印流目的地
        static void	setOut​(PrintStream out)	重新分配"标准"输出流。*/
    }
}

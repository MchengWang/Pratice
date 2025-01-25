package Summarize.CharacterSetsAndCharacterEncoding;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class DemoCharacterSetsAndCharacterEncodingTheprincipleofconvertingastreamInputStreamReader {
    /*InputStreamReader extends Reader 字节流向字符流的桥梁，它使用指定的charset读取文件，并将其解码为字符
    （解码：看不懂的转换为看得懂的）
    继承自父类的成员方法
       int	read()	读取单个字符。
       int	read​(char[] cbuf)	将字符读取到数组中。
       abstract void	close()	关闭流并释放与其关联的任何系统资源。
    构造方法：
       InputStreamReader​(InputStream in)创建使用默认字符集的输入流阅读器。
       InputStreamReader​(InputStream in, String charsetName)创建使用命名字符集的输入流阅读器。
    参数：InputStream in 字节输入流，用来读取文件中保存的文件
         String charsetName指定的编码表名称，不区分大小写，可以是utf-8，也可以是UTF-8，gbk/GBK...不指定默认UTF-8
    使用步骤：
       1、创建一个InputStreamReader​对象，构造方法中传递指定的编码表名称
       2、使用InputStreamReader​中的方法Read方法
       3、释放资源
    注意：构造方法中指定的编码表名称和文件的编码表相同，否则会发生乱码*/

    public static void main(String[] args) throws IOException {
        show01();
        show02();
    }

    private static void show02() throws IOException {
        //1、创建一个InputStreamReader​对象，构造方法中传递指定的编码表名称
        InputStreamReader isr = new InputStreamReader(new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"),"UTF-8");

        //2、使用InputStreamReader​中的方法Read方法
        int len = 0 ;
        while((len = isr .read()) !=-1){
            System.out.println((char)len);
        }

        //3、释放资源
        isr.close();
    }

    private static void show01() throws IOException {
        //1、创建一个InputStreamReader​对象，构造方法中传递指定的编码表名称
        InputStreamReader isr = new InputStreamReader(new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"),"gbk");

        //2、使用InputStreamReader​中的方法Read方法
        int len = 0 ;
        while((len = isr .read()) !=-1){
            System.out.println((char)len);
        }

        //3、释放资源
        isr.close();
    }
}

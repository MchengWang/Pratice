package Summarize.IO;

import java.io.FileOutputStream;
import java.io.IOException;

public class DemoIOOutputStreamDatePlusAndDateSequels {
    /*追加（续写）使用两个参数的构造方法
   FileOutputStream​(File file, boolean append)	创建文件输出流以写入指定对象表示的文件。File
   FileOutputStream​(String name, boolean append)	创建文件输出流以写入具有指定名称的文件。
   参数：String name：写入数据的目的地
        File file：写入数据的目的地
        boolean append：追加写开关
                       true：创建对象不会覆盖重写源文件，继续在文件末尾追加数据
                       false；创建一个新文件，覆盖源文件
   */
    public static void main(String[] args) throws IOException {
        FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt" , true);
        fos.write("你好".getBytes());//不会换行


        //换行
        for (int i = 0; i < 10; i++) {
            fos.write("你好".getBytes());
            fos.write("\r\n".getBytes());
        }

        fos.close();
    }
}

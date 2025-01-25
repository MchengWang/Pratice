package Summarize.IO;

import java.io.FileWriter;
import java.io.IOException;

public class DemoIOWriterDatePlusAndDateSequels {
    /*字符输出流的续写和换行
    续写，使用两个参数的构造方法
    FileWriter​(File file, boolean append)	构造给定的 要写入和布尔，指示是否使用平台的默认字符集追加写入的数据。FileWriterFile
    FileWriter​(String fileName, boolean append)	构造给定的文件名和布尔值，指示是否使用平台的默认字符集追加写入的数据。FileWriter
    参数：String name File file 写入数据的目的地
         boolean append 追加写开关
                        true 不会创建新的文件覆盖源文件，可以重写
                        false：创建新的文件覆盖源文件
   换行符号：windows \r\n linux:/n Mac:/r
   */
    public static void main(String[] args) throws IOException {
        FileWriter fw = new FileWriter("C:\\Users\\GoodMe\\Desktop\\test.txt",true);
        for (int i = 0; i < 20; i++) {
            fw.write("Hello World" + i + "\r\n");
        }
        fw.close();
    }
}

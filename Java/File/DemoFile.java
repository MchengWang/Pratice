package Summarize.File;

import java.io.File;

public class DemoFile {
    /*File类
    java.io.File类是文件和目录路径名的抽象表示，主要用于文件和目录的创建，查找和删除等操作
    重点：记住三个单词：file：文件 ， directory：文件夹/目录 path：路径
    static String	pathSeparator	系统相关的路径分隔符，表示为字符串，方便。
    static char	pathSeparatorChar	依赖于系统的路径分隔符。
    static String	separator	从系统相关的默认名称分隔符，表示为字符串，方便。
    static char	separatorChar	依赖于系统的默认名称分隔符。
    构造方法
    File​(File parent, String child)	从父抽象路径名和子路径名字符串创建新实例。File
    File​(String pathname)	通过将给定的路径名字符串转换为抽象路径名创建新实例。File
    File​(String parent, String child)	从父路径名字符串和子路径名字符串创建新实例。File

    */

    public static void main(String[] args) {
        char c = File.pathSeparatorChar;
        System.out.println(c);//路径分隔符Windows； Linux：

        String s = File.separator;
        System.out.println(s);//文件名称分隔符Windows\ linux/

    }
}

package Summarize.File;

import java.io.File;
import java.io.FilenameFilter;

public class DemoFileSearch {
    public static void getAllFile(File dir , String name){
        System.out.println(dir);

        //FileNameFilter使用和lambda优化程序
        //匿名内部类
        File[] file = dir.listFiles(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name) {
                return new File(dir.getName()).isDirectory() || name.toLowerCase().endsWith(".pdf");
            }
        });

        //普通
       /* File[] file = dir.listFiles();
        for (File f : file) {
            if(f.isDirectory()){
                getAllFile(f);
            }else{
                *//*只要把pdf格式结尾的文件
                * 1、把File对象转换为字符串*//*
                //String str1 = f.getName();
                //String str2 = f.getPath();
                String str3 = f.toString();
                str3.toLowerCase();
                //调用String方法endswith判断是否为.pdf结尾
                boolean b = str3.endsWith(".pdf");
                //如果是以.pdf结尾的文件则输出
                if(b){
                    System.out.println(f);
                }else{
                    if(f.getName().toLowerCase().endsWith(".pdf")){
                        System.out.println(f);
                    }
                }
            }
        }*/



    }

    public static void main(String[] args) {
        /*文件过滤器优化
        在File类中有两个和ListFile（）重载的方法，方法的参数传递是过滤器
        File[]	listFiles​(FileFilter filter)	返回一个抽象路径名数组，这些参数表示目录中的文件和目录，
        这些参数由满足指定筛选器的此抽象路径名表示。
        java.io.FileFileter接口：用于抽象路径名File对象的过滤器
            作用：用来过滤文件（File对象）
            抽象方法：用来过滤文件的方法
            boolean	accept​(File pathname)	测试指定的抽象路径名是否应包含在路径名列表中。
            参数：File pathname：使用listFiles方法遍历目录，得到每一个文件名
        File[]	listFiles​(FilenameFilter filter)	返回一个抽象路径名数组，这些参数表示目录中的文件和目录，
        这些参数由满足指定筛选器的此抽象路径名表示。
        java.io.FileNamefiler接口，实现此接口的实例可用于过滤器文件名
            作用：用来过滤文件名称
            抽象方法：用来过滤方法中的方式
            boolean	accept​(File dir, String name)	测试指定文件是否应包含在文件列表中。
            参数：File dir：构造方法中传递的被遍历的目录
                 String name：使用listFiles方法遍历目录，获取每一个文件/文件夹的名称
       注意：两个过滤器是没有实现类的，需要我们自己写实现类，重写过滤方法accept在方法中定义过滤规则
       必须明确两件事
           1、过滤器中的accept方法是谁调用的
           2、accept方法中的参数pathName是什么
       */
        File file = new File("C:\\Users\\GoodMe\\Desktop\\C++学习资料");
        getAllFile(file , "2分支.PDF");
    }
}

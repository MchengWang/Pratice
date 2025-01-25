package Summarize.Recursive;

import java.io.File;

public class DemoRecursivePrint {
    /*递归打印多级目录
    遍历文件夹以及文件中的子文件*/
    public static void getAllFile(File dir){
        //定义一个方法传递File类型目录方法中对目录进行遍历
        System.out.println(dir);//打印被遍历的目录名称
        File[] file = dir.listFiles();
        for (File f : file) {
            if(f.isDirectory()){
                getAllFile(f);
            }else{
                System.out.println(f);
            }
        }

    }

    public static void main(String[] args) {
        File file = new File("C:\\Users\\ZSH\\Desktop\\java");
        getAllFile(file);
    }

    /*分析：发现遍历结果并不安全，只有文件夹中的内容，没有子文件夹的内容
    * 解决：对遍历得到的File对象进行判断，判断是否有文件夹
    * if(f.isDirectory()){
    *   //f是一个文件夹，则继续遍历这个文件夹
    *   //我们发现getAllFile方法，就是传递文件夹，遍历文件夹的方法
    *   //所以直接调用getAllFile方法即可，递归（自调自身）
    *   getAllFile（f）;
    * }else{
    *   //f是一个文件，直接打印即可
    *   System.out.prinln(f);
    * }
    * */
}

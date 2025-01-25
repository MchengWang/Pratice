package Summarize.Exception;

import java.io.FileNotFoundException;
import java.io.IOException;

public class DemoExceptionThrows {
    /*throws关键字 声明异常 异常处理的第一种方式交给别人处理（中断）
    作用：当方法内部抛出异常对象时，那么我们就必须处理这个异常对象
         可以使用throw关键字处理异常对象，会把异常对象声明抛出给方法的调用者处理（
         自己不处理，交给别人处理）最终交给jvm处理处理-->中断处理
    使用格式： 在方法声明时使用
           修饰符 返回值类型 方法名（参数） throws XXXException{
            throw new XXXException ("原因");
           }
   注意：
        1、throws必须写在方法声明处
        2、throws后边声明的是异常，必须是Exception或者Exception的子类
        3、方法内部如果抛出多个异常对象没那么throws后面也声明多个异常
           如果抛出的多个异常又子父类关系，那么直接声明父类对象即可
        4、调用声明异常抛出的方法，我们就必须处理声明的异常，要么继续使用throws声明抛出，交给方法的调用者处理
           最终交给jvm要么try...catch自己处理这个异常*/
    public static void redFile(String filename) throws IOException {

        /*如果传递的路径不是。txt结尾
        那么会抛出Io异常，告知调用者，后缀名不对*/
        if(filename.endsWith(".txt")){
            throw new IOException("文件的后缀名不是.txt");
        }

        if(!filename.equals("C:\\a.txt")){
            throw new FileNotFoundException("传递的路径是C:a.txt");
        }

        System.out.println("路径没有问题，读取文件");

        /*上述为定义一个方法对传递文件路径和后缀名进行合法判断
          如果路径不是"C:\\a.txt"后缀名不是“.txt”会抛出FileNotFoundsException和
          IoException异常
          注意：FileNotFoundException， Ioexception都是编译异常，必须处理；
          可以使用Throws声明抛出FileNotFoundException,InException异常，让调用者处理
          FileNotFoundException extends IoException 所以只用声明IoException或者Exception*/
    }

    public static void main(String[] args) throws IOException {
        redFile("C:\\a.ttt");
    }
}

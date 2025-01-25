package Summarize.Throwable;

import java.io.IOException;

public class DemoThrowabletest {
    /*Throwable类中3个处理异常的方法
         String	getMessage() 返回此可引发的详细信息消息字符串。
         String	toString()	返回此可引发项的简短说明。
         void	printStackTrace()	打印此可投掷和其回溯到标准错误流。
*/

    public static void main(String[] args) {
        try {
            method("C:\\a.docx");//可能产生异常的代码
        } catch (IOException e) {//try中抛出什么异常，那么catch就会定义什么异常变量用来接收这个异常对象
            System.out.println(e.getMessage());//文件的后缀名不对

           System.out.println(e.toString());//重写object类的toString java.io.IOException: 文件的后缀名不对


          e.printStackTrace();//最详细
        }
        System.out.println("后续");
    }
    public static void method(String filename) throws IOException {
        if(!filename.endsWith(".txt")){
            throw new IOException("文件的后缀名不对");
        }
    }
}

package Summarize.Exception;

import java.io.IOException;

public class DemoExceptionTryCatch {
    /*try...catch 捕获异常自己处理
    格式 try{

    }catch（异常变量 变量名）{
        异常的处理逻辑，异常对象之后，怎么处理异常对象
        一般工作中，会把异常的信息记录在一个日志中
    } ...catch(异常变量 变量名){}
    注意：
       1、try中可能抛出多个异常对象，那么就使用多个catch处理这些异常对象
       2、如果try中产生了异常，那么会执行catch中的异常的处理逻辑，执行完毕catch中的
       处理逻辑，继续执行try...catch之后的代码
       如果try中没有产生异常，那么就不会执行catch异常的处理逻辑，执行完毕try中的代码，继续执行try...catch
       之后的代码*/
    public static void main(String[] args) {
        try {
            method("C:\\a.docx");//可能产生异常的代码
        } catch (IOException e) {//try中抛出什么异常，那么catch就会定义什么异常变量用来接收这个异常对象
            e.printStackTrace();
        }
        System.out.println("后续");
    }
    public static void method(String filename) throws IOException {
        if(!filename.endsWith(".txt")){
            throw new IOException("文件的后缀名不对");
        }
    }
}

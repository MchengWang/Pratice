package Summarize.IO;

import java.io.*;

public class DemoIOExceptionHandling {
    /*在jdk1.7之前使用try。。。catch。。。finaly处理异常
    格式：try{
    //...可能会出现异常的代码
    }catch(异常变量 变量名){
    //异常的处理逻辑
    }finaly{
    一定会执行的代码，资源释放
    }*/

    public static void main(String[] args) throws FileNotFoundException {
        FileWriter fw = null;
        try{
            fw = new FileWriter("C:\\Users\\GoodMe\\Desktop\\test.txt",true);
            for (int i = 0; i < 20; i++) {
                fw.write("Hello World" + i + "\r\n");
            }
        }catch(IOException e){
            System.out.println(e);
        }finally {
            //如果创建对象失败fw默认值为null不会调用方法，先抛出空指针异常，增加判断，不是null再把资源释放
            if(fw!=null){
                try {
                    fw.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        /*jdk7和jdk9流中异常的代码
        jdk7的新特性
            在try的后面可以增加一个（）在括号内可以定义流对象
            那么这个流对象的作用域就在try中有效
            try中的代码执行完毕，会自动把流对象释放，不用写finally
        格式：try(定义流对象；...){
        //可能会出现异常的代码
        }catch(异常变量 变量名){
        //异常的处理逻辑
        }*/
       try(FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt",true);
           FileInputStream fis = new FileInputStream("C:\\Users\\GoodMe\\Desktop\\test.txt");){
           int len = 0;
           while((len=fis.read())!= -1){
               fos.write(len);
           }
       }catch(IOException e){
           System.out.println(e);
       }

       /*jdk9的新特性
       try的前面可以定义流对象
       在try后面的（）可以直接引入流对象的名称（变量名）
       在try代码执行完毕后，流对象也可以释放，不用谢finally
       格式：A a = new A();
            B b = new B();
            try(a,b ){}catch(异常变量 变量名){}*/

        FileInputStream fis = new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt");
        FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\Desktop\\test.txt");
        try(fis ; fos){
            int len = 0;
            while((len = fis.read())!=-1){
                fos.write(len);
            }
        }catch(IOException e){
            System.out.println(e);
        }

    }
}


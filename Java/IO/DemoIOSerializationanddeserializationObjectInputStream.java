package Summarize.IO;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class DemoIOSerializationanddeserializationObjectInputStream {
    /*对象的反序列化流
    ObjectInputStream 类 extends InputStream
    java.io.ObjectInputStream:对象的反序列化流
    作用：把文件中保存的对象，以流的方式读取出来使用
    构造方法：
       ObjectInputStream​(InputStream in)	创建从指定的输入流读取的对象输入流。
    参数：InputStream in 字节输入流
    特有的成员方法
       Object	readObject()	从对象输入流读取对象。
    使用步骤：
       1、创建ObjectInputStream对象，构造方法中传递字节输入流
       2、使用ObjectInputStream中的方法readObject（）读取保存对象的文件
       3、释放资源
       4、使用读取出来的对象（打印）*/
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        //1、创建ObjectInputStream对象，构造方法中传递字节输入流
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //2、使用ObjectInputStream中的方法readObject（）读取保存对象的文件
        Object o = ois.readObject();
        /*readObject()放啊声明了抛出ClassNotFoundException（class文件找不到异常）
        *当不存在对象的class文件时会抛出异常*/

        //3、释放资源
        ois.close();

        //4、使用读取出来的对象（打印）
        System.out.println(o);

        /*反序列化的前提
        *  1、类比细实线Serializable接口
        *  2、必须存在类对应的class文件*/
    }
}

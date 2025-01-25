package Summarize.IO;

import java.io.*;

public class DemoIOSerializationanddeserializationObjectOutputStream {
    /*ObjectOutputStream extends OutputStream
    java.io.ObjectOutputStream:对象的序列化流
    作用：把对象在以流的方式写入到文件中保存
    构造方法：
       ObjectOutputStream​(OutputStream out)	创建写入指定输出流的对象输出流。
       参数：OutputStream out字节输出流
    特有的成员方法
       void	writeObject​(Object obj)	将指定的对象写入对象输出流。
    使用步骤：
       1、创建ObjectOutputStream对象，构造方法中传递字节输出流
       2、使用ObjectOutputStream对象中的方法WriterObject（），把对象写入到文件中
       3、释放资源
    */
    public static void main(String[] args) throws IOException {
        //1、创建ObjectOutputStream对象，构造方法中传递字节输出流
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //2、使用ObjectOutputStream对象中的方法WriterObject（），把对象写入到文件中
        oos.writeObject(new person(38,"胡歌"));
        /*序列化和反序列化错误，会抛出NotSerializableException没有序列化异常
        类通过实现java.io.Serializable接口一起用其序列化功能，为实现接口的类将无法使用其任何状态的序列化和反序列化
        Serializable接口也叫做标记型接口
          要进行序列化和反序列化的类，必须实现Serializable接口，就会给类添加一个标记
          当我们进行序列化和反序列化的时候就会检测类上是否有这个标记
             有：就可以序列化和反序列化
             没有：就会抛出NotSerializabeExceptio异常*/

        //3、释放资源
        oos.close();
    }
}

class person implements Serializable{
    private int age;
    private  String name;

    public person() {
    }

    public person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "person{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

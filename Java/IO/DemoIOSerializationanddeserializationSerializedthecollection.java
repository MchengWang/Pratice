package Summarize.IO;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class DemoIOSerializationanddeserializationSerializedthecollection {
    /*序列化集合
    当我们想在文件中保存多个对象的时候，可以把多个对象存储到一个集合中，对集合进行序列化和反序列化
    分析：
       1、定义一个存储Person对象的集合（ArrayList）
       2、往ArrayList中添加对象
       3、创建一个序列化流ObjectOutputStream对象
       4、使用ObjectOutputStream中的方法WriterObject（0方法，对集合进行序列化
       5、常见反序列化ObjectInputStream对象
       6、使用ObjectInputStream中的方法readObject（）读取文件中对想到集合中
       7、把Object集合转化为ArrayList集合
       8、遍历ArrayList集合
       9、释放资源
      */
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        //1、定义一个存储Person对象的集合（ArrayList）
        ArrayList<Person> list = new ArrayList<>();

        //2、往ArrayList中添加对象
        Collections.addAll(list,new Person("你猜猜",20),new Person("王梦成",18),
        new Person("胡歌",38));

        //3、创建一个序列化流ObjectOutputStream对象
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //4、使用ObjectOutputStream中的方法WriterObject（0方法，对集合进行序列化
        oos.writeObject(list);

        //5、常见反序列化ObjectInputStream对象
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //6、使用ObjectInputStream中的方法readObject（）读取文件中对想到集合中,7、把Object集合转化为ArrayList集合
        ArrayList<Person> list1 = (ArrayList<Person>) ois.readObject();

        //8、遍历ArrayList集合
        for (Person person : list1) {
            System.out.println(person);
        }

        //9、释放资源
        ois.close();
        oos.close();
    }
}

class Person implements Serializable{
    private String name;
    private int age;

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}

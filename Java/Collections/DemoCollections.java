package Summarize.Collections;

import java.util.ArrayList;
import java.util.Collections;

public class DemoCollections {
    /*Collections常用方法：
     static <T> boolean	addAll​(Collection<? super T> c, T... elements) 将所有指定的元素添加到指定的集合。
     static void	shuffle​(List<?> list) 使用默认的随机性源随机排列指定列表。
     static <T extends Comparable<? super T>>
     void sort​(List<T> list)	根据指定列表元素的自然顺序，按升序排序。
     static <T> void sort​(List<T> list, Comparator<? super T> c) 根据指定比较器诱导的顺序对指定列表进行排序。
     使用步骤
     1、往集合中添加元素
     2、打乱集合顺序
     3、将集合中的元素按照默认规则排序
     4、将集合中元素按照制定规则排序*/
    public static void main(String[] args) {
        //创建集合对象
        ArrayList<String> list = new ArrayList<>();
        //往集合中添加元素
        Collections.addAll(list,"a","b","c","d","e","f");
        //打乱顺序
        Collections.shuffle(list);
        System.out.println(list);//[c, b, a, e, d, f]

        //排序
        Collections.sort(list);//默认是升序
        System.out.println(list);//[a, b, c, d, e, f]

        /*sort方法使用前提
             被排序的集合中存储的元素，必须实现Comparable接口，重写Comparable的方法toComparabeTo
             定义排序的规则*/

        Person p1 = new Person(19);
        Person p2 = new Person(20);
        ArrayList<Person> list01 = new ArrayList<>();
        Collections.addAll(list01,p1,p2);
        Collections.sort(list);
        System.out.println(list01);


    }
}

class Person implements Comparable<Person>{
    private int age;

    public Person() {
    }

    public Person(int age) {
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "age=" + age +
                '}';
    }

    @Override
    public int compareTo(Person o) {
        //return 0;//认为元素是相同的
        //自定义规则，比较两人年龄（this.参数Person）
        return this.getAge()-o.getAge();//年龄升序排序
    }
}

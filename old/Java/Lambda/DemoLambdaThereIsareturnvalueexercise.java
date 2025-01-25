package Summarize.Lambda;

import java.util.Arrays;
import java.util.Comparator;

public class DemoLambdaThereIsareturnvalueexercise {
    /*lambda表达式有返回值练习
    需求：是用数值存储多个Person对象
    对数组的Person对象使用ArrayList的Sort方法通过年龄进行排序*/
    public static void main(String[] args) {
        //使用数组存储多个Person对象
        Person[] arr = {
          new Person("胡歌",28),
          new Person("王梦成",17),
          new Person("张守慧",18),
        };

        //对数组中的Person对象，使用ArrayList的Sort方法，通过年龄进行一个升序（前-后）排序
       /* Arrays.sort(arr, new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                return  o1.getAge() - o2.getAge();
            }
        });*/

        //使用Lambda表达式简化匿名内部类
        Arrays.sort(arr,((o1, o2) -> o1.getAge() - o2.getAge()));

        //遍历数组
        for (Person person : arr) {
            System.out.println(person);
        }
    }

}

class Person{
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

    public void setName(String name) {
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
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}

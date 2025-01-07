package Summarize.Object;

import java.util.Objects;

public class DemoObjectEquals {
    public static void main(String[] args) {
        /*object中的equals方法
         boolean equals(Object obj) 指示其他某个对象是否与此对象“相等”。
         参数 Object obj ： 可以传递任意的对象
         equals的源码
         public boolean equals(Object obj){
            return (this == obj);
         }
         方法体：
         == 比较运算符，返回值是布尔值，非true即false
         基本数据类型 比较的是值
         引用数据类型 比较的是两个对象的地址值
          问题：隐含着一个多态
          多态弊端：无法使用子类特有的内容
          解决方法：可以使用向下转型（强转）吧Object类型转化为Person*/
        Person o = new Person("胡歌",28);
        Person t = new Person("胡歌",28);
        boolean f = o.equals(t);//比较的是地址值，要是比较属性值，我们可以重写equals方法
        System.out.println(f);
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
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Person person = (Person) o;
        return age == person.age &&
                Objects.equals(name, person.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }
}

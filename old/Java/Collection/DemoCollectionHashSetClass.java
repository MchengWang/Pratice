package Summarize.Collection;

import java.util.HashSet;
import java.util.Objects;

public class DemoCollectionHashSetClass {
    public static void main(String[] args) {
        //创建HashSet集合存储Students
        HashSet<Students> set = new HashSet<>();
        Students s1 = new Students("小豆腐干",18);
        Students s2 = new Students("小豆腐干",18);
        Students s3 = new Students("小豆腐干",19);
        System.out.println(s1.hashCode());//734175839
        System.out.println(s3.hashCode());//734175840
        System.out.println(s1 == s2);//false
        System.out.println(s1.equals(s2));//true
        set.add(s1);
        set.add(s2);
        set.add(s3);
        System.out.println(set);//[Students{name='小豆腐干', age=19}, Students{name='小豆腐干', age=18}]
    }
}
class Students{//必须重写equals和toString方法
    private String name;
    private int age;

    public Students() {
    }

    public Students(String name, int age) {
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
    public boolean equals(Object o) {//重写equals方法
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Students students = (Students) o;
        return age == students.age &&
                Objects.equals(name, students.name);
    }

    @Override
    public int hashCode() {//重写hashcode方法
        return Objects.hash(name, age);
    }

    @Override
    public String toString() {//重写toString方法
        return "Students{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}

package Summarize.Generics;

import java.util.ArrayList;
import java.util.Iterator;

public class DemoGenercistest {
    /*当我们不知道使用什么类型的时候，可以使用泛型
      泛型也可以看作是一个变量，用来接收数据类型
      E e Elements 元素     T t Type 类型
        */
    public static void main(String[] args) {
        /*创建集合对象，不使用泛型
        好处：集合不使用泛型，默认类型是odject类型，可以存储任何类型的数据
        弊端：不安全，会引发异常*/
       /* ArrayList list = new ArrayList();
        list.add("aaa");
        list.add(1);
        //使用迭代器遍历list集合  //获取迭代器
        Iterator it = list.iterator();
        //使用迭代器中的hasNext()和next（）方法
        while(it.hasNext()){
            Object obj = it.next(); // 取出的类型是object类型
            System.out.println(obj);
            //向下转型 //想使用String的方法Length，不能使用多态 object obj = “abc”；
            String s = (String) obj;
            System.out.println(s.length());//ClassCastException会抛出类型转换异常
            //不能把Integer类型转换为String类型
        }*/

        /*创建集合对象，使用泛型
        好处：1、避免了类型转换的麻烦，存储的是什么类型，取出就是什么类型
             2、把运行异常（代码运行之后才会抛出异常），提升到了编译异常（写代码的时候会报错）
        弊端：反省是什么类型，只能存储什么类型的数据*/
        ArrayList<String> list = new ArrayList<>();
        list.add("abc");
        //list.add(1);//add(java.lang.String)in Arraylist cannot be applied to (int);
        //使用迭代器遍历集合
        Iterator<String> it = list.iterator();
        while(it.hasNext()){
            String s = it.next();
            System.out.println(s);
        }
    }
}

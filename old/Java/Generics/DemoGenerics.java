package Summarize.Generics;

import java.lang.reflect.Array;
import java.sql.ClientInfoStatus;
import java.util.ArrayList;
import java.util.Iterator;

public class DemoGenerics {
    /*泛型通配符：<?>
    不知有什么类型来接收数据的时候，此时可以使用，此时只能接收数据不能往该集合存储集合
    使用方式： 1、不能创建对象使用
             2、只能作为方法的参数使用*/
    public static void main(String[] args) {
        ArrayList<Integer> list01 = new ArrayList<>();
        list01.add(1);
        list01.add(2);

        ArrayList<String> list02 = new ArrayList<>();
        list02.add("a");
        list02.add("b");

        PrintArray(list01);
        PrintArray(list02);

    }

    public static void PrintArray(ArrayList<?> list){
        //使用迭代器遍历
        Iterator<?> it = list.iterator();
        while(it.hasNext()){
            Object o = it.next();
            System.out.println(o);
        }
    }
}

package Summarize.Generics;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class DemoGenericsWildcards {
    /*泛型通配符的高级使用 （受限泛型）
    泛型的上限 格式：类型名称<? extends 类>对象名称
             意义：只能接收该类型及其子类
    泛型的下限 格式：类型名称<? super 类>对象名称
             意义：只能接受该类型及其父类*/
    public static void main(String[] args) {
        Collection<Integer> list01 = new ArrayList<Integer>();
        Collection<String> list02 = new ArrayList<String>();
        Collection<Number> list03 = new ArrayList<Number>();
        Collection<Object> list04 = new ArrayList<Object>();
        getElements1(list01);
        //getElements1(list02);//报错
        getElements1(list03);
        //getElements1(list04);//报错

        //getElements2(list01);//报错
        //getElements2(list02);//报错
        getElements2(list03);
        getElements2(list04);
        /*类与类之间的继承关系 Integer extends Number extends Object
                           String extends object*/

    }
    //泛型的上限，必须是Number类型或者是Number类型的子类
    public static void getElements1(Collection<? extends Number> coll){}
    //泛型的下限，必须是Number类型或者是Number类型的父类
    public static void getElements2(Collection<? super Number> coll){}

}

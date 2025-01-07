package Summarize.Map;

import java.util.HashMap;
import java.util.Hashtable;

public class DemoMapHashtable {
    /*Hashtable集合 implements Map(不允许空值) （单线程） 慢
        1、不允许存储null值
        2、最早期的双列集合
    java.util.Hashtable<k,v>
    Hashtable:底层是一个哈希表，是一个线程安全的集合，是单线程，速度慢
    HashMap：底层是一个哈希表，是一个线程不安全的集合，是多线程，速度快
    （之前学的集合）：可以存储null值，null键
    Hashtable：不能存储null值，bull键
    Hashtable和Vector集合不一样，在jdk1.2之后被（HashMap ArrayList）取代了
    Hashtable的子类 Properties依然活跃在历史的舞台上
    Properties是一个唯一和Io流相结合的集合*/
    public static void main(String[] args) {
        //创建集合对象
        HashMap<String ,String> map = new HashMap<>();
        //往集合中日添加元素
        map.put(null , "a");
        map.put( "a" ,null);
        map.put(null , null);
        System.out.println(map);//{null=null, a=null}

        //创建Hashtable集合
        Hashtable<String,String> table = new Hashtable<>();
        table.put(null ,"a");//NullPointerException空指针异常
        table.put("a" ,null);//NullPointerException
        table.put(null ,null);//NullPointerException
        System.out.println(table);
    }
}

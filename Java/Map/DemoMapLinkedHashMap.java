package Summarize.Map;

import java.util.HashMap;
import java.util.LinkedHashMap;

public class DemoMapLinkedHashMap {
    /*LinkedHashMap特点
        1、LinkedHashMap集合底层是哈希表+链表（保证迭代顺序）
        2、LinkedHashMap集合是一个有序地集合，存储元素和取出元素的顺序一致
    LinkedHashMap集合 extends HashMap集合（有序集合）
     Map接口的哈希表+链表列表实现，可具有预知的迭代顺序
    底层原理：哈希表+链表（记录元素的顺序）*/
    public static void main(String[] args) {
        //创建HashMap集合对象
        HashMap<String ,String> map = new HashMap<>();
        map.put("a","a");
        map.put("c","c");
        map.put("b","b");
        map.put("a","d");
        System.out.println(map);//key不允许重复，无序{a=d, b=b, c=c}

        //创建LinkedHashMap集合对象
        LinkedHashMap<String ,String> linked = new LinkedHashMap<>();
        linked.put("a","a");
        linked.put("c","c");
        linked.put("b","b");
        linked.put("a","d");
        System.out.println(linked);//key不允许重复，有序{a=d, c=c, b=b}
    }
}

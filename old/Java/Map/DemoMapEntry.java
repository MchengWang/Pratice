package Summarize.Map;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class DemoMapEntry {
    /*Entry键值对对象
    在map接口中有一个内部接口Entry
    作用：当map集合一创建，那么就会在map集合中创建一个Entry对象，用来记录键与值（键值对对象，键与值的映射关系）-->结婚证
    Set<Map.Entry<K,​V>>	entrySet()	获取所到Map集合中所有的键值对对象的集合（Set集合）
    Map遍历键值对方式
     Set<Map.Entry<K,​V>>	entrySet()	获取所到Map集合中所有的键值对对象的集合（Set集合）
    实现步骤
     1、使用Map集合中的方法entrySet（），把Map集合中多个Entry对象取出来，存储到一个set集合中
     2、遍历set集合，获取每一个Entry对象
     3、使用Entry对象中的方法，getKey()和getValue()获取键与值*/
    public static void main(String[] args) {
        //创建Map集合
        Map<String, Integer> map = new HashMap<>();

        //往集合中添加元素
        map.put("张守慧",18);
        map.put("王梦成",17);

        //1、使用Map集合中的方法entrySet（），把Map集合中多个Entry对象取出来，存储到一个set集合中
        Set<Map.Entry<String, Integer>> entries = map.entrySet();

        //2、遍历set集合，获取每一个Entry对象
        //使用迭代器遍历
       /* Iterator<Map.Entry<String, Integer>> it = entries.iterator();
        while(it.hasNext()){
            Map.Entry<String, Integer> entry = it.next();
            //3、使用Entry对象中的方法，getKey()和getValue()获取键与值
            String key = entry.getKey();
            Integer value = entry.getValue();
            System.out.println(key+"="+value);//王梦成=17,张守慧=18
        }*/

        //使用增强for循环
        for (Map.Entry<String, Integer> entry : entries) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            System.out.println(key+"="+value);//王梦成=17,张守慧=18
        }
    }
}

package Summarize.Map;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.jar.JarOutputStream;

public class DemoMapInterface {
    /*Map集合概述
        将键印象到值的对象，一个映射不包含重复的键；每个键最多只能映射到一个值
      Map集合 定义了双列集合的规范 每次存储一对元素 Map<k,v>夫妻对集合
      K 代表键的类型  V代表值的类型
      通过键找到相应的值
       1、键唯一（值可变）
       2、键和值————映射一个键一个值
       3、靠键维护他们的关系
      Map集合的特点
       1、Map集合是一个双列集合，一个元素包括两个值（一个Key，一个Value）
       2、Map集合中的元素，key和Value的数据类型可以相同，可以不同
       3、Map集合中的元素，key是不允许重复的，value是可以重复的
       4、Map集合中的元素，key和value一一对应
      Map常用子类
       HashMap此类不保证映射的顺序，特别是他不保证该顺序恒基不变（多线程） implements Map<K,V>接口
       LinkedHashMap extends HashMap
      Map接口的常用方法
       boolean	containsKey​(Object key)	判读集合中是否包含指定的键
       V	get​(Object key)	根据指定的键在Map集合中获取相应的值
       V	remove​(Object key)	把指定的键所对应的值对元素，在Map集合中删除，返回被删除元素的值。
       Set<K>	keySet()	获取Map集合中所有的键，存储到Set集合中
       Set<Map.Entry<K,​V>>	entrySet()	获取所到Map集合中所有的键值对对象的集合（Set集合）
       V	put​(K key, V value)	将指定的键与值添加到Map集合中。
       */
    public static void main(String[] args) {
        //创建Map集合对象
        Map<String , String> map = new HashMap<>();
        String v1 = map.put("王梦成", "张守慧");
        System.out.println(v1);//v1 = null
        String v2 = map.put("王梦成", "张守慧");
        System.out.println(v2);//v2 =张守慧
        System.out.println(map);//{王梦成=张守慧}

        map.put("杨过","小龙女");
        map.put("胡歌","刘亦菲");
        map.put("甄志丙","小龙女");
        map.put("冷锋","龙小云");
        System.out.println(map);//{杨过=小龙女, 甄志丙=小龙女, 胡歌=刘亦菲, 冷锋=龙小云}

        /*publiv v put (k key , v value):
        返回值 v
        存储值对的时候，key不重复，返回值v是null
                     key重复，会使用新的value替换Mao中重复的Value，返回被替换的value值
        public v remove(Object key):
        返回值v
           key存在，v返回被删除的值，key不存在，v返回为空null；
      */
        String s = map.remove("甄志丙");
        System.out.println(s);//小龙女
        System.out.println(map);//{杨过=小龙女, 王梦成=张守慧, 胡歌=刘亦菲, 冷锋=龙小云}
        String s1 = map.remove("尹志平");
        System.out.println(s1);//null

        //多使用包装类，少使用基本数据类型
        /*public v get(Object key)
          返回值V: key存在，返回对应的value值，key不存在的时候返回null*/
        String s2 = map.get("王梦成");
        System.out.println(s2);//张守慧

        /*public boolean	containsKey​(Object key)	判读集合中是否包含指定的键
          返回值boolean 包含true 不包含false*/
        boolean b = map.containsKey("王梦成");
        System.out.println(b);//true
        boolean b1 = map.containsKey("张守慧");
        System.out.println(b1);//false

        /*Map集合遍历键找值的方法
        利用Set<K>	keySet()，把Map集合中的所有key取出存储到Set集合，使用迭代器或则增强
        for循环遍历Set集合，获取Map中的每一个key，通过key获取value get（key）*/
        //Set<K>	keySet()，把Map集合中的所有key取出存储到Set集合
        Set<String> set = map.keySet();
        System.out.println(set);

        //使用迭代器遍历set集合
        Iterator<String> it = set.iterator();
        while(it.hasNext()){
            String s3 = it.next();//s3是键的值
            String s4 = map.get(s3);//s4是vlaue的值
            System.out.println(s3+"&"+s4);//杨过&小龙女,王梦成&张守慧,胡歌&刘亦菲,冷锋&龙小云
        }

        //使用增强for循环
        for (String s3 : set) {//s3是键的值
            String s4 = map.get(s3);//s4是vlaue的值
            System.out.println(s3+"&"+s4);//杨过&小龙女,王梦成&张守慧,胡歌&刘亦菲,冷锋&龙小云
        }
    }
}

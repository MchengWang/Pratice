package Summarize.Collection;

import java.util.HashSet;

public class DemoCollectionHashSet {
    /*HashSet集合存储结构：哈希表 特点：速度快
      jdk1.8 哈希表 = 数组+链表
      jdk1.8后 哈希表 = 数组+链表
               哈希表 = 数组+红黑树（提高查询速度）
      数据结构：把元素进行了分组（相同哈希值元素是一组）链表/红黑树结构把相同哈希值的元素连接起来
      两个元素不同，但哈希值相同，叫做哈希冲突
      如果链表的长度超过8位，那么就会把链表转换为红黑树（提高查询速度）
      Set集合存储元素不重复的原理 前提：存储的元素必须重写hashcode方法和equals方法*/
    public static void main(String[] args) {
        //创建HashSet集合对象
        HashSet<String> set = new HashSet<>();
        String s1 = new String("abc");
        String s2 = new String("abc");//计算哈希值，判断是否重复hashcode方法
        /*Set集合在调用add方法的时候，add方法会先调用元素的hashcode和equals方法，新判断元素是否重复
          add方法调用是s1的hashcode方法计算字符串的哈希值，如果在集合中没有找到相同哈希值的元素，那么
          就会把s1放入集合中*/
        set.add(s1);
        set.add(s2);//如果哈希值重复，就不会存储到集合中
        set.add("重地");//发现没有相同哈希值元素，就会把元素放在集合中
        set.add("通话");//哈希值相同使用equals方法返回false，就会把童话存储到集合中“重地”.equals（"通话"）
        set.add("abc");
        System.out.println(set);
    }

}



package Summarize.Collection;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class DemoCollectionSet {
    /*Set接口，一个不包含重复元素的集合（没有带索引的方法），也不能使用普通的for循环遍历
   HashSet集合： 他不保证Set的迭代顺序，哈希表结构
     特点：1、不允许存储重复的元素
          2、没有索引，没有带索引的方法，也不能使用普通的for循环遍历
          3、是一个无序的集合，存储元素和取出元素的顺序有可能不一致
          4、底层是一个哈希表结构（查询速度非常快）*/
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();
        //用add方法往集合中添加元素
        set.add("Hello");
        set.add("world");
        set.add(".");
        set.add("java");

        //使用迭代器遍历集合
        Iterator<String> it = set.iterator();
        while(it.hasNext()){
            String s = it.next();
            System.out.print(s);//worldjavaHello.
        }

        //为了方便直视结果换行显示
        System.out.println();

        //使用增强for循环
        for (String s : set) {
            System.out.print(s);//worldjavaHello.
        }
    }
}

package Summarize.Collection;

import java.util.LinkedList;

public class DemoCollectionLinkedList {
    /*LinkedList集合 （多线程） implements List集合
      底层是链表实现的，查询慢，增删快，里面包含了大量操作首尾元素的方法
      注意：使用LinkedList集合特有方法，必能使用多态
      E	pop() 从此列表表示的堆栈中弹出元素。*/
    public static void main(String[] args) {
        //创建LinkedList集合对象
        LinkedList<String> linked = new LinkedList<>();
        //使用add方法往集合中添加元素
        linked.add("a");
        linked.add("b");
        linked.add("c");
        linked.add("d");
        System.out.println(linked);//[a, b, c, d]

        //添加元素到开头
        //void addFirst​(E e) 在此列表的开头插入指定的元素。
        linked.addFirst("WWW.");
        //void	push​(E e) 将元素推送到此列表表示的堆栈上。
        linked.push("WWW.");
        System.out.println(linked);//[WWW., WWW., a, b, c, d]

        //添加元素到结尾
        //void addLast​(E e)	将指定的元素追加到此列表的末尾。
        linked.addLast(".com");
        System.out.println(linked);

        //linked.clear();//清空集合中的元素，在获取集合中的元素会抛出NoSuchElementsException

        //获取第一个元素
        //boolean isEmpty() 如果此集合不包含元素，则返回。true*/
        if(!linked.isEmpty()){

            //E	getFirst() 返回此列表中的第一个元素。
            String s = linked.getFirst();
            System.out.println(s);//WWW.

            //E	getLast() 返回此列表中的最后一个元素。
            String l = linked.getLast();
            System.out.println(l);//.com
        }

        // E	removeFirst() 删除并返回此列表中的第一个元素。
        String s = linked.removeFirst();
        System.out.println(s);//WWW.

        //E	removeLast() 删除并返回此列表中的最后一个元素。
        String l = linked.removeLast();
        System.out.println(l);//.com

        System.out.println(linked);//[WWW., a, b, c, d]
    }
}

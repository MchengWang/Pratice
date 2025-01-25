package Summarize.Collection;

import java.util.ArrayList;
import java.util.Collection;

public class DemoCollectionmain {
    /*Collection集合 即一种容器，可以用来存储多个数据 存储对象
    集合框架 单列集合 java.util.Collection 双列集合 java.util.Map
    目标：1、会使用集合存储数据   2、会遍历集合把数据取出来
    3、掌握每种集合的特性
    集合框架的学习方式
    1、学习顶层：学习顶层接口/抽象类中的共性的方法，所有子类都可以使用
    2、使用底层：底层不是借口就是抽象类，无法创建对象使用，需要使用底层的子类创建的对象使用
    Collection的常用方法
    Arraylist：底层是数组是实现的，查询快，增删慢
    Linkedlist ：底层是链表实现的，查询慢，增删快
    list集合：有索引，可以存储重复元素，可以保证存储顺序
    set集合：无索引，不可存储重复元素，存取无序
    HashSet集合：底层是哈希表+（红黑树）实现的无索引，不可以存储重复原色，存取无序
    LinkedHashSet集合： 底层是哈希表+链表实现的无索引，不可以存储重复元素，可以保证存储顺序
    TreeSet集合： 底层是二叉树实现口，一般用于排序*/
    public static void main(String[] args) {
        /* boolean add(E e) 确保此 collection 包含指定的元素（可选操作）。
        void clear() 移除此 collection 中的所有元素（可选操作）。
        boolean contains(Object o) 如果此 collection 包含指定的元素，则返回 true。
        boolean isEmpty() 如果此 collection 不包含元素，则返回 true。
        boolean remove(Object o) 从此 collection 中移除指定元素的单个实例，如果存在的话（可选操作）。
        int size() 返回此 collection 中的元素数。
        Object[] toArray() 返回包含此 collection 中所有元素的数组。 */
        //创建集合对象
        Collection<String> coll = new ArrayList<>();
        //boolean add(E e)
        coll.add("Hello");
        coll.add("World");
        coll.add(".");
        coll.add("java");
        System.out.println(coll);

        //boolean remove(Object o)
        boolean result = coll.remove(".");
        System.out.println(result);
        System.out.println(coll);

        //void clear()
        //coll.clear();
        System.out.println(coll);

        //boolean contains(Object o)
        boolean reslt = coll.contains("java");
        System.out.println(reslt);

        //boolean isEmpty()
        boolean empty = coll.isEmpty();
        System.out.println(empty);

        //int size()
        System.out.println(coll.size());

        //Object[] toArray()
        Object[] objects = coll.toArray();
        //遍历集合
        for (Object o : objects) {
            System.out.println(o);
        }
    }
}

package Summarize.Collection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class DemoCollectionList {
    /*list集合
      特点：
        1、他是一个元素存取有序的集合，例如存元素的顺序是11，22，33，那么集合中元素的存取就是按照
        11，22，33的顺序完成的
        2、它是一个有索引的集合+，通过索引就可以准确的操作集合中的元素，（与数组的索引是一个道理）
        3、集合中可以有重复的元素，通过元素Equals方法，来比较是否为重复的元素
      常用方法
        boolean	add​(E e) 将指定的元素追加到此列表的末尾（可选操作）。
        E get​(int index) 返回此列表中指定位置的元素
        E remove​(int index) 删除此列表中指定位置的元素（可选操作）。
        E set​(int index, E element) 将此列表中指定位置的元素替换为指定的元素（可选操作）。
        */

    public static void main(String[] args) {
        //创建一个list集合对象，多态
        List<String> list = new ArrayList<>();
        //使用add方法
        list.add("Hello");
        list.add("World");
        list.add(".");
        list.add("java");
        //打印集合
        System.out.println(list);//[Hello, World, ., java]不是地址值重写了toStirng方法
        //在Hello和world之间添加一个My
        list.add(1, "My");
        System.out.println(list);

        //移除元素
        String b = list.remove(1);
        System.out.println("被移除的元素是："+b);//被移除的元素是：My
        System.out.println(list);//[Hello, World, ., java]

        //把最后的java改为Java
        String s = list.set(3, "Java");
        System.out.println("被替换的元素是：" + s);//被替换的元素是：java
        System.out.println(list);//[Hello, World, ., Java]

        //List集合遍历方法有3种
        //普通for循环
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));//HelloWorld.Java
        }

        //为了方便观看，换行
        System.out.println();

        //使用迭代器
        Iterator<String> it = list.iterator();
        while(it.hasNext()){
            String is = it.next();
            System.out.print(is);//HelloWorld.Java
        }

        //为了方便观看，换行
        System.out.println();

        //使用增强for循环
        for (String s1 : list) {
            System.out.print(s1);//HelloWorld.Java
        }

        /*注意：操作索引的时候，一定防止索引越界的异常
               IndexOfBoundsException:索引越界异常，集合会报
               ArrayIndexOfBoundsException:数组索引异常
               StringIndexOfBoundsException：字符串索引异常*/
    }
}

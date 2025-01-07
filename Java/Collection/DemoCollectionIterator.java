package Summarize.Collection;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class DemoCollectionIterator {
    /*Iterator接口（迭代器）即遍历集合中的类
    Iterator<E> iterator() 返回在此 collection 的元素上进行迭代的迭代器
    迭代：即Collection集合元素的通用获取方法。再去元素之前先判断集合中有没有元素，如果有，就把这个元素
        取出来，继续判断，如果还有再取出来。一直把集合中所有元素取出，这种取出方式专业术语称作为迭代
    Iterator迭代接口的常见方法
        boolean hasNext() 如果仍有元素可以迭代，则返回 true。
        E next() 返回迭代的下一个元素。
        void remove() 从迭代器指向的 collection 中移除迭代器返回的最后一个元素（可选操作）。
    迭代器的使用原理
        1、判断集合中的下一个元素，有true，无false
        2、取出结合中的下一个元素
    Inerator是一个接口，我们无法直接使用，需使用Iterator的实现类对象，获取实现类的方法比较特殊
    Collection接口中有一个方法叫Iterator<E> iterator() 返回在此 collection 的元素上进行迭代的迭代器。
    这个方法返回的就是迭代器的实现类
     迭代器的使用步骤：
        1、使用及和中国的iterator()获取迭代器的实现类对象，使用Iterator接口接收（多态）
        2、使用Iterator接口中的hasNext（）方法判断还有没有下一个元素
        3、使用Iterator接口中的next（）方法取出即可中的下一个元素
*/
    public static void main(String[] args) {
        //创建一个集合对象
        Collection<String> coll = new ArrayList<>();
        //往集合中添加元素
        coll.add("姚明");
        coll.add("科比");
        coll.add("麦迪");
        coll.add("詹姆斯");
        coll.add("艾弗森");
        /*注意：
             Iterator接口也是有泛型的，跟着集合走，集合是什么泛型，迭代器就是什么泛型*/
        //多态接口 实现类对象 NosuchElementsException  没有元素异常
        Iterator<String> it = coll.iterator();
        //使用Iterator接口中的hasNext（）方法判断还有没有下一个元素
        boolean b = it.hasNext();
        //使用Iterator接口中的next（）方法取出即可中的下一个元素
        String s = it.next();
        System.out.println(s);
        boolean c = it.hasNext();
        String g = it.next();  //有几个人就用几次
        System.out.println(g);
        /*发现使用迭代器取出集合中的元素代码，是一个重复的过程
        所以我们可以使用循环优化
        不知集合中有多少个元素，使用While（）循环
        循环结束的条件 haxNext（）方法返回false*/

        //优化后
        while(it.hasNext()){
            String next = it.next();
            System.out.println(next);
        }

        //for循环
        for(Iterator<String> str2 = coll.iterator() ; it.hasNext();){
            String next = it.next();
            System.out.println(next);
        }



    }
}

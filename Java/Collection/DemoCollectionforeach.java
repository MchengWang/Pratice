package Summarize.Collection;

import java.util.ArrayList;

public class DemoCollectionforeach {
    /*迭代器的实现原理
     * 增强for循环（foreach循环）
     * 格式：
     * for(元素的的数据类型 ： Collection集合or数组){
     *       //方法体
     * }
     *Iterable<E> extends Collection<E> 所有的单列结合都可以使用foreach循环
     * public interface Iterator<T>实现这个接口允许成为”Foreach“语句的目标
     * 增强for循环（foreach循环）：又来遍历集合和数组 */
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6};
        for (int i : arr) {
            System.out.println(i);
        }

        //使用foreach遍历集合
        ArrayList<String> list = new ArrayList<>();
        list.add("aaa");
        list.add("bbb");
        list.add("ccc");
        list.add("ddd");
        for (String s : list) {
            System.out.println(s);
        }

        //建议日后工作或者是学习只要用到遍历及应用增强for循环（foreach）
    }
}

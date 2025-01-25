package Summarize.Collections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class DemoCollectionsSort {
    /*Comparable接口的排序规则
        自己（this）-参数，升序
        参数-自己（this），降序
    Comparable_sort（list , comparator）
    Comparable：自己（this）和别人（参数）比较，自己需实现Comparable接口，重写排序顺序comparableTo方法
    Comparator：相当于找一个第三者，比较两个*/
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        Collections.addAll(list,1,2,3,4,55,66,48);
        System.out.println(list);
        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                //return 01 - 02;
                return 02 - 01;//升序
                //return 01- 02;//降序
                //Comparator的排序规则 01-02降序 02-01升序
            }
        });
        System.out.println(list);
    }
}

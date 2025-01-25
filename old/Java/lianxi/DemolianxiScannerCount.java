package Summarize.lianxi;

import java.util.*;

public class DemolianxiScannerCount {
    /*计算一个字符串出现的次数
    1、Scanner获取字符串 aaabbbcca a4b4c2 字符不能重复，统计个数可以重复
     HashMap<Character,Integer>
    2、遍历字符串，获取每一个字符
      1、String类中的方法charArray，把字符串转换为一个字符数组，遍历集合
      2、String类中length（）+charAt（索引）
    3、使用map集合中的方法判断获取当前的字符是否存在在map集合中\
      1、使用Map集合中的方法，Containskey（获取到的字符，返回值是Boolean）
         true：字符存在
              通过key，获取vlaue
              把vlaue++
              把新的value存储到集合中
         false：字符不存在
               把字符串作为key，1作为value存储到Map集合中
      2、使用Map集合的get（key）
                返回null ，key不存在
               不是null，key存在*/
    public static void main(String[] args) {
        /*Scanner sc = new Scanner(System.in);
        System.out.println("请输入字符串");
        String s = sc.next();
        HashMap<Character , Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            if(map.containsKey(c)){
                //key存在
                Integer value = map.get(c);
                value++;
                map.put(c,value);
            }else{
                //key不存在
                map.put(c , 1);
            }
        }
        for(Character key : map.keySet()){
            Integer value = map.get(key);
            System.out.println(key+"=="+value);
        }*/

        /*jdk9对集合添加的方法进行优化_of方法
        list.set.map增加了一个静态方法of。可以给集合一次性添加多元素
        static <E> list<E> of（E...elements）
        前提：当前集合存储的个数确定了，不在改变时在使用
        注意：
        1、of方法不适用于list.set.map，不适用于接口的实现类
        2、of方法返回值是一个不能改变的集合，集合不能再使用add和put方法添加元素，会抛出异常
        3、set。map在调用of方法，不能有重复的元素，否则会抛出异常*/

        List<String> list = List.of("a","b","c","d","e","f");//使用list接口调用of方法
        System.out.println(list);

        //list.add("a");//UnsupportedOperationException不支持操作异常

        /*Set<String> set = Set.of("a","b","c","d","e","a");
        System.out.println(set);//IllegalArgumentException非法参数异常，有重复的元素*/

        /*Set<String> set = Set.of("a","b","c","d","e");
        System.out.println(set);
        set.add("c");//UnsupportedOperationException不支持操作异常*/

        Map<String,Integer> map = Map.of("a",1,"b",2);
        System.out.println(map);

        ////IllegalArgumentException: duplicate key: 张三非法参数异常，有重复的值
        Map<String,Integer> map1 = Map.of("张三",18,"张三",19);
    }

}

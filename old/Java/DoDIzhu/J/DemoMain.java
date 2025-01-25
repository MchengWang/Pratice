package Summarize.DoDIzhu.J;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class DemoMain {
    /*1、准备 54张牌存储到一个集合中
         特殊牌：大王小王
         其他52张牌： 定义一个数组/集合 存储4种花色：♠ ，♥ ，♣，♦
         定义一个数组/集合，存储13个序号A，2，3，4...J，Q，K
         循环嵌套遍历2个集合/数组 组装52张牌
         List<String> color = List.of("♠","♥","♣","♦");
         List<String> number = List.of("A","2","3","4","5","6","7","8","9","10","J","Q","K");
     2、洗牌
         使用集合工具类Collections的方法
         static void shuffle​(List<?> list) 使用默认的随机性源随机排列指定列表。
         会随机打乱集合中元素的顺序
     3、发牌
         要求：11张牌，3张底牌 一人一张,索引（0-53）%3
         定义4个集合，存储3个玩家和底牌
         索引%2有两个值（0，1）0%2=0 1%2=1 2%2=0
         索引%3有三个值（0，1，2）0%3=0 1%3=1 2%3=2 3%3=0
         索引>=51改为底牌
     4、排序
     Collections中的Sofe(List)
      5、看牌
          遍历集合，获取另外一个集合中的Key
          通过key查找value
          遍历玩家和底牌得list集合，获取map集合的key
          通过key找到value
    */
    public static void main(String[] args) {
        //创建Map集合，存储牌的索引和组装好的牌
        HashMap<Integer , String> poker = new HashMap<>();
        //创建一个集合list，存储牌的索引
        ArrayList<Integer> pokerIndex = new ArrayList<>();
        //定义两个集合，存储牌的花色和牌的序号
        List<String> color = List.of("♠","♥","♣","♦");
        List<String> number = List.of("A","2","3","4","5","6","7","8","9","10","J","Q","K");
        //把大小王放在集合中
        //定义一个牌的索引
        int index = 0;
        poker.put(index ,"大王");
        pokerIndex.add(index);
        index++;
        poker.put(index ,"小王");
        pokerIndex.add(index);
        index++;
        //循环嵌套遍历两个集合，组装52张牌，存储到集合中
        for (String s : number) {
            for (String s1 : color) {
                poker.put(index , s1+s);
                pokerIndex.add(index);
                index++;
            }
        }
        //2、洗牌使用Collections中的shuffe(List)
        Collections.shuffle(pokerIndex);
        //3、发牌定义4个集合，存储玩家和底牌的索引
        ArrayList<Integer> player01 = new ArrayList<>();
        ArrayList<Integer> player02 = new ArrayList<>();
        ArrayList<Integer> player03 = new ArrayList<>();
        ArrayList<Integer> dipai = new ArrayList<>();
        //遍历存储索引的list集合，获取每一个牌的索引
        for (Integer i : pokerIndex) {
            Integer it = pokerIndex.get(i);
            //先判断底牌
            if(i >= 51){
                //给底牌发牌
                dipai.add(it);
            }else if(i % 3 == 0){
                //给玩家1发牌
                player01.add(it);
            }else if(i % 3 == 1){
                //给玩家2发牌
                player02.add(it);
            }else if(i % 3 == 2){
                //给玩家3发牌
                player03.add(it);
            }
        }

        //4、排序使用Collections的sort<List>方法（默认是升序排序）
        Collections.sort(player01);
        Collections.sort(player02);
        Collections.sort(player03);
        Collections.sort(dipai);

        //5、看牌
        Lookpoker("刘德华" , poker , player01);
        Lookpoker("周星驰" , poker , player02);
        Lookpoker("周润发" , poker , player03);
        Lookpoker("底牌" , poker , dipai);
    }

    /*定义一个方法，提高代码的复用性
    参数 String name;玩家名
        HashMap<Integer , String> poker:存储拍的poker集合
        ArrayList<Integer> list : 存储玩家和底牌得list集合
    查表法：
    遍历玩家或者底牌索引
    使用牌的索引去Map集合中找到对应的牌*/
    public static void Lookpoker(String name , HashMap<Integer , String> poker , ArrayList<Integer> list){
        //输出玩家的,名称，不换行
        System.out.print(name);
        //遍历玩家或者底牌，索引牌的索引
        for (Integer i : list) {
            //使用索引去map集合中找到对应的牌
            String s = poker.get(i);
            System.out.print(s+"");
        }
        System.out.println();//打印每一个玩家的牌换行
    }
}

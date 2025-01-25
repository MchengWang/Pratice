package Summarize.DoDIzhu;

import java.util.ArrayList;
import java.util.Collections;

public class DemoMain {
    /*1、准备 54张牌存储到一个集合中
         特殊牌：大王小王
         其他52张牌： 定义一个数组/集合 存储4种花色：♠ ，♥ ，♣，♦
         定义一个数组/集合，存储13个序号A，2，3，4...J，Q，K
         循环嵌套遍历2个集合/数组 组装52张牌
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
     4、看牌
          直接打印集合，遍历存储玩家和底牌的集合*/
    public static void main(String[] args) {
        //1、准备
        //定义存储54张牌的Arraylist集合，泛型使用String
        ArrayList<String> poker = new ArrayList<>();
        //定义两个数组，一个数组存储牌的花色，一个数组存储牌的序号
        String[] color = {"♠","♥","♣","♦"};
        String[] number = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        //先把大小王存储搭配poker集合中
        poker.add("大王");
        poker.add("小王");
        //使用循环嵌套，遍历两个数组，组成52张牌
        for (String s : number) {
            for (String s1 : color) {
                //System.out.println(s + s1);
                //把组好的牌存在poker集合中
                poker.add(s + s1);
            }
        }
        //System.out.println(poker)

        //洗牌
        Collections.shuffle(poker);
        //System.out.println(poker);

        //发牌
        ArrayList<String> player01 = new ArrayList<>();
        ArrayList<String> player02 = new ArrayList<>();
        ArrayList<String> player03 = new ArrayList<>();
        ArrayList<String> dipai = new ArrayList<>();
        //遍历poker集合，获取每一张牌
        //使用poker集合%3给3个玩家轮流发牌剩3张底牌
        //注意：先判断底牌<i>=51>，否则牌就发没
        for (int i = 0; i < poker.size(); i++) {
            //获取每一张牌
            String p = poker.get(i);
            //轮流发牌
            if(i >= 51){
                //给底牌发牌
                dipai.add(p);
            }else if(i %3== 0){
                //给player01发牌
                player01.add(p);
            }else if(i %3== 1){
                //给player02发牌
                player02.add(p);
            }else if(i %3== 2){
                //给player03发牌
                player03.add(p);
            }
        }

        //看牌
        System.out.println("刘德华"+player01);
        System.out.println("周润发"+player02);
        System.out.println("周星驰"+player03);
        System.out.println("底牌"+dipai);
    }
}

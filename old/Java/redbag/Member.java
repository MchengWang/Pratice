package Summarize.redbag;

import java.util.ArrayList;
import java.util.Random;

public class Member extends user {
    public Member(){}
    public Member(String name , int money){
        super(name, money);
    }
    public void recelve(ArrayList<Integer> list){
        //从红包中抽一个
        //随机获得一个索引，从集合中
         Random a = new Random();
         int index = a.nextInt(list.size());
        //根据索引删除集合中你所抽到的，并把红包给自己
        int delta = list.remove(index);
        //当前成员有多少钱
        int money = super.getMoney();
        //加法并重设
        super.setMoney(money + delta);
    }
}

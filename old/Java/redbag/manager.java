package Summarize.redbag;

import java.util.ArrayList;

public class manager extends user{
    public manager(){}

    public manager(String name , int money){
        super(name, money);
    }

    public ArrayList<Integer> send(int totalmoney , int count){
        //用一个集合存储红包金额
        ArrayList<Integer> list = new ArrayList<>();
        //首先看一下发红包的人有多少钱
        int lefotmoney = super.getMoney();//查看发红斑的人的余额
        if(totalmoney>lefotmoney){
            System.out.println("余额不足");
            return list;
        }
        super.setMoney(lefotmoney-totalmoney);
        int arg = totalmoney/count;
        int mod = totalmoney%count;//余额即零头

        //剩下零头包在最后一个红包中
        for (int i = 0; i < count - 1; i++) {
            list.add(arg);
        }

        //最后一个红包
        int last = arg+mod;
        list.add(last);
        return list;
    }

}

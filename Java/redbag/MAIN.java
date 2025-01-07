package Summarize.redbag;

import java.util.ArrayList;

public class MAIN {
    public static void main(String[] args) {
        manager m = new manager("法人",100);
        Member o = new Member("收人",0);
        Member t = new Member("收人",0);
        Member T = new Member("收人",0);
        m.show();
        o.show();
        t.show();
        T.show();
        System.out.println("====================");
        //发20元红包三个
        ArrayList<Integer> list = m.send(20,3);
        //三个人收
        o.recelve(list);
        t.recelve(list);
        T.recelve(list);
        m.show();
        o.show();
        t.show();
        T.show();
    }
}

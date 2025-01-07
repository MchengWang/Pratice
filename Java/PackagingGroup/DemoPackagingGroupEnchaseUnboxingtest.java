package Summarize.PackagingGroup;

import java.util.ArrayList;

public class DemoPackagingGroupEnchaseUnboxingtest {
    //自动装箱和自动拆箱
    //基本类型数据和包装类之间的自动的互相转换
    public static void main(String[] args) {
        //自动装箱：直接把证书赋值给包装类
        Integer in = 1; //相当于Integer in= new Integer(1);
        //自动拆箱：in是包装类，无法直接运算，可以自动转化为基本类型数据并计算
        //in+2相当于 in.intvalue(1+2=3)
        //in = in+2;相当于 in = new Integer(3); 自动装箱
        //Arraylist集合无法直接存储整数，可以存储Integer包装类
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1); //自动装箱  list.add(new Integer(1));
        int a = list.get(0); //自动拆箱 list.get(0).invalue();

    }
}

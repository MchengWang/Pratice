package Summarize.PackagingGroup;

public class DemoPackagingGroupunboxing {
    /*拆箱：在包装类中取出基本类型的数据（包装类 --> 基本类型的数据）
    * 成员方法
    * int intvalue 以int类型返回Integer的值*/
    public static void main(String[] args) {
        //装箱
        Integer it = new Integer(1);//方法上有横线，说明方法过时了
        System.out.println(it);//重写了toString方法
        Integer ie = new Integer("1");
        System.out.println(ie);
        //静态方法
        Integer ig = Integer.valueOf(1);
        System.out.println(ig);
        //Integer in = Integer.valueOf("a");//NumberFormatException:数字格式化错误异常
        Integer in1 = Integer.valueOf("1");
        System.out.println(in1);
        //拆箱
        int i = in1.intValue();
        System.out.println(i);
    }
}

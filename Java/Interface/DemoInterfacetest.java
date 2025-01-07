package Summarize.Interface;

public class DemoInterfacetest {
    public static void main(String[] args) {
        DemoInterfaceImpl impl = new DemoInterfaceImpl();
        impl.abs1();
        impl.xs();//如果实现类里没有，向上找接口
        DemoInterface.dc();//静态方法直接从接口中调用
        /*访问接口中的常量
        * 格式：
        * System.out.println(MyInterfaceCount.NUM_OF_MY_CLASS)
        * MyInterfaceCount: 接口名称
        * NUM_OF_MY_CLASS： 接口中的常量*/
        System.out.println(DemoInterface.AW_OF_MY_INTERFACE);

        //调用实现多个接口的实现类
        DemoInterfaceMultipleImpl Dimi = new DemoInterfaceMultipleImpl();
        Dimi.abs1();
        Dimi.sd();
    }
}

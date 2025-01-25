package Summarize.Interface;

public class DemoInterfaceMultipleImpl implements DemoInterface ,DemoInterface1{

    /*继承父类，实现多个接口
    1、接口是没有静态代码块的或者构造方法
    2、一个类的直接父类是唯一的，但一个类可以同时实现多个接口
    3、如果实现类所实现的多个接口，有重复的抽象方法时，只需覆盖重写一次即可
    4、如果实现类没有覆盖重写所有的接口中的抽象方法，那么实现类必须是一个抽象类
    5、如果实现类所实现的多个接口中，存在重复的默认方法，那么实现类一定要对冲突的默认方法进行覆盖重写
    6、一个类如果父类当中的方法和接口中的默认方法产生了冲突，优先使用父类中的方法
    接口之间的多继承
    1、类与接口之间是单继承，直接父类有一个
    2、类与接口之间是多实现的，一个类可以实现多个接口
    注意事项：
    1、多个父类接口当中的抽象方法重复，没关系
    2、多个父类接口当中的默认方法重复，那么子类接口必须进行默认方法的覆盖重写，【而且也要带着default关键字】*/
    @Override
    public void abs1() {
        System.out.println("你好");
    }

    @Override
    public void sd() {
        System.out.println("Hello world");
    }
}

package Summarize.Generics;

public interface DemoGenericsInterface<I>{
    /*定义和使用含有泛型的接口
    格式：修饰符 interface 接口名称<代表泛型的变量>{

    }
    */
    //有两种方式1、创建实现类，指定数据的类型
    public abstract void method(I i);

    //第二种方式，接口使用什么类就用什么类

}

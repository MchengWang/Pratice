package Summarize.Collection;

public class DemoCollectionHashvalue {
    /*哈希值是一个十进制的整数，由系统随机给出（就是对象的地址值，是一个逻辑地址，是模拟出来的地址
    ，不是数据存储的物理地址）
    在object类中有一个方法，可以获取对象的哈希值
        int	hashCode() 返回对象的哈希代码值。
        hashcode（）的源码：public native int hashCode();
        native：代表该方法调用的是本地操作系统的方法*/
    public static void main(String[] args) {
        //Person extends Object,可以使用object的方法
        Person p = new Person();
        int i = p.hashCode();
        System.out.println(i);//1028214719

        //Stirng 类重写了HashCode方法
        String s2 = "ab";
        String s1 = "cd";
        System.out.println(s2.hashCode());//3105
        System.out.println(s1.hashCode());//3169
    }
}

class Person extends Object{
    public static void xs(){
        System.out.println("Hello World");
    }
}

package Summarize.BeinTransition;

public class DemoUpwardtransformation {
    public static void main(String[] args) {
        /*向上转型既是多态的写法 即父类指向子类
        父类名称 对象名 = new 子类名称（）；
        含义：右创建一个子类对象，把它当作父类来使用
        弊端：向上转型为父类，那就无法拥有子类原本特有内容
        注意事项：
        向上转型一定是安全的，从小范围扩大到大范围*/
        fu ZI = new zi();
        ZI.fx();
        zi.ko();
    }
}
abstract interface fu{
    void fx();
}

class zi implements fu{

    @Override
    public void fx() {
        System.out.println("你好");
    }

    public static void ko(){
        System.out.println("Hello World");
    }
}

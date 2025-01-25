package Summarize.Object;

public class DemoObjectStatic {
    static String name;

    //静态代码块
    /*格式 当第一次使用本类静态代码只执行唯一的一次
        修饰符 class 类名称{
     static {}//静态代码块的内容
     }*/
    static{
        System.out.println(name + "静态");
    }
    public DemoObjectStatic(String a){
        name = a;
        System.out.println(name + "构造方法");
    }
    public void method(){
        System.out.println(name + "成员方法");
    }

    public static void main(String[] args) {
        DemoObjectStatic t = new DemoObjectStatic("c");
        t.method();
    }
}

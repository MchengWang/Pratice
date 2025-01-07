package Summarize.Extends;

public class DemoExtendstest {
    public static void main(String[] args) {
        phone Phone = new phone();//创建老手机对象
        Phone.call();
        Phone.show();
        Phone.cend();
        System.out.println("=================");
        Newphone i = new Newphone();
        Newphone.call();
        Newphone.show();
        Newphone.cend();
    }
}

//创建老手机父类
 class phone{
    public static void call(){
        System.out.println("打电话");
    }
    public static void cend(){
        System.out.println("发信息");
    }
    public static void show(){
        System.out.println("显示号码");
    }

}

//创建新手机子类
class Newphone extends phone{

    public static  void show(){
        phone.show();//把父类的show方法拿来重复利用
        System.out.println("显示名称");
        System.out.println("显示头像");

    }
}



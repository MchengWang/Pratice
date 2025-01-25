package Summarize.Extends;

public class DemoExtends {

    /*父类定义格式
    * 修饰符 class 父类名称{ //... }
    * 子类定义格式
    * 修饰符 class 子类名称 extends 父类名称{ //... }*/
    public static void main(String[] args) {
        Demozi zi = new Demozi();
        zi.xs();
    }
}
class Demozi extends Demofu{

}
class Demofu{
    public void xs(){
        System.out.println("你好");
    }
}

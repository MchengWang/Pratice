package Summarize.Polymorphism;

public class DemoPolymorphism {
    public static void main(String[] args) {

        /*多态的前提：必须是Extends或者Implements的类
        多态即；由父类指向子类 由接口指向实现类
        格式：
        父类名称 对象名 = new 子类名称（）
        接口名称 对象名 = new 实现类名称（）
        成员变量的特点
        1、直接通过对象名称访问，成员变量看符号左边是谁就先用谁，没有在向上找
        2、直接通过成员方法访问，成员变量看该方法是谁就优先使用谁，没有则向上找
        子类没有覆盖重写就是父  子类覆盖重写就是子
        成员方法的使用特点：new的是谁，没有规则想上找*/
        fu zi = new Zi();//多态
        zi.fx();//父子都有，优先用子
        zi.fg();//子类没有，想上找到父类
        /*口诀：编译看作左边，运行看右边
        * 对比 ：
        * 成员变量 左左
        * 成员方法 左右
        * 使用多态的好处：无论右边new的时候，换成那个子类对象，等号左边调用方法都不会变化*/
    }
}
 abstract class fu {
     public abstract void fx();
     public void fg(){
         System.out.println("Hello World");
     }
 }

 class Zi extends fu{

     @Override
     public void fx() {
         System.out.println("你好");
     }
 }

package Summarize.Extends;
/*super的三种用法
1、在子类的成员方法中，访问父类的成员变量
2、在子类的成员方法中，访问父类的成员方法
3、在子类的构造方法中，访问父类的构造方法
  this的三种用法
1、在本类的成员方法中，访问苯类的另一个成员方法
2、在本类的成员方法中，访问本类中另一个成员变量
3、在本类的构造方法中，访问本类中的另一个构造方法
 */

public class DemoExtendsSuper {
    public static void main(String[] args) {
        zi ZI = new zi();
        System.out.println(ZI.num);
        ZI.method();
        ZI.methodzi();
    }

}

//创建父类
class fu{
    int num = 20;//成员变量
    public void method(){//成员方法
        System.out.println("你好");
    }
    public fu(){//构造方法
        System.out.println("Hello World");
    }
}

//创建子类对象
class zi extends fu{
     int num = 20;//子类中的num值

     public zi(){
         super();//父类中的构造方法
     }

     public void methodzi(){
         System.out.println(super.num);//父类的num值
     }

     public void method(){
         super.method();//访问父类中的method方法
         System.out.println("子类方法");
     }
}

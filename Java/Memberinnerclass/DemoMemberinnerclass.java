package Summarize.Memberinnerclass;

public class DemoMemberinnerclass<Outer> {
    private String name;//外部类的成员变量
    int num = 30;

    public DemoMemberinnerclass(){}

    public DemoMemberinnerclass(String name){
        this.name = name;
    }
    public void setName(String name){
        this.name = name;
    }
    public String getname(){
        return name;
    }

    public static void main(String[] args) {
        /*成员内部类的概述：如果一个事物内部包含另一个事物，那么这就是一个类的内部包含另一个类
        分类：成员内部类 局部内部类（匿名内部类）
        成员内部类格式：
        修饰符 class 外类名称{
            修饰符 class 内类名称{
                //...
            }
            //...
        }
        注意：内用外可以随意访问，外用内，一定要借助内部类对象
        成员内部类的使用
        1、在外部类的方法当中，使用内部类，然后main只是调用外部类的方法（直接调用）
        直接方式 格式：
        外部类名称.内部类名称 对象名 = new 外部类名称（）.new内部类名称（）；*/
        DemoMemberinnerclass.demo de = new DemoMemberinnerclass().new demo();
        de.fx();
        //内部类的同名变量访问
    }
     public class demo{//内部类
        int num = 20;//内部类的成员变量
        public void sz(){
            //内部类方法中的局部变量
            int num = 10;
            System.out.println(num);//本方法中的局部变量
            System.out.println(this.num);//内部类的成员变量
            //如果出现重名变量
            //格式：外部类名称.this.成员变量名称
            System.out.println(DemoMemberinnerclass.this.num);
        }
        public void fx(){
            System.out.println("你好");
        }
     }
     //外部类的方法
    public void gu(){
        System.out.println("Hello world");
    }

}

package Summarize.Memberinnerclass;

public class DemoMenberberinnerinclass {
    public static void main(String[] args) {
        /*局部内部类的定义
        如果一个类是定义在一个方法内部的，那么这就是一个局部内部类
        ’局部‘，只有当前所属的方法才能使用他，出了这个方法外卖呢就不能用了
        格式：
        修饰符 class 外部类名称{
            修饰符 返回值类型 外部类方法名称（参数列表）{
                class 局部内部类名称{
                    //...
                }
            }
        }
        定义一个类的时候，权限修饰符规则
        1、外部类 public/（default）
        2、内部类 public/protected/（Default）/private
        局部内部类： 什么都不能写，跟（Default）不一样 根据类的种类选择权限修饰符
        局部内部类的final问题 如果希望访问所在方法的局部变量，那么这个局部变量必须是[有效final的]
        备注：从java 8+开始，只要局部变量事实不变，那么final关键字可以省略
        原因：1、new出来的对象在堆内存中
        2、局部变量是跟着方法走的，在栈内存中
        3、方法结束后，立刻出栈，局部变量就会消失
        4、但是new出来的对象会在堆当中持续存在，知道垃圾回收消失*/

        //使用局部内部类
        DemoMenberberinnerinclass du = new DemoMenberberinnerinclass();
        du.method();
    }

    public void method(){
        class gu{
            int num = 10;
            public void du(){
                System.out.println(num);
            }
        }
        gu hi = new gu();
        hi.du();
    }
}

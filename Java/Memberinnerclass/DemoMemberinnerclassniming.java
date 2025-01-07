package Summarize.Memberinnerclass;

import Summarize.Interface.DemoInterface;
import Summarize.Interface.DemoInterface1;
import Summarize.Interface.DemoInterface;
import Summarize.Interface.DemoInterface1;

public class DemoMemberinnerclassniming {
    public static void main(String[] args) {
        /*匿名内部类（重点） 如果接口的实现类或者弗父类的子类只需使用一次那么这种情况下，就可以省略该类的定义
        ，而改为使用[匿名内部类]
        格式：
        接口名称 对象 = new 接口名称（）{
            //覆盖重写所有的抽象方法
        }；（这个分号一定不要忘记写）
        解析：
        1、new代表创建对象的动作
        2、接口名称可就是匿名内部类需要实现那个接口
        3、{。。。}才是匿名内部类中的内容
        注意事项：
        1、匿名内部类，在创建对象的时候，只能使用唯一的一次，如果希望多次创建对象，而且类的内容一致的话，
        那么就必须使用单独定义的实现类了
        2、匿名对象，在（调用方法）时，只能用唯一一次
        如果同一个对象，调用多次方法，那么就必须给对象起个名字
        3、匿名内部类是省略了（实现类/子类名称），但是匿名对象是省略了（对象名称）
        强调：匿名内部类和匿名对象不是一回事*/
        DemoInterface di = new DemoInterface()  {//使用匿名内部类
            @Override
            public void abs1() {
                System.out.println("你好");
            }
        };//分号一定记住不要忘记写了

        //调用匿名内部类的方法
        di.abs1();

        new DemoInterface1(){//使用匿名对象的方法调用DemoInterface1中的sd（）方法

            @Override
            public void sd() {
                System.out.println("Hello world");
            }
        }.sd();
    }
}

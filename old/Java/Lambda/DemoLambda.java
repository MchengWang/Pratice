package Summarize.Lambda;

public class DemoLambda {
    /*lambda表达式
    函数式编程思想概述
        函数就是有输入量，输出量的一套计算方案，也就是“拿什么东西做什么事”。相对而言，面向对象过分强调
        “必须通过对象的形式来做事情”，而函数式思想尽量忽略面向对象的复杂语言--强调做什么，而不是以什么形式去做
    面对对象的思想：做一件事情，找一个能解决这个事情的对象，调用对象的方法完成事情
    函数式编程思想：只要获取到结果，谁去做，怎么做的都不重要，重要的是结果，不重视过程
    */

    public static void main(String[] args) {
        //冗余的Runnable代码  冗余（多余）
        //使用匿名内部类创建新线程
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName()+"新的线程启动了");
            }
        }).start();

        /*分析：
        1、Thread类需要Runnable接口作为参数，其中的抽象方法run方法是用来指定线程任务内容的核心
        2、为了指定的run的方法体，不得不需要Runnable接口的实现类
        3、为了省去定义一个RunnableImpl实现类的麻烦，不得不使用匿名内部类
        4、必须覆盖重写抽象run方法，所以方法名称，方法参数，方法返回值不得不再写一遍，且不能写错
        5、而实际上，似乎只用方法体才是关键所在
        编程思想转换&lambda的更优写法
        编程思想：做什么而不是怎么做 将关注点从“怎么做”回到“做什么”的本质上，就会发现只要能够更好的达成目的，过程和形式其实并不重要
        2014年3月Oracle所发布的java8（jdk1.8）中，加入lambda表达式的重量级新特性，为我们打开了新世界的大门
        lambda表达式更优写法体验
        */
        new Thread(()->{
            System.out.println(Thread.currentThread().getName());
        }).start();
        /*等价于*/
        new Thread(()-> System.out.println(Thread.currentThread().getName())).start();

        /*lambda*/
    }
}

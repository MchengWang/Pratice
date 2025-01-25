package Summarize.Thread;

public class DemoThreadInterfaceRunnableImpl {
    /*匿名内部类方法实现多线程的创建
        匿名：没有名字
        内部类：写在其它类内部的类
        匿名内部类：简化代码
                 把子类继承父类，重写父类的方法，创建子类对象一步完成
                 把实现类实现接口，重写接口中的方法，创建实现类队形合成一步完成
        匿名内部类的最终产物：子类/实现类对象，而这个类没有名字
        格式：new 父类名称/接口名称{
            重写父类和接口中的方法
        }*/
    public static void main(String[] args) {
        new Thread(){//线程父类为Thread
            //重写run方法

            @Override
            public void run() {
                for (int i = 0; i < 20; i++) {
                    System.out.println(Thread.currentThread().getName()+"-->"+"黑马");
                }
            }
        }.start();

        //线程接口Runnable
        Runnable r = new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 20; i++) {
                    System.out.println(Thread.currentThread().getName()+"-->"+"程序员");
                }
            }
        };
        new Thread(r).start();

        //简化接口的方式
        new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 20; i++) {
                    System.out.println(Thread.currentThread().getName()+"-->"+"黑马程序员");
                }
            }
        }).start();
    }
}

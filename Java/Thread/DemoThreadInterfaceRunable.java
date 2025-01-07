package Summarize.Thread;

public class DemoThreadInterfaceRunable {
    /*创建多线程程序的第二种方法_实现Runnable接口
    Runnable接口应有那些打算通过某一线程执行其实例的类实现。类必须定义一个称为run的无参构造方法
    java.lang.Thread 的构造方法
         Thread​(Runnable target)	分配新对象。Thread
    实现步骤
       1、创建Runnable实现类
       2、重写run方法
       3、创建Runnable实现类对象
       4、使用Thread中的对象构造方法中传递Runnable实现类对象
       5、调用Thread类中的start方法，开启新线程执行run方法

    Thread和Runnable的区别
       实现Runnable的好处
          1、避免了单继承的局限性
             一个类只能继承一个类（一人只有一个爹），类继承了Thread类就不能继承其他类
             实现Runnable，还可以继承其他类，实现其他接口
          2、增强程序的扩展性，降低了程序的耦合性（解耦）
             实现Runnable，把设置的县城任务和开启线程进行了分离（解耦）
             实现类中，重写了run方法，用来设置线程任务
             创建Thread对象，调用start方法，开启新线程*/
}

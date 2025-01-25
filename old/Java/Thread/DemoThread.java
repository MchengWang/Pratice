package Summarize.Thread;

public class DemoThread {
   /*Thread类
     构造方法：
     Thread()	分配新对象。Thread
     Thread​(Runnable target)	分配新对象。Thread
     Thread​(Runnable target, String name)	分配新对象。Thread
     Thread​(String name)	分配新对象。Thread
     常用方法：
     String	getName()	返回此线程的名称。
     void	run()	如果此线程是使用单独的 run 对象构造的，则调用该对象的方法;如果使用单独的 run 对象构造
     ，则调用该对象的方法。否则，此方法不执行任何操作并返回。RunnableRunnablerun
     static Thread	currentThread()	返回对当前正在执行的线程对象的引用。
     static void	sleep​(long millis)	使当前执行的线程在指定毫秒数下处于睡眠状态（暂时停止执行），但
     须视系统计时器和调度器的精度和准确性。
   线程的名称
     主线程 main  新线程Thread-0，Thread-1，Thread-2
     static Thread	currentThread()	返回对当前正在执行的线程对象的引用。的简化使用
     Thread.currentThread().getName();//链式编程
   Thread中设置新线程名称的方法
     1、使用Thread类中的SetName（名字）
     void	setName​(String name)	将此线程的名称更改为等于 参数。name
     2、创建一个带参数的构造方法，参数传递线程的名称，调用的弗雷德带参构造方法，把线程名传递给父类，让父类（Thread）
     给子线程起一个名字
     Thread​(String name)	分配新对象。Thread
     */

    public static void main(String[] args) {
        //常用方法sleep的使用案例
        for (int i = 1; i <= 60; i++) {
            System.out.println(i);
            //使用Thread中的sleep方法让程序睡眠一秒钟
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}

package Summarize.Thread;

public class DemoThreadwaitforwakeup {
    /*等待唤醒案例（线程之间的通信）
      创建一个顾客线程，告知需求，使用wait方法放弃cpu执行，进入WAITING状态（无限等待状态）
      创建一个生产者线程，化5秒做，做好调用notify方法，唤醒顾客线程吃包子
    注意：
      顾客和老板线程必须使用同步代码块包裹，保证等待唤醒只能有一个执行
      同步使用的锁对象必须保证唯一
      只有锁对象才能调用wait和notify方法

    Object类中的方法
        void	notify()	唤醒等待此对象的监视器上的单个线程。
        void	wait()	导致当前线程等待，直到它被唤醒，通常是通过通知或中断。
    */
    public static void main(String[] args) {
        //创建锁对象
        Object obj = new Object();

        //创建顾客线程
        new Thread(){
            @Override
            public void run() {
                synchronized (obj){//使用同步技术
                    System.out.println("猪肉大葱");
                    //调用wait
                    try {
                        obj.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println("开吃");
                }
            }
        }.start();

        //创建生产者线程
        new Thread(){
           
            @Override
            public void run() {
                System.out.println("包子好了");
                //调用notify
                obj.notify();//用谁等待，用谁结束
            }
        }.start();
        /*进入TIMEWAITING（计时等待）两种方式
             1、sleep(long l)在毫秒值结束之后，县城睡醒进入Runnable/BLOCKED状态
             2、wait(long m)wait方法在毫秒值结束之后，还没被notify唤醒，就会自己醒来会
             进入Runnable/BLOCKED状态
        唤醒的方法
             void	notify()	唤醒等待此对象的监视器上的单个线程。
             void	notifyAll()	唤醒等待此对象的监视器的所有线程。
        */
    }
}

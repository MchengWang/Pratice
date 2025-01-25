package Summarize.Thread;

public class DemoThreadSafeMethod {
    /*注意：线程安全问题是不能产生的，我们可以让一个线程在访问共享数据的时候，无论是否失去了
    CPU的执行权，让其他线程只能等待，等待当前线程卖完票，其他线程在进行卖票
    保证：使用一个线程再买票*/

    /*线程同步：
    同步代码块   格式synchronized(同步锁){需要同步操作的代码}
    注意：1、同步代码块中的锁对象，可以使用任意的对象
         2、但是必须把保证两个线程使用的锁的对象是一个
         3、锁对象作用：把同步代码块锁住，只让一个线程在同步代码块中执行
    同步技术原理
         总结:同步中的线程，没有执行完毕不会释放锁，同步外的线程没有锁对象进不去同步
         同步保证了只能偶一个线程在同步中执行共享数据，保证了安全
     弊端：
         程序频繁的判断锁，获取锁，释放锁，程序的效率会降低
    同步方法：
         格式 修饰符 synchronized 返回值类型 方法名（参数列表）{
            可能会产生线程安全的代码
         }
    使用步骤：
         1、把访问的共享数据的代码抽取出来，放到一个方法中
         2、在方法上添加synchronized关键字*/
    private int ticket = 100;

    public synchronized void method(){
        //先判断票是否存在
        if(ticket > 0){
            //提高安全问题，让程序睡觉
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            //票存在，卖票ticket--
            System.out.println(Thread.currentThread().getName()+"正在卖第"+ticket+"张票");
            ticket --;
        }
        /*同步方法也会把方法内部的代码锁住，只让一个线程执行，同步方法所对象是谁，是实现类对象
        new RunnableImpl(),也就是this*/
    }
}

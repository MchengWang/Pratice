package Summarize.Thread;

public class DemoThreadWaitForTheWakeUpMechanism {
    /*等待唤醒机制（线程之间的通信）
    重点：有效的利用资源
    使用方法 wait() notify() notifyAll();
    注意：哪怕只通知了一个等待线程，被通知县城也不是立即恢复执行，因为他当初中断的地方
         是在同步块内，而此刻他已经不持有锁了，所以他需要再次尝试去获取锁（很可能面临
         其他线程的竞争，成功以后才能在当初调用wait方法之后的地方恢复执行）
    总结如下：
      1、如果能获取锁，锁程就从WAITING状态变成RUNNABLE状态
      2、否则，从Wait Set出来，又进入entry set，线程就从WAITING状态又变成了RUNNABLE状态
    调用wait和notify需要注意的细节
      1、wait方法与notify方法，必须同用一个锁对象调用，因为：对应的锁对象可以通过notify唤醒使用同一个
        锁对象，调用wait方法后的线程
      2、wait方法与notify方法，都属于Object类的方法，因为：锁对象可以的是任意对象，而任意对象所属类都
        是继承了Object的
      3、wait方法与notify方法，必须要在同步代码块或同步函数中，因为；必须通过锁对象调用这个方法
    等待唤醒机制需求分析
      资源类（包子类） 设置包子属性：外皮，馅  包子的状态：有true 无false，初始值为false
      生产者（包子铺）是一个线程，可继承Thread或者实现Runnable
                   设置线程任务（RUN）：生产包子
                   对包子的状态进行判断 true有包子 包子铺调用wait方法进入等待
                                    false没有包子包子铺生产包子 增加一些趣味性 交替生产两种包子
                                                 有两种状态（i%2==0）
                                                 包子铺生产包子，修改包子的状态为true 有
                                                 唤醒吃货线程，让吃货线程吃包子
      吃货线程（消费者）是一个线程类，可继承Thread或者实现Runnable
                    设置线程任务（RUN）：吃包子
                    对包子的状态进行判断false：无包子 调用wait方法进行等待
                                    true：有包子，吃货吃包子，吃货吃完包子，修改包子的状态为false
                                          没有吃货线程唤醒包子铺线程做包子

     测试类：
          包含main方法，程序执行的入口，启动程序
          创建的对象，创建包子铺线程和吃货线程：开启*/
}

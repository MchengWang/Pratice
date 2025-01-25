package Summarize.Thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class DemoThreadpool {
    /*线程池：
           其实就是一个容纳多个线程的容器，其中的线程都可以反复使用，省去频繁创建线程对象的操作，无需反复创建线程而消耗过多的资源
    线程池-->容器-->集合（ArryaList，HashSet，LinkedList<Thread>,HashMap）
      当线程第一次启动的时候，创建多个线程，保存到一个集合中，当我们想使用线程的时候，就可以从集合中取出线程使用
      Thread t = list.remove(0);返回的是被构造方法移除的元素（线程只能被一个任务所使用）
      Thread t1 = Linked.removeFist();
      当我们使用完毕线程，需把线程规范给线程池
      list.add(t);
      Linked.add(t1);
   在jdk1.5之后，JDK内置了线程池，我们可以直接使用，java.util.concurrent.exectars线程工程类，生存线程池
   好处：
       1、降低资源消耗，减少了创建和销毁线程的次数，每个工作线程可以被重复利用，可执行多个任务
       2、提高相应的速度，当任务到达时，任务可以不需要的等到线程创建就能应即执行
       3、提高现成的可管理性，可以根据系统的承受能力，调整线程池中工作线程的数组，防止因为消耗过多
          的内存，把服务器累趴下，（每个线程大概1MB内存，线程开得越多，消耗的内存也就越大，最后死机）
   线程池代码的实现
       Executor类中的静态方法
       static ExecutorSerive newFixedThreadPool(int nThreads)创建一个可重用固定显成熟的线程池
       参数：int nThreads：创建线程池中包含的线程数量
       返回值类型：ExcecutorSerive接口，返回的是ExecuptorSerive接口的实现类对象，我们可以使用ExcecutorSerive
                 接口接收（面向接口编程）
       java.util.courrent.Excecutor.ExcecutorSerive:线程池接口
       用来从线程中获取线程，调用start方法，执行线程任务
         Submit(Runnable task)提交一个Runnable任务用于执行
         void shudown() 关闭/销毁线程池的方法
   线程池的使用步骤
      1、使用线程池工厂类Exectors里的静态方法newFixedThreadPool生产一个指定数量的线程池
      2、创建一个类，实现Runnable接口，重写Run方法，这之线程任务
      3、调用ExecutorSerive中的方法，submit传递线程任务，开启线程执行run方法
      4、调用EectorsSerive中的shudown方法销毁线程池（不建议执行）*/

    public static void main(String[] args) {

        //1、使用线程池工厂类Exectors里的静态方法newFixedThreadPool生产一个指定数量的线程池
        ExecutorService es = Executors.newFixedThreadPool(2);

        //2、创建一个类，实现Runnable接口，重写Run方法，这之线程任务
        Thread t = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 20; i++) {
                    System.out.println("黑马程序员"+i);
                }
            }
        });

        //3、调用ExecutorSerive中的方法，submit传递线程任务，开启线程执行run方法
        es.submit(t);

        //4、调用EectorsSerive中的shudown方法销毁线程池（不建议执行）
        //es.shutdown();

        //es.submit(t);抛异常，线程池也就没有了就不能获得线程
    }
}


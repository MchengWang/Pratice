package Summarize.Thread;

public interface DemoThreadsafe {
    //线程安全的代码实现
    public static void main(String[] args) {
        //模拟卖票
        //chuangjianRunnable接口的实现类对象
        RunnableImpl run = new RunnableImpl();
        //创建Thread类，构造方法中传递Runnable实现类对象
        Thread t0 = new Thread(run);
        Thread t1 = new Thread(run);
        Thread t2 = new Thread(run);
        //调用start方法开启多线程
        t0.start();
        t1.start();
        t2.start();
    }
}

class RunnableImpl implements Runnable{

    //设置一个多线程共享的票源

    private int ticket = 100;



    //设置线程任务
    @Override
    public void run() {
        //使用死循环,让卖票操作重复执行
        while(true){

                //先判断票是否存在
                if(ticket > 0){
                    //票存在，买票ticket--
                    System.out.println(Thread.currentThread().getName()+"-->正在卖第"+ticket+"张票");
                    ticket -- ;
                }
        }
    }
}

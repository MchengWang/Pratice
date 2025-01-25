package Summarize.Thread;

import java.util.concurrent.locks.ReentrantLock;

public class DemoThreadSafeLock {
    /*lock锁 java.util.concurrent.locks.lock接口
          lock实现提供了比使用syniocroized方法和语句可获得的更广泛的锁定操作
    lock锁中的方法
        void	unlock()	松开锁。
        void	lock()	获取锁
    java.util.concurrent.locks.reentratlock implements lock接口
    使用步骤：
        1、在成员位置创建一个reentrantlock对象
        2、在可能出现问题代码前调用lock接口中的方法lock获取锁
        3、在可能出现问题代码后调用lock接口中的方法unlock释放锁*/
    private static int ticket1 = 100;
    public static void main(String[] args) {
        ReentrantLock lock = new ReentrantLock();
        lock.lock();
        try{
            Thread.sleep(10);
            System.out.println(Thread.currentThread().getName()+"第"+ticket1+"张票");
        }catch(InterruptedException e){
            e.printStackTrace();
        }finally{
            lock.unlock();//无论程序异常都会把锁释放
        }
    }
}

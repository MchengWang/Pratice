package Summarize.Recursive;

public class DemoRecursive {
    /*递归：指方法调用自己
   分类：直接和间接
   直接递归：方法自己调用自己
   简介递归：A调用B B调用A相当于A在使用A
   注意事项：
     递归一定要有条件限制，保证递归能停下来，否则会发生栈内存溢出
     在递归中虽然优先条件，但是递归次数不能太多，否则也会发生栈内存溢出
     构造方法，禁止递归
   递归的使用前提：                           StackOverException
     当调用方法的时候，方法的主体不会变，每次调用方法的参数不同，不能使用递归*/
    public static void a(int a){
        System.out.println(a);
        if(a == 10){
            return ;//结束
        }
        a(++a);
    }

    /*编译错误：构造方法是创建对象使用的，一直递归会导致内存中有多个对象，直接编译报错*/
}


package Summarize.Recursive;

public class DemoRecursivePractice {
    /*使用递归计算1-n的和
    定义一个方法，使用递归计算1-n之间的和
    1+2+3+...+n
    n+(n-1)+...+1
    已知：最大值：n
         最小值：1
    使用递归必须明确
         1、递归的结束条件：获取到1的时候结束
         2、递归的目的，获取下一下被加的数字（n-1）*/

    //定义一个方法使用递归
    public static int sum(int n){
        if(n == 1){
            return 1;
        }
        return n + sum(n-1);
    }

    public static void main(String[] args) {
        System.out.println(sum(100));
        System.out.println(jcc(5));
    }

    /*注意：使用递归求和，main方法调用sum，sum方法会一直调用sum
           导致内存有多个sum方法，频繁的创建方法，调用方法，销毁方法，效率低下
           如果仅是计算1-n之间的和，不推荐使用递归，使用for循环即可
    */

    /*使用递归计算阶乘 n！=n*(n-1)*...*1;
    * 递归结束的条件（所有小于及该等于该数的正整数的积）
    * 递归的目的：获取下一个被乘数与（n-1）*/
    public static int jcc(int a){
        //获取为1的时候结束
        if(a == 1){
            return 1;
        }

        return a * jcc(a - 1);
    }

}

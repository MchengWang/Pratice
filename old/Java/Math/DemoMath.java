package Summarize.Math;

public class DemoMath {
    public static void main(String[] args) {
        //获取绝对值
       /* static double abs(double a) 返回 double 值的绝对值。
        static float abs(float a) 返回 float 值的绝对值。
        static int abs(int a) 返回 int 值的绝对值。
        static long abs(long a) 返回 long 值的绝对值。*/
        double a = Math.abs(4.56466);
        System.out.println(a);//4.56466

        //向上取整
        //static double ceil(double a) 返回最小的（最接近负无穷大）double 值，该值大于等于参数，并等于某个整数。
        double b = Math.ceil(7.8);
        System.out.println(b);//8.0

        //向下取整
        //static double floor(double a) 返回最大的（最接近正无穷大）double 值，该值小于等于参数，并等于某个整数。
        double c = Math.floor(4.4);
        System.out.println(c);//4.0

        //四舍五入
        double d = Math.round(4.6);
        double e = Math.round(4.4);
        System.out.println(d);//5.0
        System.out.println(e);//4.0

        //在-10.8至5.9之间，绝对值大于6或小于2.1的整数有哪些
        double min = -10.8;
        double MAX = 5.9;
        int count = 0;//符合要求的整数的数量
        for(int i = (int)min;i < MAX; i++){//向下转型将double装化成int
            int abs = Math.abs(i);//取绝对值判断
            if(abs>6||abs<2.1){
                System.out.print(i+",");
                count ++;
            }
        }
        System.out.println("总共有："+count);


    }
}

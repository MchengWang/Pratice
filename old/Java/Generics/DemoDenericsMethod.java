package Summarize.Generics;

public class DemoDenericsMethod {
    /*含有泛型的方法
    格式：修饰符<代表泛型的变量> 返回值类型 方法名（参数）{

    }
    定义含有泛型的方法，泛型定义在方法的修饰符和返回值类型之间
    含有泛型的方法，再调用方法之前确定泛型的数据类型*/
    public static void main(String[] args) {
        //创建类对象
        DemoDenericsMethod dgm = new DemoDenericsMethod();
        dgm.show01(20);//调用含有泛型的普通方法

        //使用含有泛型的静态方法
        //静态方法通过类名.方法（参数）可以直接调用
        DemoDenericsMethod.show02("abc");
    }


    //定义含有泛型的普通方法
    public<E> void show01(E e) {
        System.out.println(e);
    }

    //定义含有泛型的静态方法
    public static<E> void show02(E e){
        System.out.println(e);
    }
}

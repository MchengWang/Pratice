package Summarize.Exception;

import jdk.dynalink.linker.LinkerServices;

import java.util.List;

public class DemoExceptionFinally {
    /*finally代码块 （无论是否有异常，finally里的代码一定执行）
    try{}catch（）{}finally{}
    注意：
        1、finally不能单独使用，必须和try一起使用
        2、finally一般用于资源释放（资源回收，无论程序是否异常，最后都要资源释放）
    异常注意事项_多异常的捕获处理
     多个异常受用捕获有该如何处理
        1、多个异常的处理
        2、多个异常一次捕获
        3、多个异常一次捕获一次处理
        */

    public static void main(String[] args) {

        //多个异常分别处理
        try{
            int[] arr = {1,2,3};
            System.out.println(arr[3]);//java.lang.ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }

        try{
            List<Integer> list = List.of(1,2,3);
            System.out.println(list.get(3));//java.lang.ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
        }catch(IndexOutOfBoundsException e){
            System.out.println(e);
        }

        //多个异常一次捕获，多次处理
        try{
            int[] arr = {1,2,3};
            System.out.println(arr[3]);
            List<Integer> list = List.of(1,2,3);
            System.out.println(list.get(3));
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);//ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
        }catch(IndexOutOfBoundsException b){
            System.out.println(b);//IndexOutOfBoundsException: Index 3 out of bounds for length 3
        }
        /*一个try多个catch的注意事项：
            catch里面定义的异常变量，如果有子父类关系，那么子类的异常变量必须写在上边，否则报错

         ArrayIndexOutOfBoundsException extends IndexOutOfBoundsException*/

        //多个异常，一次捕获一次处理
        try{
            int [] arr = {1,2,3};
            System.out.println(arr[3]);
            List<Integer> list = List.of(1,2,3);
            System.out.println(list.get(3));
        }catch(IndexOutOfBoundsException e){
            e.printStackTrace();
        }

        //异常注意事项_finally有return语句
        //如果finally语句中有return语句，永远返回finally中的结果，避免该情况
    }
}

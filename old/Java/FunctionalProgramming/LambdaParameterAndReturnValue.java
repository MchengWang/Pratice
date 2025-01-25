package Summarize.FunctionalProgramming;

import java.util.Arrays;
import java.util.Comparator;

public class LambdaParameterAndReturnValue {
    /*使用lombda作为方法参数和返回值*/

    /**
     * lambda 作为方法参数
     * @param runnable
     */
    public static void startThread(Runnable runnable){
        new Thread(runnable).start();
    }

    public static Comparator<String> getComparato(){
        //方法的返回值类型是一个接口，呢么我们可以返回这个接口的匿名内部类
        /*return new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                // 按照字符串的降序排序
                return o2.length() - o1.length();
            }
        };*/

        // 方法返回值类型是一个接口，所以我们可以返回一个lambda表达式
        /*return (String o1 , String o2) ->{
            return o2.length() - o1.length();
        }*/

        // 连续优化lambda表达式
        return (o1 , o2) -> o2.length() - o1.length();
    }

    public static void main(String[] args) {
        startThread(()-> System.out.println("线程开启"));
        //创建一个数组
        String[] arr = {"aaa" , "bb" , "cccc" , "ddddddd"};
        // 输出排序
        System.out.println(Arrays.toString(arr));
        // 调用Arrays中的sort方法，对字符串数组进行排序
        Arrays.sort(arr , getComparato());
        // 输出排序后
        System.out.println(Arrays.toString(arr));
    }

}

package Summarize.FunctionalProgramming;

import java.util.function.Supplier;

public class SupplierMax {
    /*Supplier练习，求数组元素最大值*/

    public static int getMAX(Supplier<Integer> sup){
        return sup.get();
    }

    public static void main(String[] args) {
        // 定义一个int类型的数组，并赋值
        int[] arr = {100 , 0 , -50 , 88 , 99 , 33 , -30};
        // 调用getMAX方法，方法的参数Supplier是一个函数式接口所以可以使用lambda表达式
        int Max = getMAX(()->{
            // 获取数组中最大值，并返回
            // 定义一个变量，把数组中第一个元素赋值给该变量，记录数组中元素最大值
            int MAX = arr[0];
            for (int i : arr) {
                // 使用其他的元素和最大值比较
                if (i > MAX){
                    // 如果i大于MAX。则替换MAX做最大值
                    MAX = i;
                }
            }
            return MAX;
        });

        System.out.println("最大值：" + Max);
    }

}

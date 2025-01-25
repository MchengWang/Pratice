package Summarize.FunctionalProgramming;

import java.util.function.Supplier;

public class CommonFunctionalInterfaces_Supplier {
    /*常用函数式接口
    * Supplier java.util.function.Supplier<T> 包含一个无参T get()
    * 称为生产型接口，指定接口反省是什么类型，那么接口中的方法get就会生产什么类型的数据*/

    // 使用示例
    public static String getString(Supplier<String> sup){
        return sup.get();
    }

    public static void main(String[] args) {
        // 调用getString方法参数是函数式接口，可以使用lambda表达式
        String s = getString(() -> "胡歌");
        System.out.println(s);
    }
}

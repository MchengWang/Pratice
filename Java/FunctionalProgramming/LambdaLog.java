package Summarize.FunctionalProgramming;

/*使用Lombda优化日志案例*/
public class LambdaLog {
    /*使用Lombda优化日志案例：
    *   lombda特点：延迟加载
    *       使用前提：必须存在函数式接口*/
    // 定义一个显示日志的方法，方法的参数传递日志的等级和MessageBuilder接口
    public static void showLog(int level , MessageBuilder mb){
        if (level == 1){
            System.out.println(mb.builderMessage());
        }
    }

    public static void main(String[] args) {
        // 定义三个日志信息
        String msg1 = "Hello";
        String msg2 = "world";
        String msg3 = "Java";

        // 调用showLog方法，参数MessageBuilder是一个函数式接口，所以传递lombda表达式
        showLog(2 , ()->{
            // 返回一个拼接好的字符串
            return msg1 + msg2 + msg3;
        });

        /*使用lombda表达式作用参数传递，仅仅是把参数传递到showLog方法中，只有满足条件，日志等级为1级才会调用接口中的方法BuilderMessage
        * ，才会进行字符串的拼接。如果条件不满足，那么MessageBuilder中的BuilderMessage也不会执行，所以拼接字符串的代码也不会执行，不会存在性能的浪费。*/
    }
}

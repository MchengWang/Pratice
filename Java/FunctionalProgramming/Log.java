package Summarize.FunctionalProgramming;

public class Log {
    /*日志案例*/

    /*定义一个根据日志的级别，显示日志信息的方法*/
    public static void showLog(int level , String message){
        // 对日志等级判断，输出结果
        if (level == 1){
            System.out.println(message);
        }
    }

    public static void main(String[] args) {
        // 定义三个日志信息
        String msg1 = "Hello";
        String msg2 = "world";
        String msg3 = "Java";

        // 调用showLog方法，传递日志级别和日志信息
        showLog(2 , msg1 + msg2 + msg3);
        /*发现以上代码存在的一些性能浪费问题，调用showLog方法，传递的第二个参数是一个拼装好的字符串，先把字符串拼接好，然后在调用showLog方法，showLog方法中如果床底的日志等级不是1级别
        * ，那么就不会输出拼接后的字符，所以感觉字符串九百拼接了，存在了浪费*/


    }
}

package Summarize.Exception;

public class DemoExceptionCustomExceptions {
    /*自定义异常
        java提供的异常类，不够实用，需要自己定义一些异常类
        格式：修饰符 class XXXException extends Exception/RuntimeException(必须继承){
        添加一个空参构造方法
        添加一个带异常信息的构造方法
        }
        注意：1、自定义异常类一般都是以Exception结尾，说明该类是一个异常类
             2、自定义异常类，必须继承Exception/RuntimeException
                Exception：自定义异常类为编译期异常，抛出异常，必须处理这个异常，try...catch或者Throw
                RunTimeExceptiom：自定义异常类是运行期异常类，无需处理交给虚拟机（jvm）处理（中断处理）*/
}

class Demo extends Exception{
    //添加一个空参构造方法
    public Demo(){
        super();
    }

    //添加一个带异常信息的构造方法
    //查看源码发现所有异常类都会带有一个带有异常信息的构造方法，方法内部会调用父类带异常处理的方法
    //让父类来处理这个异常

    public Demo(String message){
        super(message);
    }
}

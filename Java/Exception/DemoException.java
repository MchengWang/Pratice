package Summarize.Exception;

public class DemoException {
    /*异常：指程序在执行过程中，出现非正常的情况，最终会导致jvm的非正常停止
    在Java等面向对象的编程语言中，异常本身就是一个类，产生异常就是创建异常对象并抛出一个异常对象，java处理异常的方式是中断处理
    异常指的并不是语法错误，变扭不通过不会像产生字节码文件，根本不能运行
    异常体系                          Throwable（父类）
                Error（子类）                              Exception（子类）
               工程师不能处理                                由于使用不当导致
               只能避免                                      可以避免的
    异常分类
    java.lang.Throwable：是java语言中所有错误或者异常的超类
              Exception：编译期异常，进行编译（写代码）java程序时出现问题
                 RuntimeException：运行期异常，Java程序运行过程中出现的问题
                 异常就相当于程序得了小感冒，把异常处理掉程序可以继续执行
              Error:错误
                 就相当于程序得了一个无法治愈的毛病，必须修改源代码，程序才能继续执行
    try{//可能出现的异常}catch(Exceptinon e){//异常的处理逻辑}
    outofmemoryError：java Help Space
    异常的产生过程解析
      1、jvm检测出异常，会做两件事
         1、创建一个异常对象，这个异常对象包括了异常产生的（原因，内容，位置）
         示例 new ArrayIndexOfBoundsException("3");
         2、在getements方法中灭哟异常的处理逻辑（try...catch）,那么jvm就会把异常对象
         抛出给方法的调用处，main方法来处理这个异常
      2、main方法接收了异常对象，main方法也没有处理异常的逻辑继续把对象抛出给main方法的调用者
      jvm处理
      3、jvm接受到这个异常对象，做了两件事
         1、把异常对象（内容，原因，位置）一红色字体打印在控制台
         2、jvm会终止当前正在执行的java程序-->中断处理
      */
}

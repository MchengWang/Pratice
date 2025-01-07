package Summarize.Reflection;

public class TheWayToGetClass {
    /*获取class对象的方式
    * 1、Class.forName("全类名") 将字节码文件加载进内存，返回class对象
    * 2、类名.class 通过类名的属性class来获取
    * 3、对象.getclass() getclass()方法在Object类中定义着
    * 结论：
    *   同一个字节码文件（*.class）再一次程序运行中，只会被加载一次，无论通过哪一种方式获取的class对象都是同一个
    * 方式一、多用于配置文件，将类名称定义在配置文件中，读取文件加载类
    * 方式二、多用于参数的传递
    * 方式三、多用于对象的获取字节码的方式*/
}

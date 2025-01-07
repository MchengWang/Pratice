package Summarize.Thread;

public class DemoThreadSafeStaticMethod {
    /*静态同步方法
    格式：修饰符 static syniocroizd 参数名称（参数列表）{
        可能出现安全问题的代码
    }
    静态同步方法 锁对象是？不是this
    this是创建对象之后产生的静态方法优先对象    即：RunnableImpl.class
    静态方法的锁的对象是本类的class属性-->class文件对象（反射）*/
}

package Summarize.IO;

public class DemoIOSerializationanddeserializationTransient {
    /*transient关键字_瞬态关键字
    static关键字：静态
      静态优先于非静态加载到内存中（静态优先于对象进入内存中）
      被static修饰的成员变量不能序列化的，序列化的都是对象
    transient关键字：瞬态
      被transient修饰的成员变量不能被序列化
    InvalidClassException异常_原理和解决方案
    解决方案：
      可序列化的类可以通过声明为"SerialVersonUID"的字段，（该字段必须是静态（static）最终（final）的long型字段）
      显示声明自己的SerialVersonUID
    示例：
      static final long SerialVersonUID = 42L；常量不变*/
}

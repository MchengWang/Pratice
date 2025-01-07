package Summarize.FunctionalInterfaces;

public class FunctionalInterfacesConcepts {
    /*函数式接口 有且只有一个抽象方法的接口
    * 语法糖，更加方便但原理不变
    * 格式：
    * public interface 接口名称{
    *   public abstract 返回值类型 方法名称（可选参数信息）；
    *   //其他非抽象的内容 public abstract可省略 -> 返回值类型 方法名 （可选参数信息）
    * }
    * 可以定义其他方法（默认，静态，私有）*/

    /*@FunctionalInterface 注释
    *   作用：是可以检测接口是否是一个函数式接口
    *       是：编译成功 否：编译失败（接口五抽象，接口抽象方法大于1个）
    * 函数式接口的使用：一般作为方法的参数和返回值类型*/
}

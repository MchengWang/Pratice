package Summarize.Interface;
/*格式：
  修饰符 Interface 接口名称{
    //接口内容
  }

  接口可以包含的内容有：
  1、常量 2、抽象方法，3、默认方法，4、静态方法，5、私有方法

*/
public interface DemoInterface {

    /*接口中的常量
    * 格式：
    * 修饰符 static final 数组类型 常量名称 = 数据值
    * 备注：一旦使用final关键字进行修饰，说明不可变
    * 注意：
    * 1、接口中的常量可以省略public static final ，注意，不写照样也是这样的
    * 2、接口中的常量，必须进行赋值，不能不赋值。（明确赋值）
    * 3、接口中的常量名称，使用完全大写的字母，而且要用下划线进行分割（建议）命名规则*/
    public static final int AW_OF_MY_INTERFACE = 10;

    /*抽象方法格式
    * 修饰符 abstract 返回值类型 参数名称（参数列表）；
    * 注意：
    * 接口中的抽象方法，修饰符系是固定的关键字：public abstract
    * 这两个关键字，可以选择性省略（但不建议）
    * 方法的三要素可以随意定义*/

    public abstract void abs1();//标准式
    //abstract void abs2();//省略public修饰符的省略式
    //public void abs3();//省略abstract的省略式
    //void abs4();//省略public和abstract的省略式

    /*接口中的默认方法
    * 格式：
    * 修饰符 default 返回值类型 方法名称 （参数列表）{
    *   方法体；
    * }
    * 注意：
    * 1、接口的默认方法，可以通过接口的实现类对象，直接调用
    * 2、接口的默认方法，也可以被接口实现类覆盖重写*/
    public default void xs(){
        System.out.println("Hello World");
    }

    /*接口中的静态方法
    * 格式：
    * 修饰符 static 返回值类型 方法名称（参数列表）{
    *   方法体；
    * }
    * 注意：
    * 1、通过接口名称直接调用接口当中的静态方法*/
    public static void dc(){
        System.out.println("HELLO");
    }

    /*普通私有方法 解决多个默认方法之间重复代码问题
    * 格式：
    * private 返回值类型 方法名称（参数列表）{
    *   方法体；
    * }
    * 静态私有方法 解决多个静态方法之间重复代码问题
    * 格式：
    * private static 返回值类型 参数名称（参数列表）{
    *   方法体；
    * }*/
    
}

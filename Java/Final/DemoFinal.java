package Summarize.Final;

public class DemoFinal {
    //直接
    private final String name = "胡歌";
    //构造 构造有两个，默认勿赋值
    //保证所有重载的构造方法，都最终会对final的成员变量进行赋值

    public static void main(String[] args) {
        /*final : 代表最终，不可改变的
        四种用法：
        1、可以用来修饰一个类
        2、可以用来修饰一个方法
        3、可以用来修饰一个局部变量
        4、可以用来修饰一个成员变量
        当final修饰一个类的时候：
        格式：修饰符 final class 类名称{}
        含义，这个类泵有任何的子类（太监类）
        注意：一个类如果是final修饰的，那么内部的成员方法都无法覆盖重写（因为没儿子）
        final修饰成员方法
        格式：修饰符 返回值类型 方法名称（参数列表）{//方法体}
        注意：对于类，方法来说，abstract和final不能同时使用，因为矛盾
        fianl修饰局部变量
        格式: final 数据类型 参数名称 = 数据值
        注意：
        1、对于基本数据类型，不可变说的是变量当中的数据不可变
        2、对于引用数据类型，不可变说的是变量当中的地址值不可变
        3、地址值不可变，但是地址值指向的对象可变，利用setname修改地址值指向对象
        final修饰成员变量
        格式：修饰符 final 返回值类型 参数名称 = 数据值
        对于成员变量来说，如果使用final修饰，那么这个变量照样不可变
        1、由于成员变量具有默认值，所以使用了final必须手动赋值，不会再给默认值了
        2、对于final的成员变量，要么使用直接赋值，要么使用构造方法进行复制，二者选其一
        3、必须保证类中的所有重载的构造方法，都最终会对final的成员变量进行赋值*/

    }
}
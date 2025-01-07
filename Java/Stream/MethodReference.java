package Summarize.Stream;

public class MethodReference {
    /*方法引用 对于lambda优化*/
    public static void main(String[] args) {
//        printString((s) -> System.out.println(s));
        // 可以直接使用
//        printString(System.out :: println);

        /*方法引用符
        *   双冒号 :: 为引用运算符，而他所在表达式被称为方法引用，如果lambda要表达的函数已经存在某个方法的实现中，那么则可以通过双冒号来
        * 引用方法作为lambda的替代者
        * lambda写法：s->System.out.println(s)
        * 方法引用写法： System.out :: println
        * 第一种语义：拿到参数之后经lambda之手，继而传递给System.out.println方法来处理
        * 第二种语义：直接让System.out中的println来取代lambda
        * 两种写法效果完全一样，而第二种方法引用的写法复用了已有方案，更加简洁
        * 注：
        *   lambda中传递的参数一定是方法引用中的，那个方法可以接受的类型否则会抛出异常*/

        // 面向对象名引用成员方法
        /*pringtString((s) -> {
            MethodReobject reobject = new MethodReobject();
            reobject.printUpperCase(useString(s));
        });*/
        /*使用方法引用优化lambda对象十一存在的MethodReObject成员方法，也是存在的printUpperCase(String)所以我们可以使用
        * 对象名引用成员方法*/
        // 创建对象
        /*MethodReobject reobject = new MethodReobject();
        printString(reobject :: printUpperCaseString);*/

        // 通过类名引用静态方法
        /*使用方法引用优化lambda表达式 Math类是存在的 abs计算绝对值得静态方法也是存在的所以我们了一通过类名直接引用静态方法*/
        // int number = method(-10 , Math :: abs);
        // System.out.println(number);

        // 通过super引用父类成员方法
        /*使用哦个super引用父类成员方法 super是已经存在的，弗雷德成员方法sayHello也是已经存在的，所以我们可以直接使用super引用父类的
        * 成员方法*/
        /*method(super :: sayHello); // 前提是有子父类继承关系*/

        // 通过this引用本类成员方法
        // marry(this :: buyHouse);

        // 类的构造器（构造方法）引用 类名称 :: new
        /*构造方法 new Person(String name)已知，创建对象已知new就可以使用Person引用new创建对象*/
        // printName("古力娜扎" , Person :: new); // 使用Person类的带参构造方法，通过传递的姓名创建对象

        // 数组构造器引用
        /*已知创建的就是int[]数组，长度是一致的就可以使用方法引用，int[]引用new，根据参数传递的长度来创建数组*/
        // int[] arr = CreateArray(10 , int[] :: new);
    }
}

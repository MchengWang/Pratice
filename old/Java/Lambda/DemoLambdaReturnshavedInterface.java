package Summarize.Lambda;

public class DemoLambdaReturnshavedInterface {
    /*Lambda表达式有返回值有参（自定义接口）
    一个计算机接口，内涵抽象方法calc可以将两个int数字相加的到加值*/

    /*定义一个方法
    参数传递两个int参数Calcultor接口
    方法调用caluctor中的Calc技术按两个参数的和*/
    public static void invokecalc(int a , int b , calculator c){
        int sum = c.calc(a,b);
        System.out.println(sum);
    }

    public static void main(String[] args) {
        //调用invokecalc方法，方法参数是一个接口，可以使用匿名内部类
       /* invokecalc(10, 20, new calculator() {
            @Override
            public int calc(int a, int b) {
                return a + b;
            }
        });*/

        //使用lambda表达式简化匿名内部类的书写
        invokecalc(10,20,( a , b ) -> a + b);

        /*lambda省略格式（是可以指导，可以省略）
        凡是根据上下文推导出来的内容，都可以省略书写
        可以省略书写的内容：
           1、（参数列表）：括号中参数列表的数据类型，可以不写
           2、（参数列表）：括号中的参数若果有一个，那么类型和（）都可以省略
           3、{一些代码}：如果{}中的代码只用一行，无论是否有返回值都可以省略（{}，return ， ；）
           注意：要省略{}，return，分号必须一块省略
        Lambda使用前提
           1、使用lambda必须是有接口，且接口中大的方法有且只有一个抽象方法
           无论是jdk呢值得Runnable，Comparator接口还是自定义接口，只有当接口中的丑行方法存在唯一时，
           才可以使用Lambda
           2、使用Lambda必须具有上下文推断
           也就是方法中的参数或者局部变量类必须为lambda对应的接口类型，才能使用lambda作为该接口的实例
        备注：有且仅有一个抽象方法的接口，称为”函数式“接口
       */
    }

}

interface calculator{
    public abstract int calc(int a ,int b);
}

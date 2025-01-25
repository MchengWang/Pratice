package Summarize.VariableParameters;

public class DemoVariableParameters {
    /*可变参数：
       格式：修饰符 返回值类型 方法名（参数类型...形参名）{}
      可等价于
       格式：修饰符 返回值类型 方法名（参数类型[] 形参名）{}
      使用前提：当方法的参数列表数据类型已经确定，但是参数的个数不确定，就可以使用可变参数
      使用格式：定义方法时使用
      可变参数的原理：可变参数底层是一个数组，根据传递参数不同，会创建不同长度的数组，来存储这些参数
       传递的参数个数，可以是0个（不传递）或者多个
     可变参数的注意事项：
       1、一个方法的参数列表，只能有一个可变参数
       2、如果方法的参数有多个，那么可变参数必须写在参数列表的末尾
     可以这样写多个参数，可变参数放在参数列表中最末尾的位置
       示例：public static void method(int a,int b ,int...c){}
     可变参数的终极写法
       示例：public static void method(Object...obj){}*/
    public static void main(String[] args) {
//        int i = add();
//        System.out.println(i);

        int i1 = addh(1, 2, 3, 4, 5, 6, 78, 9, 455, 6, 322, 63, 6, 2353, 26, 656, 6565);
        System.out.println(i1);
    }

    private static int add(int...arr) {
        System.out.println(arr);
        System.out.println(arr.length);
        return 0;
    }

    /*定义计算（0-n）整数和的方法
      已知：计算整数的和，数据类型定义为int
      但是参数的个数不确定，不知道要计算多少个整数的和，就可以使用可变参数*/

    public static int addh(int...arr){
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return sum;
    }
}

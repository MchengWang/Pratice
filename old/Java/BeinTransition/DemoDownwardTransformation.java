package Summarize.BeinTransition;

public class DemoDownwardTransformation {
    public static void main(String[] args) {
        /*向下转型既是[还原]动作
        格式： 子类名称 对象名 = （子类名称）父类对象
        含义：将父类对象[还原]成为本来的子类对象
        注意：必须保证对象本来创建的时候，才能向下转型
        java.lang.classcastException: 类转换异常
        类似于 int num = (int) 10.0; 可以
              int num = (int) 10.5; 不可以，精度缺失
       可以用instanceof关键字进行类型判断（一定要进行判断）
       格式：对象 instanceof 类名称
       返回值 Boolean*/

    }
}

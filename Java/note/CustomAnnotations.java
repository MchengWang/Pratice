package Summarize.note;

public class CustomAnnotations {
    /*自定义注解
    *   格式：1、元注解
    *       2、修饰符 @interface 注解名称{}
    *   注解本质：本质上就是一个接口，该接口默认继承Annotation接口
    *   public interface MyAnno extends java.lang.annotation.Annotation{}
    *   属性：接口中的抽象方法
    *   要求：1、属性的放回置类型由下列取值
    *           1、基本数据类型
    *           2、String
    *           3、枚举
    *           4、注解
    *           5、以上数据类型的数组
    *       2、定义了属性在使用时需要给属性赋值
    *           1、如果定义属性时，使用defau关键字给属性默认初始化值，则使用注解时，可以不进行属性的赋值
    *           2、如果只有一个属性需要赋值，并且属性的名称时Value则value可以省略*/
}

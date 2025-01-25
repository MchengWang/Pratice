package Summarize.Reflection;

import java.lang.reflect.Field;

public class ClassObjectFunctionality {
    /** class对象功能
    * 获取功能
    * 1、获取成员变量们
    *   1、Field[] getFields() 返回包含反映该对象所表示的类或界面中所有可访问公共字段的对象的数组。FieldClass
    *   2、Field getField(String name) 返回反映该对象所表示的类或界面的指定公共成员字段的对象。FieldClass
    *   3、Field getDeclaredField(String name) 返回反映该对象所表示的类或界面的指定申报字段的对象。FieldClass
    *   4、Field[] getDeclaredFields() 返回反映该对象所表示的类或界面所声明的所有字段的对象阵列。FieldClass
    * 2、获取构造方法们
    *   1、Constructor<?>[] getConstructors() 返回包含反映该对象所代表的类的所有公共构造器的对象的数组。ConstructorClass
    *   2、Constructor<T> getConstructor(Class<?>... parameterTypes) 返回反映该对象所代表的类的指定公共构造器的对象。ConstructorClass
    *   3、Constructor<T> getDeclaredConstructor(Class<?>... parameterTypes) 返回反映该对象所表示的类或界面的指定构造体的对象。ConstructorClass
    *   4、Constructor<?>[] getDeclaredConstructors() 返回反映该对象所代表的类所声明的所有构造器的对象阵列。ConstructorClass
    * 3、获取成员方法们
    *   1、Method getMethod(String name, Class<?>... parameterTypes) 返回反映该对象所代表的类或界面的指定公共成员方法的对象。MethodClass
    *   2、Method[] getMethods() 返回包含反映该对象所代表的类或界面的所有公共方法的对象的数组，包括类或界面声明的对象以及从超级类和超级字面继承的对象。Method Class
    *   3、Method getDeclaredMethod(String name, Class<?>... parameterTypes) 返回反映该对象所表示的类或界面的指定申报方法的对象。MethodClass
    *   4、Method[] getDeclaredMethods() 返回包含反映该对象所代表的类或界面的所有申报方法的对象的数组，包括公共、受保护、默认（包）访问和私有方法，但不包括继承的方法。Method Class
    * 4、获取类名
    *   1、String getName() 返回由此对象表示的实体的名称（类、接口、阵列类、原始类型或无效）。Class
    * 暴力反射：setAccessible(true)用于获取到方法后进行操作*/
    public static void main(String[] args) {
        //对A类中私有成员字段y进行暴力反射
        ClassObjectFunctionality c = new ClassObjectFunctionality();
        Field fy= null;
        try {
            fy = c.getClass().getDeclaredField("y");
            //暴力反射
            fy.setAccessible(true);
            System.out.println(fy.get(c));
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

    }
}

package Summarize.Exception;

public class DemoExceptionThorw {
    /*thorw关键字
         作用：可以使用thorw在指定的方法中抛出指定的异常
         使用格式：thorw new XXXException（"异常产生的原因"）
         注意事项：1、thorw必须写在方法内部
                 2、thorw后边new对象必须是Exception或者Exception的子类
                 3、thorw抛出指定的异常对象，我们就必须处理这个异常
                    thorw后边创建的是RunTimeException或者RunTimeException的子类对象我们可以不处理
                    默认交给jvm处理（打印异常对象，中断程序）
                    thorw后边创建的是编译异常（写代码的时候会报错），我们就必须处理这个异常要么thorws要么Try...catch*/
    public static int getElements(int[] arr , int index){
        /*定义一个方法，获取指定索引的字符
        参数 int[] arr :
            int index:
        以后（工作中）我们首先必须都方法传递的参数进行合法性校验
        如果参数不合适，那么我们就必须使用抛出异常的方式，告知方法的调用者“
        传递的数组的值是null”*/
        if(arr == null){
            throw new NullPointerException("传递的数组是null");
            /*注意：nullpointerException是一个运行期异常，我们不用处理，默认交给jvm处理
            我们也可以对index进行合法校验
            如果index的范围不在数组的索引范围中
            那么我们就会抛出数组索引越界异常，告知方法的调用者，传递的索引3超过数组的使用范围*/
        }else if(index<0 || index>arr.length-1){
            throw new ArrayIndexOutOfBoundsException("传递的索引超过数组的适用范围");
        }
        int Else = arr[index];
        return Else;
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        int i = DemoExceptionThorw.getElements(arr, 5);
        System.out.println(i);
    }
}

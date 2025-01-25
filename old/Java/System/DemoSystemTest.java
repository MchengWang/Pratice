package Summarize.System;

import java.util.Arrays;

public class DemoSystemTest {
    /*System类提供了大量的静态方法，可以获取与系统相关的信息或系统操作
    static long currentTimeMillis() 返回以毫秒为单位的当前时间。
    static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
      从指定源数组中复制一个数组，复制从指定的位置开始，到目标数组的指定位置结束。
    参数解析：
    src-源数组 srcPos-源数组中的起始位置 dest-目标数组 destPos-目标数组的起始位置
    length-要复制的数组元素的数量*/

    public static void main(String[] args) {
        //static long currentTimeMillis() 返回以毫秒为单位的当前时间。
        System.out.println(System.currentTimeMillis());

        //static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
        //      从指定源数组中复制一个数组，复制从指定的位置开始，到目标数组的指定位置结束。
        int[] arr = {1,2,3,4,5,6};
        int[] acc = {7,8,9,0};
        System.arraycopy(arr,0,acc,1,3);//复制的数组个数不得超过数组的长度
        System.out.println(Arrays.toString(acc));
    }
}

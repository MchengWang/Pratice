package Summarize.Array;

import java.lang.reflect.Array;
import java.util.Arrays;

public class DomeArray {

    public static void main(String[] args) {

        //定义二维数组
        char arr[][]= new char[4][];
        arr[0] = new char[]{'春','眠','不','觉','小'};
        arr[1] = new char[]{'处','处','闻','啼','鸟'};
        arr[2] = new char[]{'夜','来','风','雨','声'};
        arr[3] = new char[]{'花','落','知','多','少'};

        //遍历二维数组
        //普通for循环
        for (int i = 0; i < arr.length; i++) {
            for (int i1 = 0; i1 < arr[i].length; i1++) {
                System.out.print(arr[i][i1]);
            }
            //打印一句换行打印下一句
            System.out.println();
        }

        //使用foreach循环遍历二维数组
        for(char[] a : arr){
            for(char b : a){
                System.out.print(b);
            }
            System.out.println();
        }

        //对数组进行排序
        /*static void sort(byte[] a)对指定的 byte 型数组按数字升序进行排序。
        static void sort(byte[] a, int fromIndex, int toIndex)对指定 byte 型数组的指定范围按数字升序进行排序。
        static void sort(char[] a)对指定的 char 型数组按数字升序进行排序。
        static void sort(char[] a, int fromIndex, int toIndex)对指定 char 型数组的指定范围按数字升序进行排序。
        static void sort(double[] a)对指定的 double 型数组按数字升序进行排序。
        static void sort(double[] a, int fromIndex, int toIndex) 对指定 double 型数组的指定范围按数字升序进行排序。
        static void sort(float[] a)对指定的 float 型数组按数字升序进行排序。
        static void sort(float[] a, int fromIndex, int toIndex)对指定 float 型数组的指定范围按数字升序进行排序。
        static void sort(int[] a)对指定的 int 型数组按数字升序进行排序。
        static void sort(int[] a, int fromIndex, int toIndex)对指定 int 型数组的指定范围按数字升序进行排序。
        static void sort(long[] a)对指定的 long 型数组按数字升序进行排序。
        static void sort(long[] a, int fromIndex, int toIndex)对指定 long 型数组的指定范围按数字升序进行排序。
        static void sort(Object[] a)根据元素的自然顺序对指定对象数组按升序进行排序。
        static void sort(Object[] a, int fromIndex, int toIndex)根据元素的自然顺序对指定对象数组的指定范围按升序进行排序。
        static void sort(short[] a)对指定的 short 型数组按数字升序进行排序。
        static void sort(short[] a, int fromIndex, int toIndex)对指定 short 型数组的指定范围按数字升序进行排序。
        static <T> void sort(T[] a, Comparator<? super T> c)根据指定比较器产生的顺序对指定对象数组进行排序。
        static <T> void sort(T[] a, int fromIndex, int toIndex, Comparator<? super T> c)根据指定比较器产生的顺序对指定对象数组的指定范围进行排序。
*/
        int aee[] = new int[]{5,84,46,94};
        Arrays.sort(aee);
        for (int i : aee) {
            System.out.print(i+",");
        }
        //为方便阅读，是上述语句打印输出完后，就行换行命令
        System.out.println();


        //二维数组的三种初始化
        //静态省略式 ；
        int tdarr[][] = {{0,1,2},{1,2,3}};

        //静态标准式
        int tdarr2[][] = new int[][]{{0,1,2},{1,2,3}};

        //动态标准式
        //左索引为行，右索引为列
        int tdarr3[][] = new int[2][3]; //此式为2行3列的二维数组

        //复制数组的方法
        /*static boolean[] copyOf(boolean[] original, int newLength) 复制指定的数组，截取或用 false 填充（如有必要），以使副本具有指定的长度。
        static byte[] copyOf(byte[] original, int newLength) 复制指定的数组，截取或用 0 填充（如有必要），以使副本具有指定的长度。
        static char[] copyOf(char[] original, int newLength) 复制指定的数组，截取或用 null 字符填充（如有必要），以使副本具有指定的长度。
        static double[] copyOf(double[] original, int newLength) 复制指定的数组，截取或用 0 填充（如有必要），以使副本具有指定的长度。
        static float[] copyOf(float[] original, int newLength) 复制指定的数组，截取或用 0 填充（如有必要），以使副本具有指定的长度。
        static int[] copyOf(int[] original, int newLength) 复制指定的数组，截取或用 0 填充（如有必要），以使副本具有指定的长度。
        static long[] copyOf(long[] original, int newLength) 复制指定的数组，截取或用 0 填充（如有必要），以使副本具有指定的长度。
        static short[] copyOf(short[] original, int newLength) 复制指定的数组，截取或用 0 填充（如有必要），以使副本具有指定的长度。
        static <T> T[] copyOf(T[] original, int newLength) 复制指定的数组，截取或用 null 填充（如有必要），以使副本具有指定的长度。
        static <T,U> T[] copyOf(U[] original, int newLength, Class<? extends T[]> newType) 复制指定的数组，截取或用 null 填充（如有必要），以使副本具有指定的长度。
        static boolean[] copyOfRange(boolean[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static byte[] copyOfRange(byte[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static char[] copyOfRange(char[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static double[] copyOfRange(double[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static float[] copyOfRange(float[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static int[] copyOfRange(int[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static long[] copyOfRange(long[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static short[] copyOfRange(short[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static <T> T[] copyOfRange(T[] original, int from, int to) 将指定数组的指定范围复制到一个新数组。
        static <T,U> T[] copyOfRange(U[] original, int from, int to, Class<? extends T[]> newType)将指定数组的指定范围复制到一个新数组。*/
        int arr4[] = {1,2,3,4,5};
        int arrq[] = Arrays.copyOf(arr4,2);
        for (int i : arrq) {
            System.out.print(i+",");
        }
        //为方便实验下次代码，所以进行换行显示
        System.out.println();

        //冒泡排序实例
        int aqq[] = {64,75,46,33,16};
        for (int i = 1; i < aqq.length; i++) {
            for (int j = 0; j < aqq.length-1; j++) {
                if(aqq[j] > aqq[j+1]) {
                    int tmp = aqq[j];
                    aqq[j] = aqq[j+1];
                    aqq[j+1] = tmp;
                }
            }
        }
        System.out.println("冒泡排序：");
        for (int i : aqq) {
            System.out.print(i+",");
        }

        //为方便实验下次代码，所以进行换行显示
        System.out.println();

        //直接选择排序
        int yu[] = {64,1,75,46,7};
        int rui;
        for (int i = 1; i < yu.length; i++) {
            rui = 0;
            for (int j = 1; j < yu.length; j++) {
                if(yu[rui] < yu[j]){
                    rui = j;
                }
            }
            int tmp = yu[yu.length-i];
            yu[yu.length-i] = yu[rui];
            yu[rui] = tmp;
        }
        System.out.println("选择排序结果为");
        for (int i : yu) {
            System.out.print(i + ",");
        }

        //为方便实验下次代码，所以进行换行显示
        System.out.println();

        /*一维数组的三种形式
        * 1、动态初始化格式 数据类型 数组名称[] = new 数据类型[数组长度]
        *       动态拆分：(不建议使用) 数据类型[] = 数组名称； 数组名称 = new 数据类型[数组长度]
        * 2、静态初始化格式（标准式） 数据类型[] 数组名称 = new 数据类型[]{元素一。元素二，元素三...}
        * 3、静态省略式 数据类型[] 数组名称 = {元素一，元素二，元素三 ...}*/
    }
}

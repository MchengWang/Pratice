package Summarize.String;

public class DomeStringBuilder {/*StringBuilder类
    底层是一个数组，但没有被final修饰，可以改变长度
    构造方法
    StringBuilder() 构造一个不带任何字符的字符串生成器，其初始容量为 16 个字符。
    StringBuilder(String str) 构造一个字符串生成器，并初始化为指定的字符串内容。
    成员方法
    StringBuilder append(boolean b) 将 boolean 参数的字符串表示形式追加到序列。
    StringBuilder append(char c) 将 char 参数的字符串表示形式追加到此序列。
    StringBuilder append(char[] str) 将 char 数组参数的字符串表示形式追加到此序列。
    StringBuilder append(char[] str, int offset, int len) 将 char 数组参数的子数组的字符串表示形式追加到此序列。
    StringBuilder append(CharSequence s) 向此 Appendable 追加到指定的字符序列。
    StringBuilder append(CharSequence s, int start, int end) 将指定 CharSequence 的子序列追加到此序列。
    StringBuilder append(double d) 将 double 参数的字符串表示形式追加到此序列。
    StringBuilder append(float f) 将 float 参数的字符串表示形式追加到此序列。
    StringBuilder append(int i) 将 int 参数的字符串表示形式追加到此序列。
    StringBuilder append(long lng) 将 long 参数的字符串表示形式追加到此序列。
    StringBuilder append(Object obj) 追加 Object 参数的字符串表示形式。
    StringBuilder append(String str) 将指定的字符串追加到此字符序列。
    StringBuilder append(StringBuffer sb) 将指定的 StringBuffer 追加到此序列。
    String toString() 返回此序列中数据的字符串表示形式。
    append的参数可以是任意类型
    StringBuilder reverse() 将此字符序列用其反转形式取代。
*/
    public static void main(String[] args) {
        StringBuilder a = new StringBuilder().append("abc");
        StringBuilder b = a;
        System.out.println(a == b);

        StringBuilder sb = new StringBuilder();
        sb.append("Hello").append("World").append(".java");
        sb.append("abc");
        sb.append(100);
        sb.append(true);
        //反转方法(reverse)
        sb.reverse();
        //toString方法
        System.out.println(sb.toString());
    }

}

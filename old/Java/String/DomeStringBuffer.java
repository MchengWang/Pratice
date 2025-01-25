package Summarize.String;

public class DomeStringBuffer {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("你好");//创建StringBuffer类对象
       /* StringBuffer append(boolean b)将 boolean 参数的字符串表示形式追加到序列。
        StringBuffer append(char c)将 char 参数的字符串表示形式追加到此序列。
        StringBuffer append(char[] str)将 char 数组参数的字符串表示形式追加到此序列。
        StringBuffer append(char[] str, int offset, int len)将 char 数组参数的子数组的字符串表示形式追加到此序列。
        StringBuffer append(CharSequence s)将指定的 CharSequence 追加到该序列。
        StringBuffer append(CharSequence s, int start, int end)将指定 CharSequence 的子序列追加到此序列。
        StringBuffer append(double d)将 double 参数的字符串表示形式追加到此序列。
        StringBuffer append(float f)将 float 参数的字符串表示形式追加到此序列。
        StringBuffer append(int i)将 int 参数的字符串表示形式追加到此序列。
        StringBuffer append(long lng)将 long 参数的字符串表示形式追加到此序列。
        StringBuffer append(Object obj)追加 Object 参数的字符串表示形式。
        StringBuffer append(String str)将指定的字符串追加到此字符序列。
        StringBuffer append(StringBuffer sb)将指定的 StringBuffer 追加到此序列中。
        StringBuffer appendCodePoint(int codePoint)将 codePoint 参数的字符串表示形式追加到此序列。*/
        sb.append("我是");
        StringBuffer se = new StringBuffer("滚吧");
        sb.append(se);
        System.out.println(sb);

        //修改指定索引处字符
        // void setCharAt(int index, char ch)将给定索引处的字符设置为 ch。
        sb.setCharAt(5,'哈');
        System.out.println(sb);

        //插入字符串
        /*StringBuffer insert(int offset, boolean b)将 boolean 参数的字符串表示形式插入此序列中。
        StringBuffer insert(int offset, char c)将 char 参数的字符串表示形式插入此序列中。
        StringBuffer insert(int offset, char[] str)将 char 数组参数的字符串表示形式插入此序列中。
        StringBuffer insert(int index, char[] str, int offset, int len)将数组参数 str 的子数组的字符串表示形式插入此序列中。
        StringBuffer insert(int dstOffset, CharSequence s)将指定 CharSequence 插入此序列中。
        StringBuffer insert(int dstOffset, CharSequence s, int start, int end)将指定 CharSequence 的子序列插入此序列中。
        StringBuffer insert(int offset, double d)将 double 参数的字符串表示形式插入此序列中。
        StringBuffer insert(int offset, float f)将 float 参数的字符串表示形式插入此序列中。
        StringBuffer insert(int offset, int i)将 int 参数的字符串表示形式插入此序列中。
        StringBuffer insert(int offset, long l)将 long 参数的字符串表示形式插入此序列中。
        StringBuffer insert(int offset, Object obj)将 Object 参数的字符串表示形式插入此字符序列中。
        StringBuffer insert(int offset, String str)将字符串插入此字符序列中。*/
        sb.insert(2 ,'呀');
        System.out.println(sb);

        //字符串反序
        //StringBuffer reverse()将此字符序列用其反转形式取代。
        sb.reverse();
        System.out.println(sb);

        //为了方便阅读，我再将它反序回来
        sb.reverse();

        //删除字符串
        /*StringBuffer delete(int start, int end)移除此序列的子字符串中的字符。
        StringBuffer deleteCharAt(int index)移除此序列指定位置的 char。*/
        sb.delete(0,1);
        System.out.println(sb);

        //为了方便，我再次添加回来
        sb.insert(0,'你');

        //与String方法相同，具体查看java Api文档


    }
}

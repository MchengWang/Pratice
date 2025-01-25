package Summarize.IO;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class DemoIOBufferedReader {
    /*BufferedReader 字符缓冲输入类 extneds Reader
    int	read()	读取单个字符。
    int	read​(char[] cbuf)	将字符读取到数组中。
    abstract void	close()	关闭流并释放与其关联的任何系统资源。
    构造方法：
       BufferedReader​(Reader in)	创建使用默认大小的输入缓冲区的缓冲字符输入流。
       BufferedReader​(Reader in, int sz)	创建使用指定大小的输入缓冲区的缓冲字符输入流。
    参数：Reader in 字符输入，我们可以传递FileReader会增加一个缓冲区，提高读取效率
    特有的成员方法
       String	readLine()	读取一行文本。
            行的终止符号，通过以下字符之一即认为某行以终止换行（'\n'）回车（'\r'）或回车在换行（'\r\n'）
       返回值：包含该行内容的字符串，不包含任何终止符，如果已达流末尾，则返回null
    使用步骤
       1、创建缓冲输入流对象，构造方法中传递字符输入流
       2、使用缓冲输入流对象中的方法readLine读取文本
       3、释放资源
    */
    public static void main(String[] args) throws IOException {
        //1、创建缓冲输入流对象，构造方法中传递字符输入流
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //2、使用缓冲输入流对象中的方法readLine读取文本
        String line = null;
        while((line = br.readLine())!=null){
            System.out.println(br.readLine());
        }

        //3、释放资源
        br.close();
    }
}

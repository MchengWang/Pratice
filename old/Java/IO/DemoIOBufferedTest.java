package Summarize.IO;

import java.io.*;
import java.util.HashMap;

public class DemoIOBufferedTest {
    /*对文本内容排序（按1，2，3）顺序
    分析：1、创建HashMap key每行的序号，value存储每行的文本
         2、创建字符缓冲输入流，构造方法中绑定字符输入流
         3、创建字符缓冲输出流，构造方法中绑定字符输出流
         4、使用字符缓冲输入流中的方法readline，逐行读取文本
         5、对文本切割，获取行中序号和文本内容
         6、把切割好的序号和文本存储到HashMap集合中（key是有序的，1，2.3）
         7、遍历HashMap，获取每一个键值对
         8、把每一个键值对，拼接为一个文本行
         9、把拼接好的文本，使用字符缓冲输出流中的方法Writer，写入到文本中
         10、释放资源
      */
    public static void main(String[] args) throws IOException {
        //1、
        HashMap<String , String> map = new HashMap<>();

        //2、
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\GoodMe\\IdeaProjects\\untitled\\src\\TEST\\test.txt"));

        //3、
        BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\GoodMe\\Desktop\\test.txt"));

        //4、
        String line;
        while((line = br.readLine())!=null){
            //5、
            String[] s = line.split("\\.");
            //6、
            map.put(s[0] , s[1]);
        }

        //7、
        for (String s : map.keySet()) {
            String s1 = map.get(s);
            //8、
            line = s + "" + s1;

            //9、
            bw.write(line);
            bw.newLine();
        }

        //10、
        bw.close();
        br.close();
    }
}

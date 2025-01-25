package Summarize;

import org.junit.Test;

import java.io.*;
import java.util.Base64;

public class methodTest {

    @Test
    public void testxs() throws IOException {
        FileInputStream fis = new FileInputStream(new File("C:\\Users\\AX\\Pictures\\Camera Roll\\a52d5612fbdc213443edf31451cbf61.jpg"));
        // 定义一个字节数组
        byte[] bytes = new byte[1024];
        int n = 0; // 得到实际读取到的字节数
        System.out.println("C:\\Users\\AX\\Pictures\\Camera Roll\\a52d5612fbdc213443edf31451cbf61.jpg文件内容如下：");
        // 循环读取
        while ((n = fis.read(bytes)) != -1) {
            String s = new String(bytes, 0, n); // 将数组中从下标0到n的内容给s
            System.out.println(s);
        }
    }


}

package Summarize.NetworkProgramming;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class BISServer {
    /*模拟BIS服务器分析（代码实现）*/
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(8080);
        Socket socket = server.accept();
        InputStream is = socket.getInputStream();
        // 把is转化为字符缓冲流
        BufferedReader br = new BufferedReader(new InputStreamReader(is));
        // 读取客户端请求信息第一行
        String line = br.readLine();
        // 对信息进行切割，只要中间部分
        String[] arr = line.split("  ");
        // 把路径去掉
        String htmlpath = arr[1].substring(1);
        // 创建本地字节输入流，绑定读取的html的路径
        FileInputStream fis = new FileInputStream(htmlpath);
        // 使用socket中方法获取网络输出流对象
        OutputStream os = socket.getOutputStream();
        // 写入HTTP协议响应头，固定写法
        os.write("HTTP11.1 200 ok\r\n".getBytes());
        os.write("Content-Type:text/html\r\n".getBytes());
        // 写入空行，否则浏览器不解析
        os.write("\r\n".getBytes());
        // 一读一写复制文件，把服务读取文件会写到客户端
        int len = 0;
        byte[] bytes = new byte[1024];
        while ((len = fis.read(bytes)) != -1){
            os.write(bytes , 0 , len);
        }
        // 释放资源
        fis.close();
        server.close();
        socket.close();

        /*浏览器解析服务器回写的html页面，页面中如果有图片，那么浏览器就会单独开一个线程，读服务器图片，我们让服务器一直处于监听状态
        ，服务器就回写一次*/
    }
}

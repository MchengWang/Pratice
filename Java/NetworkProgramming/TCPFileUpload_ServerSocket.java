package Summarize.NetworkProgramming;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPFileUpload_ServerSocket {
    /*文件上传到服务器端
    *   读取客户端上传文件，保存到服务器中的硬盘中，回写上传成功
    * 明确：
    *   数据源 目的地
    * 实现步骤：
    *   1.创建ServerSocket，绑定端口号
    *   2.使用accept获取Socket对象
    *   3.使用socket的getInputStream方法，获取输入流对象
    *   4.判断C:/Users/GoodMe/IdeaProjects/untitled/src/main/java/Summarize/TestFile文件夹是否存在，不存在则创建
    *   5.创建本地输出流对象，构造方法中绑定要输出的目的地
    *   6.使用网络输出流，读取上传文件
    *   7.使用本地输出流，把读取到文件保存在服务器的硬盘
    *   8.使用socket中个体OuputStream，获取网络输出流
    *   9.使用网络输出流，给客户端回写“上传成功”
    *   10.释放资源（FileInputStream，Socket ， ServerSocket）*/

    public static void main(String[] args) throws IOException {
        // 1.创建ServerSocket，绑定端口号
        ServerSocket server = new ServerSocket(8888);
        // 2.使用accept获取Socket对象
        Socket socket = server.accept();
        // 3.使用socket的getInputStream方法，获取输入流对象
        InputStream is = socket.getInputStream();
        // 4.判断C:/Users/GoodMe/IdeaProjects/untitled/src/main/java/Summarize/TestFile文件夹是否存在，不存在则创建
        File file = new File("C:/Users/GoodMe/IdeaProjects/untitled/src/main/java/Summarize/TestFile");
        if (!file.exists()){
            file.mkdir();
        }
        // 5.创建本地输出流对象，构造方法中绑定要输出的目的地
        FileOutputStream fis = new FileOutputStream("C:/Users/GoodMe/IdeaProjects/untitled/src/main/java/Summarize/TestFile");
        // 6.使用网络输出流，读取上传文件
        byte[] bytes = new byte[1024];
        int len = 0;
        while ((len = is.read(bytes)) != -1){
            // 7.使用本地输出流，把读取到文件保存在服务器的硬盘
            fis.write(bytes , 0 , len);
        }
        // 8.使用socket中个体OuputStream，获取网络输出流
        OutputStream os = socket.getOutputStream();
        // 9.使用网络输出流，给客户端回写“上传成功”
        os.write("上传成功".getBytes());
        // 10.释放资源（FileInputStream，Socket ， ServerSocket）
        fis.close();
        os.close();
        socket.close();
        server.close();

        /*文件上传阻塞解决
        *   解决，上传完后，给服务器写一个结束标记
        * void shutdownOutput()  禁用此套接字的输出流。
        * void shutdownInput()  将此套接字的输入流放置在“流的末尾”。
        * 文件上传案例优化
        *   （（文件命名） & （循环接收） & （多线程高效率））*/
    }
}

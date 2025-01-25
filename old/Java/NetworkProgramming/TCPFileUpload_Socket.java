package Summarize.NetworkProgramming;

import java.io.*;
import java.net.Socket;

public class TCPFileUpload_Socket {
    /*TCP通信上传文件的案例
    *   1.客户端使用本地的字节输入流，读取要上传的文件
    *   2.客户端使用网络字节输出流，把读取的文件发送到服务器
    *   3.服务器使用网络字节输入流，读取客户端上传的文件
    *   4.服务器使用本地字节输出流，把读取到的文件，保存在服务器的硬盘上
    *   5.服务器使用网络字节输出流，给客户端会写一个“上传成功”
    *   6.客户端使用网络输入流，读取服务器回写的数据
    *   7.释放资源
    * 注意：
    *   客户端和服务器和本地硬盘进行读写，需要字节创建的字节流对象（本地流）
    *   客户端和服务器之间进行读写，必须使用Socket提供的字节流对象（网络流）*/

    /*文件上传的原理，就是文件的复制
    *   明确：数据源 数据目的地*/

    /*客户端：读取本地我呢见，上传到服务器，读取服务器回写的数据
    * 步骤：
    *   1.创建一个本地字节输出流，构造方法中绑定读取的数据源
    *   2.创建Socket对象中构造绑定服务器的IP和端口号
    *   3.使用Socket中的getOutputStream，获取网络输出流
    *   4.使用本地对象中read，读取本地文件
    *   5.使用网络中write，上传到服务器
    *   6.使用Socket中getInputStream，获取网络输入流
    *   7.使用网络输入流，读取服务器回写数据
    *   8.释放资源*/

    public static void main(String[] args) throws IOException {
        // 1.创建一个本地字节输出流，构造方法中绑定读取的数据源
        FileInputStream fis = new FileInputStream("C:/Users/GoodMe/IdeaProjects/untitled/src/main/java/Summarize/TestFile/a.txt");
        // 2.创建Socket对象中构造绑定服务器的IP和端口号
        Socket socket = new Socket();
        // 3.使用Socket中的getOutputStream，获取网络输出流
        OutputStream os = socket.getOutputStream();
        // 4.使用本地对象中read，读取本地文件
        byte[] bytes = new byte[1024];
        int len = 0;
        while((len = fis.read(bytes)) != -1){
            // 5.使用网络中write，上传到服务器
            os.write(fis.read(bytes , 0 , len));
        }
        socket.shutdownOutput();
        // 6.使用Socket中getInputStream，获取网络输入流
        InputStream is = socket.getInputStream();
        // 7.使用网络输入流，读取服务器回写数据
        while ((len = is.read(bytes)) != -1 ){
            System.out.println((char) len);
        }
        // 8.释放资源
        fis.close();
        socket.close();
    }

}

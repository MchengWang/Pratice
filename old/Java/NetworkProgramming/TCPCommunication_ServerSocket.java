package Summarize.NetworkProgramming;


import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPCommunication_ServerSocket {
    /*TCP服务器代码实现
    *   TCP通信的服务器端，接收客户端的请求，读取客户端发送的数据，给客户端回写数据
    * 表示服务器的类 java.net.ServerSocket 此类实现服务器套接字
    * 构造方法：
    *   ServerSocket(int port) 创建绑定到指定端口的服务器套接字。
    * 服务器端必须明确一件事，必须知道是哪个客户端请求的服务器，所以使用accept方法获取请求的客户端对象Socket
    * 成员方法：
    *   Socket accept()  侦听要连接到此套接字并接受它。 */

    /*服务器的实现步骤：
    *   1.创建服务器ServerSocket对象和系统指定的端口号
    *   2.使用ServerSocket对象中的方法accept，获取到请求的客户端对象Socket
    *   3.使用Socket对象中getInputStream（），获取InputStream
    *   4。使用InputStream，读取客户端发送的数据
    *   5.使用Socket对象中的方法getOutputStream（），获取OutputStream
    *   6.使用OutputStream，给客户端回写数据
    *   7.释放资源（Socket，ServerSocket）*/

    public static void main(String[] args) throws IOException {
        // 1.创建服务器ServerSocket对象和系统指定的端口号
        ServerSocket server = new ServerSocket(8888);
        // 2.使用ServerSocket对象中的方法accept，获取到请求的客户端对象Socket
        Socket socket = server.accept();
        // 3.使用Socket对象中getInputStream（），获取InputStream
        InputStream is = socket.getInputStream();
        // 4.使用InputStream，读取客户端发送的数据
        byte[] bytes = new byte[1024];
        int len = is.read(bytes);
        System.out.println(new String(bytes , 0 , len));
        // 5.使用Socket对象中的方法getOutputStream（），获取OutputStream
        OutputStream os = socket.getOutputStream();
        // 6.使用OutputStream，给客户端回写数据
        os.write("收到，谢谢".getBytes());
        // 7.释放资源（Socket，ServerSocket）
        socket.close();
        server.close();
    }

}

package Summarize.NetworkProgramming;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class TCPCommunication {
    /*TCP通信
     *   实现两台计算机之间的数据交互，通信两端，要严格区分为客户端（Client）和服务端（Server）*/

    /*两端通信时的步骤
     *   1.服务端程序，需要事先启动，等待客户端的链接
     *   2.客户端主动连接服务端，连接成功才能通信，服务端不可以主动连接客户端。*/

    /*客户端通过IO对象字节流与服务器进行通信
     *   客户端（Socket）类    服务器（ServerSocket）类
     * 客户端和服务端进行一次数据交互，需要4个Io对象*/

    /*服务端必须明确两件事情：
     *   1.多个客户端同事和服务器进行交互，服务器必须明确和那个客户端进行的交互，
     *在服务端有一个方法，叫accept客户端获取到请求的客户端对象
     *   2.多个客户端同事和服务器进行交互，就需要使用多个IO流对象
     * 服务器是没有IO流的，服务器可以获取到请求的客户端对象Socket，使用每个客户端Socket中提供的IO流对象和客户端进行交互
     * 服务器端通过客户端的字节输入流读取到客户端所发送的数据
     * 服务器端通过客户端的字节输出流给客户端写数据*/

    /*Socket 构造方法
     *    Socket(String host, int port) 创建流套接字并将其连接到指定主机上的指定端口号。
     *       参数：host 服务器主机的名称，也可以传递服务器的IP地址
     *           port 服务器的端口号
     * 成员方法
     *   OutputStream getOutputStream()  返回此套接字的输出流。
     *   InputStream getInputStream() 返回此套接字的输入流。
     *   void close()  关闭此套接字。*/

    /*实现步骤：
     *   1.创建客户端对象Socket，构造中绑定服务器IP地址和端口号
     *   2.使用Socket对象中的方法getOutputStream（）获取网络字节输出流对象
     *   3.使用网络字节输出流OutputStream对象中的方法write，给服务器发送数据
     *   4.使用Socket对象中的方法getInputStream（）获取网络字节输入流对象
     *   5.使用网络字节输入流InputStream对象中的方法read，读取服务器回写的数据
     *   6.释放资源close（）
     * 注意：
     *   1.客户端和服务器段进行交互，必须使用Socket中提供的网络流，不能使用自己创建的流对象
     *   2.当我们创建客户端对象Socket的时候，就回去请求服务器和服务器经过三次握手建立连接通路，这是如果服务器没有启动，
     * 那么就会抛出异常ConnectException：连接异常。如果服务器启动了，呢么就可以进行交互了*/

}


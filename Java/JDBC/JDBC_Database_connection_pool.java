package Summarize.JDBC;

public class JDBC_Database_connection_pool {
    /*数据库连接池
    * 概述：其实就是一个容器（集合）存放连接的容器
    *   当系统初始化好后，容器被创建，容器中会申请一些链接对象，当用户来访问数据库是，从容其中获取来连接对象，用户访问完之后，会将连接对象归还到容器中
    * 好处；
    *   1、节约资源
    *   2、用户访问高效
    * 实现：（DataSourse） interface
    *   1、标准接口 java.sql包下的
    *       1、方法：获取连接 getConnection(); 归还链接，如果来连接对象Connection是从连接线池中获取的，那么调用conn.close()方法，则不会再关闭连接了
    *               而是归还链接
    *   2、一般我不去实现，有数据库厂商来实现
    *       1、c3p0：数据库连接池
    *       2、Druid：数据库连接池实现技术（由阿里巴巴提供的）*/
}

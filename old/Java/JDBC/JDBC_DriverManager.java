package Summarize.JDBC;

public class JDBC_DriverManager {
    /*DtiverManager 驱动管理对象
    *   功能：
    * 1、注册驱动（告诉程序使用哪一个数据库驱动） Mysql5版本之后可以不注册
    * 2、获取数据库连接
    *   1、static voidregisterDriver(Driver driver)将给定的驱动程序注册为 。DriverManager
    *       写代码时候用Class.forName("com.数据库.jdbc.Driver");
    *       通过查看源码发现在com.mysql.jdbc.Driver存在静态代码块
    *        static {
    *           try{
    *               java.sql.DriverManager.regiserDriver(new Driver);//注册驱动
    *           }catch(SQLException e){
    *               throws new Runnable("Can't redister driver!");
    *           }
    *        }
    *       注意：Mysql之后的驱动Jar包可以省罗注册驱动的步骤
    *   2、static ConnectiongetConnection(String url, String user, String password)尝试建立与给定数据库URL的连接。
    *       参数：url：指定一个连接的路径
    *                 语法：jdbc://Localhost://(ip地址)域名：端口号/（数据库名称）
    *           user:用户名
    *           password：密码
    *       注意：如果连接的市本级的Mysql服务器，并且MySQL默认端口是3306则url可以简写为jdbc：mysql:///数据库名称*/
}

package Summarize.JDBC;

import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBC_JDBCUtils {
    /*练习：定义一个方法，查询数据库表中的数据将其封装为对象，然后装载集合返回
    *   1、定义EMP类
    *   2、定义方法public List<EMP> findAll(){};
    *   3、定义方法select * from emp;
    * 抽取JDBCUtils工具类
    * 目的：简化书写
    *   分析：1、注册驱动也抽取
    *       2、抽取一个方法获取连接对象
    *       3、抽取一个方法释放资源
    *   需求：
    *       1、不想传递参数麻烦，还得保证工具类的通用性
    * 解决：
    *       1、配置文件*/
    private static String url;
    private static String user;
    private static String password;
    private static String driver;

    static {
        try {
            //创建Properties集合
            Properties pro = new Properties();
            pro.load(JDBC_JDBCUtils.class.getResourceAsStream("jdbc.properties"));
            url = pro.getProperty("url");
            user = pro.getProperty("user");
            password = pro.getProperty("password");
            driver = pro.getProperty("driver");
            Class.forName(driver);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url , user , password);
    }

    static void close(Connection conn , Statement stmt , ResultSet rs){
        if(conn != null){
            try {
                conn.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if(stmt != null){
            try {
                stmt.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if(rs != null){
            try {
                rs.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }

    static void close(Connection conn , Statement stmt){
         close(conn , stmt , null);
    }

}

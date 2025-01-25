package Summarize.JDBC;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class JDBCGettingStarted {
    /*JDBC快速入门
    *   1 导入jar包 1-1复制jar包到项目的libs目录下 1-2libs右键add as library
    *   2 注册驱动
    *   3 获取数据库连接对象
    *   4 定义SQL语句
    *   5 获取执行SQL语句的对象 Statement
    *   6 执行SQL，接受返回结果
    *   7 处理结果
    *   8 释放资源*/

    public static void main(String[] args) throws Exception {
        //1 导入jar包 1-1复制jar包到项目的libs目录下 1-2libs右键add as library
        //2 注册驱动
        Class.forName("com.mysql.JDBC.Driver");
        // 3 获取数据库连接对象
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/数据库名称", "账户名", "密码");
        //4 定义SQL语句
        String sql = "SQL语句";
        //5 获取执行SQL语句的对象 Statement
        Statement s = conn.createStatement();
        //6 执行SQL，接受返回结果
        boolean b = s.execute(sql);
        //7 处理结果
        System.out.println(b);
        //8 释放资源
        conn.close();
        s.close();
    }
}

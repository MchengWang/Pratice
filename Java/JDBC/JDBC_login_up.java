package Summarize.JDBC;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class JDBC_login_up {
    static boolean login(String user , String password){
        if(user == null || password == null) {
            return false;
        }
        //获取链接
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try {
            conn = JDBC_JDBCUtils.getConnection();
            String sql = "select * from user where user = '" + user + "' and password = ' " + password + "'";
            stmt = conn.createStatement();
            rs = stmt.executeQuery(sql);
            //判断
            return rs.next();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBC_JDBCUtils.close(conn , stmt , rs);
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入用户名");
        String user = sc.next();
        System.out.println("请输入密码");
        String password = sc.nextLine();
        //调用方法
        boolean b = login(user, password);
        //判断
        if(b) {
            System.out.println("登陆成功");
        } else {
            System.out.println("登陆失败");
        }
    }
}

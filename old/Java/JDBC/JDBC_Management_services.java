package Summarize.JDBC;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class JDBC_Management_services {
    /*管理事务
    *   1、事务：一个包含多个步骤的业务操作，如果这个业务操作被事务管理，则这个步骤要么同时成功们要么同时失败
    *   2、操作
    *       1、开始事务
    *       2、提交事务
    *       3、回滚事务
    *   3、使用Connection对象管理事务
    *       1、开启事务：void setAutoCommit(boolean autoCommit) 将此连接的自动提交模式设置为给定状态。 (在执行之前开启事务)
    *       2、提交事务：void commit() 使自上次提交/回滚以来所做的所有更改都将永久性，并释放此 Connection对象当前持有的任何数据库锁。（当所有SQL都执行完后提交事务）
    *       3、回滚事务：void rollback() 撤消在当前事务中所做的所有更改，并释放此 Connection对象当前持有的任何数据库锁。（在catch中回滚事务）
    * */
    public static void main(String[] args) throws SQLException {
        Connection conn = null;
        PreparedStatement pstmt1 = null;
        PreparedStatement pstmt2 = null;
        try {
            conn = JDBC_JDBCUtils.getConnection();
            conn.setAutoCommit(false);//开启事务
            String SQl1 = "update account set banlance = banlance - ? where id = ?";
            String SQl2 = "update account set banlance = banlance + ? where id = ?";
            pstmt1 = conn.prepareStatement(SQl1);
            pstmt2 = conn.prepareStatement(SQl2);
            pstmt1.setDouble(1 , 500);
            pstmt1.setInt(2 , 1);
            pstmt2.setDouble(1 , 500);
            pstmt2.setInt(2 , 2);
            pstmt1.executeUpdate();
            pstmt2.executeUpdate();
            conn.commit();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (Exception e){
            //事务回滚
            if(conn != null) {
                conn.rollback();
            }
        }
    }
}

package Summarize.JDBC;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class JDBC_Database_connection_pool_Druid_Utils {
    private static DataSource ds;

    static {
        try {
            //加载配置文件
            Properties pro = new Properties();
            pro.load(JDBC_Database_connection_pool_Druid_Utils.class.getResourceAsStream("druid.properties"));
            //获取DataScource
            ds = DruidDataSourceFactory.createDataSource(pro);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //获取连接
    static Connection getConnection() throws SQLException {
        return ds.getConnection();
    }

    //释放资源
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

    //获取连接池方法
    static DataSource getDataSource(){
        if(ds != null) return ds;
        return null;
    }
}

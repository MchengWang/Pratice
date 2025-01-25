package Summarize.JDBC;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;

public class JDBC_c3p0Demo1 {
    public static void main(String[] args) throws SQLException {
        //创建数据库连接池对象，使用默认配置
        DataSource ds = new ComboPooledDataSource();
        //获取连接
        Connection conn = ds.getConnection();
        System.out.println(conn);
    }
}

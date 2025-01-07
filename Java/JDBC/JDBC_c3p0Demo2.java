package Summarize.JDBC;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;

public class JDBC_c3p0Demo2 {
    public static void main(String[] args) throws SQLException {
        //创建数据库连接池对象，使用指定配置
        DataSource ds = new ComboPooledDataSource("c3p0-config.xml");
        //获取连接
        for (int i = 0; i < 10; i++) {
            Connection conn = ds.getConnection();
            System.out.println(conn);
            if(i == 5) {
                conn.close();
            }
        }

    }
}

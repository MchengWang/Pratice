package Summarize.JDBC;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.Connection;
import java.util.Properties;

public class JDBC_Database_connection_pool_Druid {
    /*步骤：
    *   1、导入jar包 druid-1.0.9.jar
    *   2、定义配置文件
    *       是properties形式的 initialsize 初始个数 maxActive 最大个数 maxWait 等待时间
    *       可以叫任意名称，可以放在任意目录下
    *   3、获取数据库连接池对象，通过工厂类来获取DruidDataSourceFactory
    *   4、获取连接*/
    public static void main(String[] args) throws Exception {
        //1、
        //2、
        //3、
        Properties pro = new Properties();
        InputStream is = JDBC_Database_connection_pool_Druid.class.getClassLoader()
                .getResourceAsStream("META-INF/druid.properties");
        pro.load(is);
        //4、
        DataSource ds = DruidDataSourceFactory.createDataSource(pro);
        //5、
        Connection conn = ds.getConnection();
    }
}

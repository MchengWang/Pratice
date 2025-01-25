package Summarize.JDBC;

import org.springframework.jdbc.core.JdbcTemplate;

public class JDBC_Spring_JDBCTemplte_test {
    public static void main(String[] args) {
        //导入jar包
        //创建JDBCTemple对象
        JdbcTemplate  template = new JdbcTemplate(JDBC_Database_connection_pool_Druid_Utils.getDataSource());
        //调用方法
        String sql = "insert into staff values (? , ? , ?)";
        int count = template.update(sql , "hh" , 14 , "男");
        System.out.println(count);
    }
}

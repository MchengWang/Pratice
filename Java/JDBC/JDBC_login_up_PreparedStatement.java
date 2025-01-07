package Summarize.JDBC;

import java.sql.*;
import java.util.Scanner;

public class JDBC_login_up_PreparedStatement {
    /*PreparedStatement对象
    * 1、SQL注入问题（在拼接SQL时一些SQL特殊关键字参与，会造成安全性问题）
    *   1、用户随便输入，输入密码“a' or ' a ' =  ' a”
    *   2、SQl select * from user where name = 'fafa' and password = 'a' or 'a' = 'a';
    * 2、解决SQL注入问题，使用preparedStement对象来解决
    * 3、预编译的SQL：参数使用？作为占位符
    * 4、步骤
    *   1、导入驱动
    *   2、注册驱动
    *   3、获取数据库连接对象
    *   4、定义SQL
    *       注意：SQL的参数使用？作为占位符，如select * from user where name = ? and password = ?;
    *   5、获取执行sql语句的对象 PreparedStement connection.PreparedStement(String sql)
    *   6、给？赋值
    *       1、方法  void setArray(int parameterIndex, Array x) 将指定的参数设置为给定的 java.sql.Array对象。
                    void setAsciiStream(int parameterIndex, InputStream x) 将指定的参数设置为给定的输入流。
                    void setAsciiStream(int parameterIndex, InputStream x, int length) 将指定的参数设置为给定的输入流，它将具有指定的字节数。
                    void setAsciiStream(int parameterIndex, InputStream x, long length) 将指定的参数设置为给定的输入流，它将具有指定的字节数。
                    void setBigDecimal(int parameterIndex, BigDecimal x) 将指定的参数设置为给定的 java.math.BigDecimal值。
                    void setBinaryStream(int parameterIndex, InputStream x) 将指定的参数设置为给定的输入流。
                    void setBinaryStream(int parameterIndex, InputStream x, int length) 将指定的参数设置为给定的输入流，它将具有指定的字节数。
                    void setBinaryStream(int parameterIndex, InputStream x, long length) 将指定的参数设置为给定的输入流，它将具有指定的字节数。
                    void setBlob(int parameterIndex, Blob x) 将指定的参数设置为给定的 java.sql.Blob对象。
                    void setBlob(int parameterIndex, InputStream inputStream) 将指定的参数设置为 InputStream对象。
                    void setBlob(int parameterIndex, InputStream inputStream, long length) 将指定的参数设置为 InputStream对象。
                    void setBoolean(int parameterIndex, boolean x) 将指定的参数设置为给定的Java boolean值。
                    void setByte(int parameterIndex, byte x) 将指定的参数设置为给定的Java byte值。
                    void setBytes(int parameterIndex, byte[] x) 将指定的参数设置为给定的Java字节数组。
                    void setCharacterStream(int parameterIndex, Reader reader) 将指定的参数设置为给定的 Reader对象。
                    void setCharacterStream(int parameterIndex, Reader reader, int length) 将指定的参数设置为给定的 Reader对象，这是给定的长度的字符数。
                    void setCharacterStream(int parameterIndex, Reader reader, long length) 将指定的参数设置为给定的 Reader对象，这是给定的长度的字符数。
                    void setClob(int parameterIndex, Clob x) 将指定的参数设置为给定的 java.sql.Clob对象。
                    void setClob(int parameterIndex, Reader reader) 将指定的参数设置为 Reader对象。
                    void setClob(int parameterIndex, Reader reader, long length) 将指定的参数设置为 Reader对象。
                    void setDate(int parameterIndex, Date x) 使用运行应用程序的虚拟机的默认时区将指定的 java.sql.Date设置为给定的 java.sql.Date值。
                    void setDate(int parameterIndex, Date x, Calendar cal) 使用给定的 Calendar对象将指定的 Calendar设置为给定的 java.sql.Date值。
                    void setDouble(int parameterIndex, double x) 将指定的参数设置为给定的Java double值。
                    void setFloat(int parameterIndex, float x) 将指定的参数设置为给定的Java float值。
                    void setInt(int parameterIndex, int x) 将指定的参数设置为给定的Java int值。
                    void setLong(int parameterIndex, long x) 将指定的参数设置为给定的Java long值。
                    void setNCharacterStream(int parameterIndex, Reader value) 将指定的参数设置为 Reader对象。
                    void setNCharacterStream(int parameterIndex, Reader value, long length) 将指定的参数设置为 Reader对象。
                    void setNClob(int parameterIndex, NClob value) 将指定的参数设置为 java.sql.NClob对象。
                    void setNClob(int parameterIndex, Reader reader) 将指定的参数设置为 Reader对象。
                    void setNClob(int parameterIndex, Reader reader, long length) 将指定的参数设置为 Reader对象。
                    void setNString(int parameterIndex, String value) 将指定的参数设置为给定的 String对象。
                    void setNull(int parameterIndex, int sqlType) 将指定的参数设置为SQL NULL 。
                    void setNull(int parameterIndex, int sqlType, String typeName) 将指定的参数设置为SQL NULL 。
                    void setObject(int parameterIndex, Object x) 使用给定对象设置指定参数的值。
                    void setObject(int parameterIndex, Object x, int targetSqlType) 使用给定对象设置指定参数的值。
                    void setObject(int parameterIndex, Object x, int targetSqlType, int scaleOrLength) 使用给定对象设置指定参数的值。
                    default void setObject(int parameterIndex, Object x, SQLType targetSqlType) 使用给定对象设置指定参数的值。
                    default void setObject(int parameterIndex, Object x, SQLType targetSqlType, int scaleOrLength) 使用给定对象设置指定参数的值。
                    void setRef(int parameterIndex, Ref x) 将指定的参数设置为给定的 REF(<structured-type>)值。
                    void setRowId(int parameterIndex, RowId x) 将指定的参数设置为给定的 java.sql.RowId对象。
                    void setShort(int parameterIndex, short x) 将指定的参数设置为给定的Java short值。
                    void setSQLXML(int parameterIndex, SQLXML xmlObject) 将指定的参数设置为给定的 java.sql.SQLXML对象。
                    void setString(int parameterIndex, String x) 将指定的参数设置为给定的Java String值。
                    void setTime(int parameterIndex, Time x) 将指定的参数设置为给定的 java.sql.Time值。
                    void setTime(int parameterIndex, Time x, Calendar cal) 使用给定的 Calendar对象将指定的 Calendar设置为给定的 java.sql.Time值。
                    void setTimestamp(int parameterIndex, Timestamp x) 将指定的参数设置为给定的 java.sql.Timestamp值。
                    void setTimestamp(int parameterIndex, Timestamp x, Calendar cal) 使用给定的 Calendar对象将指定的 Calendar设置为给定的 java.sql.Timestamp值。
                    void setUnicodeStream(int parameterIndex, InputStream x, int length) 已弃用 使用setCharacterStream
                    void setURL(int parameterIndex, URL x) 将指定的参数设置为给定的 java.net.URL值。
                    * 参数1、？的位置从1开始
                    * 参数2 ？的值
          7、执行sql，接收返回结果，不用传递参数SQL语句
        * 8、处理结果
        * 9、释放资源
     5、注意：后期都会使用PrepreadStement来完成增删待查的所有操作
     *  1、可以防止SQL注入
     *  2、效率更高*/
    static boolean login(String user , String password){
        if(user == null || password == null) return false;
        //获取链接
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        try {
            conn = JDBC_JDBCUtils.getConnection();
            String sql = "select * from user where user = ? and password = ?";
            stmt = conn.prepareStatement(sql);
            //给？赋值
            stmt.setString(1 , user);
            stmt.setString(2 , password);
            rs = stmt.executeQuery();
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
        if(b) System.out.println("登陆成功");
        else System.out.println("登陆失败");
    }
}

package Summarize.JDBC;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class JDBC_ResultSet {
    /*ResultSet 结果集对象，封装查询情况
    * boolean next()  将光标从当前位置向前移动一行。
    * Array getArray(int columnIndex) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Array对象检索。
    * Array getArray(String columnLabel) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Array对象检索。
    * InputStream getAsciiStream(int columnIndex) 将此 ResultSet对象的当前行中指定列的值作为ASCII字符流检索。
    * InputStream getAsciiStream(String columnLabel) 将此 ResultSet对象的当前行中指定列的值作为ASCII字符流检索。
    * BigDecimal getBigDecimal(int columnIndex)将此 ResultSet对象的当前行中指定列的值作为 java.math.BigDecimal以完全精确的方式获取。
    * BigDecimal getBigDecimal(String columnLabel) 将此 ResultSet对象的当前行中的指定列的值作为 java.math.BigDecimal完全精确检索。
    * InputStream getBinaryStream(int columnIndex) 将此 ResultSet对象的当前行中的指定列的值作为未解释的字节流检索。
    * InputStream getBinaryStream(String columnLabel) 将此 ResultSet对象的当前行中的指定列的值 ResultSet为未解释的流 byte s。
    * Blob getBlob(int columnIndex) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Blob对象检索。
    * Blob getBlob(String columnLabel) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Blob对象检索。
    * boolean getBoolean(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 boolean的Java编程语言。
    * boolean getBoolean(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 boolean的Java编程语言。
    * byte getByte(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 byte的Java编程语言。
    * byte getByte(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 byte的Java编程语言。
    * byte[] getBytes(int columnIndex) 将该 ResultSet对象的当前行中的指定列的值作为Java编程语言中的 byte数组检索。
    * byte[] getBytes(String columnLabel) 将该 ResultSet对象的当前行中的指定列的值作为Java编程语言中的 byte数组检索。
    * Reader getCharacterStream(int columnIndex) 将此 ResultSet对象的当前行中的指定列的值 ResultSet为 java.io.Reader对象。
    * Reader getCharacterStream(String columnLabel) 将此 ResultSet对象的当前行中的指定列的值 ResultSet为 java.io.Reader对象。
    * Clob getClob(int columnIndex) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Clob对象检索。
    * Clob getClob(String columnLabel) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Clob对象检索。
    * int getConcurrency() 检索此 ResultSet对象的并发模式。
    * String getCursorName() 检索此 ResultSet对象使用的SQL游标的名称。
    * Date getDate(int columnIndex) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Date对象检索。
    * Date getDate(int columnIndex, Calendar cal) 将此 ResultSet对象的当前行中指定列的值 ResultSet为Java编程语言中的 java.sql.Date对象。
    * Date getDate(String columnLabel) 将此 ResultSet对象的当前行中的指定列的值作为Java编程语言中的 java.sql.Date对象检索。
    * Date getDate(String columnLabel, Calendar cal) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Date对象检索。
    * double getDouble(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 double的Java编程语言。
    * double getDouble(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 double的Java编程语言。
    * int getFetchDirection() 检索此 ResultSet对象的抓取方向。
    * int getFetchSize() 检索此 ResultSet对象的提取大小。
    * float getFloat(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 float的Java编程语言。
    * float getFloat(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 float的Java编程语言。
    * int getHoldability() 检索此 ResultSet对象的 ResultSet
    * int getInt(int columnIndex) 这个检索的当前行中指定列的值 ResultSet作为对象 int在Java编程语言。
    * int getInt(String columnLabel) 以Java编程语言中的 int此 ResultSet对象的当前行中指定列的值。
    * long getLong(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 long的Java编程语言。
    * long getLong(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 long的Java编程语言。
    * ResultSetMetaData getMetaData() 检索此 ResultSet对象的列的数量，类型和属性。
    * Reader getNCharacterStream(int columnIndex) 将此 ResultSet对象的当前行中的指定列的值 ResultSet为 java.io.Reader对象。
    * Reader getNCharacterStream(String columnLabel) 将此 ResultSet对象的当前行中的指定列的值 ResultSet为 java.io.Reader对象。
    * NClob getNClob(int columnIndex) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 NClob对象检索。
    * NClob getNClob(String columnLabel) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 NClob对象检索。
    * String getNString(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 String的Java编程语言。
    * String getNString(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 String的Java编程语言。
    * Object getObject(int columnIndex) 获取此的当前行中指定列的值 ResultSet作为对象 Object在Java编程语言。
    * <T> T getObject(int columnIndex, 类<T> type) 检索此 ResultSet对象的当前行中指定列的值，并将转换为SQL类型的列到所请求的Java数据类型，如果转换支持。
    * Object getObject(int columnIndex, Map<String,类<?>> map) 这个检索的当前行中指定列的值 ResultSet作为对象 Object在Java编程语言。
    * Object getObject(String columnLabel) 获取此的当前行中指定列的值 ResultSet作为对象 Object在Java编程语言。
    * <T> T getObject(String columnLabel, 类<T> type) 检索此 ResultSet对象的当前行中指定列的值，并将转换为SQL类型的列到所请求的Java数据类型，如果转换支持。
    * Object getObject(String columnLabel, Map<String,类<?>> map) 这个检索的当前行中指定列的值 ResultSet作为对象 Object在Java编程语言。
    * Ref getRef(int columnIndex) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Ref对象检索。
    * Ref getRef(String columnLabel) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 Ref对象检索。
    * int getRow() 检索当前行号。
    * RowId getRowId(int columnIndex) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.RowId对象检索。
    * RowId getRowId(String columnLabel) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.RowId对象检索。
    * short getShort(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 short的Java编程语言。
    * short getShort(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 short的Java编程语言。
    * SQLXML getSQLXML(int columnIndex) 这个检索的当前行中指定列的值 ResultSet为 java.sql.SQLXML的Java编程语言对象。
    * SQLXML getSQLXML(String columnLabel) 这个检索的当前行中指定列的值 ResultSet为 java.sql.SQLXML的Java编程语言对象。
    * Statement getStatement() 检索 Statement生成此对象 ResultSet对象。
    * String getString(int columnIndex) 这个检索的当前行中指定列的值 ResultSet对象为 String的Java编程语言。
    * String getString(String columnLabel) 这个检索的当前行中指定列的值 ResultSet对象为 String的Java编程语言。
    * Time getTime(int columnIndex) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Time对象检索。
    * Time getTime(int columnIndex, Calendar cal) 将此 ResultSet对象的当前行中的指定列的值作为Java编程语言中的 java.sql.Time对象检索。
    * Time getTime(String columnLabel) 将此 ResultSet对象的当前行中的指定列的值作为Java编程语言中的 java.sql.Time对象检索。
    * Time getTime(String columnLabel, Calendar cal) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Time对象检索。
    * Timestamp getTimestamp(int columnIndex) 将该 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Timestamp对象检索。
    * Timestamp getTimestamp(int columnIndex, Calendar cal) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Timestamp对象检索。
    * Timestamp getTimestamp(String columnLabel) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的 java.sql.Timestamp对象检索。
    * Timestamp getTimestamp(String columnLabel, Calendar cal) 将此 ResultSet对象的当前行中指定列的值作为Java编程语言中的
    * java.sql.Timestamp对象检索。
    * int getType() 检索此 ResultSet对象的类型。
    * 参数： int 代表列的编号（从一开始）如getString(1)获取而第一列的值
    *       String 代表列名，如getString("banlance");
    * 如何正确的使用ResultSet结果集对象
    * 注意：使用步骤
    *   1、游标向下移动一行
    *   2、判断是否有数据
    *   3、获取数据
    *   boolean next()  将光标从当前位置向前移动一行。判断当前是否为最后一行，末尾是否有数据，如何是则返回false，如果不是则返回true；
    *   */
    public static void main(String[] args) throws Exception{
        //1 导入jar包 1-1复制jar包到项目的libs目录下 1-2libs右键add as library
        //2 注册驱动
        Class.forName("com.mysql.JDBC.Driver");
        // 3 获取数据库连接对象
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/数据库名称", "账户名", "密码");
        //4 定义SQL语句
        String sql = "SQL语句";
        //5 获取执行SQL语句的对象 Statement
        Statement s = conn.createStatement();
        //6 获取结果集
        ResultSet rs = s.executeQuery(sql);
        //处理结果
        //让游标向下移动一行
        while(rs.next()) {
            int id = rs.getInt(1);
            String name = rs.getString("name");
            double banlance = rs.getDouble(3);
            System.out.println(id + " -- " + name + " -- " + banlance);
        }
        //8 释放资源
        conn.close();
        s.close();
        rs.close();
    }
}

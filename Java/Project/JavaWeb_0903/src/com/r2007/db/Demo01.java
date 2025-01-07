package com.r2007.db;
import java.sql.*;

public class Demo01 {

	
	public static void main(String[] args) {
		Connection con = null;
		PreparedStatement ps = null;
		try {
			//1.加载驱动
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			//2.建立连接
			con = DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;databaseName=R2007_01",
					"sa", "1");
			//3.准备sql语句
			String sql = "insert into users values (?,?,?,?)";
			//4.创建访问连接
			ps = con.prepareStatement(sql);
			//4.2设置参数
			ps.setString(1, "ww");
			ps.setString(2, "qq");
			ps.setString(3, "ee");
			ps.setString(4, "22");
			//5.执行sql语句
			int count = ps.executeUpdate();
			//6.处理返回结果
			if(count>0) {
				System.out.println("执行插入成功");
			}else {
				System.out.println("执行插入失败");
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			//7.关闭连接
			try {
				if(ps!=null) ps.close();
				if(con!=null) con.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	
}

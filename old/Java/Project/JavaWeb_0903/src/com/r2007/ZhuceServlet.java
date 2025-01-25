package com.r2007;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ZhuceServlet
 */
@WebServlet("/ZhuceServlet")
public class ZhuceServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//注册的信息提交到doPost中了，所以我们只用在 doPost中做处理
		//1.解决中文乱码，并获取页面传递过来的数据
		response.setContentType("text/html;charset=UTF-8");
		String userName = request.getParameter("userName");
		String userPwd = request.getParameter("userPwd");
		String nickName = request.getParameter("nickName");
		String age = request.getParameter("age");
		
		//用户名和昵称进行中文乱码的解决
		userName = new String(userName.getBytes("ISO-8859-1"), "UTF-8");
		nickName = new String(nickName.getBytes("ISO-8859-1"), "UTF-8");
		//下一步去数据库操作
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
			ps.setString(1, userName);
			ps.setString(2, userPwd);
			ps.setString(3, nickName);
			ps.setString(4, age);
			//5.执行sql语句
			int count = ps.executeUpdate();
			//6.处理返回结果
			if(count>0) {
				response.getWriter().append("注册成功！ <a href='denglu.jsp'>请去登录</a>");
				System.out.println("执行插入成功");
			}else {
				response.getWriter().append("注册失败，请再次尝试！");
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

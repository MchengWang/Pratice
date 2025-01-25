package com.r2007;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class DengluServlet
 */
@WebServlet("/DengluServlet")
public class DengluServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * 登录的数据都提交到 post中了  所有只处理这个
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//1.获取登录的信息
		String userName = request.getParameter("userName");
		String userPwd = request.getParameter("userPwd");
		userName = new String(userName.getBytes("ISO-8859-1"), "UTF-8");
		//响应流设置中文编码
		response.setContentType("text/html;charset=UTF-8");
		//2.去数据库中进行比对  操作数据了
		Connection con = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			con = DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;databaseName=R2007_01","sa", "1");
			//准备执行sql
			String sql = "select * from users where userName = ? and userPwd = ?";
			ps = con.prepareStatement(sql);
			//设置值
			ps.setString(1, userName);
			ps.setString(2, userPwd);
			//执行
			rs = ps.executeQuery();
			//解析结果集
			if(rs.next()) {
				//在我们的数据库中注册过了，可以查询出来，意味着登录成功！
				String name = rs.getString("userName");
				String nickName = rs.getString("nickName");
				String age = rs.getString("age");
				response.getWriter().append("登录成功！欢迎使用xxx系统! 您的个人信息为：<br>")
				.append("用户名为：").append(name).append("<br>")
				.append("昵称为：").append(nickName).append("<br>")
				.append("年龄为：").append(age).append("<br>");
			}else {
				//在我们的数据库中没有注册过，所以登录，意味登录失败！
				response.getWriter().append("登录失败！你还没有注册我们网站的会员 <a href='zhuce.jsp'>请去注册！</a>");
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			try {
				if(rs!=null)rs.close();
				if(ps!=null)ps.close();
				if(con!=null)con.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		
		
		
		
	}

}

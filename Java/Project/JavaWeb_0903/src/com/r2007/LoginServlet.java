package com.r2007;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 *  我们需要判断是否登录成功，则需要进行  参数值的获取，并通过java代码来进行对比
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 1. 获取传递的参数
		String userName = request.getParameter("userName");
		String userPwd = request.getParameter("userPwd");
		//中文乱码的转化
		userName = new String(userName.getBytes("ISO-8859-1"), "UTF-8");
		userPwd = new String(userPwd.getBytes("ISO-8859-1"), "UTF-8");
		//对响应的流信息，设置中文编码
		response.setContentType("text/html;charset=UTF-8");
		//2.对密码进行对比
		if(userName.equals("admin") && userPwd.equals("admin123")) {
			//登录成功  提示信息到 浏览器
			response.getWriter().append("登录成功，登录的用户名为：").append(userName);
		}else{
			//登录失败
			response.getWriter().append("登录失败，登录的用户名为：").append(userName);
		}
	}

}

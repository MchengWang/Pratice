<%@ page language="java" pageEncoding="UTF-8"%>

<%
	//应为jsp就是 servlet  他再次就只是充当我们的业务处理页面
	String userName = request.getParameter("userName");
	String userPwd = request.getParameter("userPwd");

	//对比如果是admin 和 admin123 则去登录成功页面，否则去 登录失败页面
	if(userName != null && userPwd != null &&userName.equals("admin") && userPwd.equals("admin123")){
		//如何去成功页面,  使用内部转发, 服务器内部做处理，用户无法感知，且只能 是你自己服务器内部的路径，不能是网络的路径
		//内部转发 他的路径，还是当前页面的路径，  用户不知道真是访问的路径，
		//内部转发 使用的是同一个请求和响应,所以在同一个request作用域中，我们可以访问到他的内容
		request.setAttribute("name", userName);
		request.setAttribute("pwd", userPwd);
		
		request.getRequestDispatcher("success.jsp").forward(request, response);
		
	}else{
		//跳转到失败页面，我们使用重定向功能
		response.sendRedirect("fail.jsp");
	}
	
	
%>

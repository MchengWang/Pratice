<%@ page language="java" pageEncoding="utf-8"%>


<%

	//接受小秘密
	request.setCharacterEncoding("utf-8");
	String mimi = request.getParameter("mimi");
	//把秘密存放在session中，只有当前的这一个浏览器，在本次没有关闭之前可以看到的内容
	session.setAttribute("mimi", mimi);
	
	response.sendRedirect("Demo03.jsp");
	
%>
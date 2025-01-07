<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<p> 登录的用户名或密码错误，请重新登录！3秒后自动跳转到  登录页面！   </p>
	<%=request.getAttribute("name") %> ！ 
	<%=request.getAttribute("pwd") %>
	<%
		response.addHeader("refresh", "3;url=index.jsp");
	%>
</body>
</html>
<%@page import="com.r2007.bean.Users"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	获取到前一个页面传递过来的数据，并封装到javabean中展示
	<%
		//获取数据
		String userName = request.getParameter("userName");
		String userPwd = request.getParameter("userPwd");
		String nickName = request.getParameter("nickName");
		String age = request.getParameter("age");
		//设置已经写好的javabean中
		Users user = new Users();
		user.setUserName(userName);
		user.setUserPwd(userPwd);
		user.setNickName(nickName);
		user.setAge(Integer.parseInt(age));
	%>
	<p>把bean中的数据展示出来</p>
	<p> <%=user.getUserName() %> </p>
	<p> <%=user.getUserPwd() %> </p>
	<p> <%=user.getNickName() %> </p>
	<p> <%=user.getAge() %> </p>
</body>
</html>

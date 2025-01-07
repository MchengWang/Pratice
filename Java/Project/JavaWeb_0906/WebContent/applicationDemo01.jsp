<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

向全局变量 appliction中存放数据，只要项目不关闭，都可以访问到
	<%
		application.setAttribute("name", "R2007YYDS");
	%>
</body>
</html>
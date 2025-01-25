<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<p> 恭喜你，登录成功！ 当前登录的信息为  <%=request.getAttribute("name") %> ！ </p>
	<%=request.getAttribute("pwd") %>
</body>
</html>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		String mimi = (String)session.getAttribute("mimi");
	%>
	<%= mimi!=null?mimi:"你还没有秘密，请去填写" %>
	
</body>
</html>
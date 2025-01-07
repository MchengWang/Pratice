<%@ page language="java" contentType="text/html; UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isErrorPage="true" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<P>进来后，需要先声明我们这个是错误捕捉的页面
	错误捕获页面也其他页面有什么区别那？</P>
	
	<p>捕获到的错误信息为：<%=exception.getMessage() %> </p>
	
	
</body>
</html>
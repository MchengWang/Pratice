<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	一个简单的JSP页面
	<!-- HTML 自己的注释，他可以被jsp输出到浏览器端并进行加载 -->
	
	<%
		//在此对等的符号中写JAVA代码，所以java代码的注释也在此符号中生效，他会被jsp编译到 生成的java中，并不会输出到浏览器端
	%>
	
	<%-- 这是jsp自己的注释，他不会被jsp编译到生成的java代码中，他只有在jsp源码中存在！ --%>
	
</body>
</html>
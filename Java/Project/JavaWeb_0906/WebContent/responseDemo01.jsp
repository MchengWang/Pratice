<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>


	此页面停留三秒钟，取新的页面
	<%
		//响应可以对头信息，添加内容
		//他相当于生成了一个meta内容
		//<meta http-equiv="Refresh" content="3;url=http://blog.csdn.net/haoaiqian" />
		//响应其实是影响浏览器的，由浏览器再次发出的内容，所以和服务无关，从而我们可以取任意的界面
		response.addHeader("refresh", "3;url=http://blog.csdn.net/haoaiqian");
	%>
	
</body>
</html>
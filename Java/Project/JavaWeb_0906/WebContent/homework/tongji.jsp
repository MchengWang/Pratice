<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
1.写一个 jsp页面，统计当前的用户访问量
并在下显示访问时间 以”yyyy年MM月dd日 HH:mm:ss”的格式显示当前的日期
<%! 
	//统计所有人的访问次数，我们用全局变量进行初始化
	int count = 0;
%>
<%
	//局部变量，每次获取的时间都是当前访问者进入的时间
	Date date = new Date();
	SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss");
%>
<p> 当前访问的时间为：<%=sdf.format(date) %>,当前页面被访问了<%=++count %>次。</p>
</body>
</html>
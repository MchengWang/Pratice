<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<% 
	//时间的定义与转化
	Date date = new Date();
	//时间的转化
	SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
	String sj = sdf.format(date);
%>

</head>
<body>
		<h1>个人首页面，系统功能页面</h1>
		<div>
			正经的功能
			输出当前的日期
			<div style="color: red;font-size: 60px">
				当前时间为：<%=sj %>
			</div>
		</div>
		
		
		<!-- 引入脚步页面 -->
		<%@ include file="footer.jsp" %>
		
</body>
</html>
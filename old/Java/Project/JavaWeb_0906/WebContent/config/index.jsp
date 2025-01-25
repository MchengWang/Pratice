<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
  </head>
  <body>
    	<h2>下面的参数来自web.xml文件</h2>
    	<h3>姓名：<%=config.getInitParameter("name") %></h3>
    	<h3>地址：<%=config.getInitParameter("addr") %></h3>
  </body>
</html>

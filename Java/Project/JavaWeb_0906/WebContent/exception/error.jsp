<%@ page language="java" import="java.util.*" 
	pageEncoding="UTF-8" isErrorPage="true"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>    
    <title>错误处理页面</title>
  </head>
  <body>
    <h1>发生了异常，异常信息如下：</h1>
    <h3><%=exception.getMessage() %></h3>
  </body>
</html>

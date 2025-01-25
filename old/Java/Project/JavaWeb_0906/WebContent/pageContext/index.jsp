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
   	//pageContext.setAttribute("gongfu", "太极拳");
   	pageContext.setAttribute("gongfu", "太极拳", pageContext.PAGE_SCOPE);
   	
   	//request.setAttribute("xingming", "张三丰");
   	pageContext.setAttribute("xingming", "张三丰", pageContext.REQUEST_SCOPE);
   	
   	//session.setAttribute("nianling", "108");
   	pageContext.setAttribute("nianling", "108", pageContext.SESSION_SCOPE);
   	
   	//application.setAttribute("dizhi", "武当山");
   	pageContext.setAttribute("dizhi", "武当山", pageContext.APPLICATION_SCOPE);
   %>
    
  </body>
</html>

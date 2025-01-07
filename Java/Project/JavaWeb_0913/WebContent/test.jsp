<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<%
	//取Cookie中的值
	Cookie[] cookies = request.getCookies();
	String color = "#ffffff";
	//遍历找到我们需要的内容
	for(Cookie cookie:cookies){
		if(cookie.getName().equals("color")){
			color = cookie.getValue();
		}
	}
%>
<style type="text/css">
	body {
		background-color: <%=color %>
}
</style>
</head>
<body>
	只要设置一次，cookie不失效的情况下，再次登录到这个页面就一直是设定的背景，
	不需要每次重新设置。
</body>
</html>
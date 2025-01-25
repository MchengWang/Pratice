<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<h3> 输入用户名和密码，如果比对是 admin 和 admin123 则跳转到登录成功页面，如果不是则跳转到登录失败页面 </h3>
	
	<form action="handle.jsp" method="post">
		用户名： <input name="userName" > <br>
		密码：  <input type="password" name="userPwd" > <br>
		<input type="submit" value="登录" >
	</form>
</body>
</html>
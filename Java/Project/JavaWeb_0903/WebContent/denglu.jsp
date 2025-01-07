<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form method="post" action="denglu">
		<table>
			<tr>
				<td>用户名：</td>
				<td> <input type="text" name="userName"> </td>
			</tr>
			<tr>
				<td>密  码：</td>
				<td> <input type="password" name="userPwd"> </td>
			</tr>
			<tr>
				<td colspan=2> <input type="submit" value="登录"> 
					<a href="zhuce.jsp">还没有账号？去注册！</a>
				</td>
			</tr>
		</table>
	</form>
</body>
</html>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form method="post" action="reg01.jsp">
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
				<td>昵  称：</td>
				<td> <input type="text" name="nickName"> </td>
			</tr>
			<tr>
				<td>年 龄：</td>
				<td> <input type="number" name="age"> </td>
			</tr>
			<tr>
				<td colspan=2> <input type="submit" value="注册"> </td>
			</tr>
		</table>
	</form>
</body>
</html>
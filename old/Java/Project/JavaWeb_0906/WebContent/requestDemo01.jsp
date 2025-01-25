<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
创建你的邮箱：
<form action="requestDemo02.jsp" method="post">
	<table>
		<tr>
			<td>
				选择你的邮箱：
			</td>
			<td>
				<input name="zhanghu">
			</td>
			<td>
				@
				<select name="youxiang">
					<option>163.com</option>
					<option>qq.com</option>
					<option>yahoo.com.cn</option>
				</select>
			</td>
		</tr>
		<tr>
			<td>密码：</td>
			<td><input type="password" name="mima"> </td>
		</tr>
		<tr>
			<td>再次输入密码：</td>
			<td><input type="password" name="chongfumima"> </td>
		</tr>
		<tr>
			<td>姓名：</td>
			<td><input  name="xingming"> </td>
		</tr>
		<tr>
			<td>性别：</td>
			<td><input type="radio" name="xingbie" value="man">男 
				<input type="radio" name="xingbie" value="women">女 
			</td>
		</tr>
		<tr>
			<td>中国直邮：</td>
		</tr>
		<tr>
			<td colspan="3">
			 我愿意接受来自中国的直邮，请选择（可多选）
			</td>
		</tr>
		<tr>
			<td colspan="3">
				<input type="checkbox" name="guanggao" value="旅游"> 旅游
				<input type="checkbox" name="guanggao" value="休闲"> 休闲
				<input type="checkbox" name="guanggao" value="财经"> 财经
				<input type="checkbox" name="guanggao" value="汽车"> 汽车
			</td>
		</tr>
		<tr>
			<td colspan="3">
				<input type="checkbox" name="guanggao" value="音乐"> 音乐
				<input type="checkbox" name="guanggao" value="房产"> 房产
				<input type="checkbox" name="guanggao" value="家居"> 家居
				<input type="checkbox" name="guanggao" value="生活"> 生活
			</td>
		</tr>
		<tr>
			<td colspan="3">
				<input type="submit" value="注册邮箱"> 
			</td>
		</tr>
	</table>
	
</form>


</body>
</html>
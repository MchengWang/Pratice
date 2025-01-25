<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
1.设计程序，用户选择选择喜好的背景颜色（红/黄/绿），
提交后创建Cookie并存储用户名及颜色信息，cookie有效期设置为300秒，
然后在当前servlet中跳转到test.jsp页面，
在test.jsp页面显示用户名，及改变页面的背景颜色

	<form action="cookieServlet">
		请选择喜欢的颜色<br>
		<span style="background-color: red;"> 红 </span> <input type="radio" name="color" value="red" checked="checked"><br>
		<span style="background-color: yellow;"> 黄 </span> <input type="radio" name="color" value="yellow"><br>
		<span style="background-color: green;"> 绿 </span> <input type="radio" name="color" value="green"><br>
		<input type="submit">
	</form>


</body>
</html>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<P>用户输入1，我们转化为男生，输入2转化为 女生:
	自己提交给自己， 在action不写参数时</P>
	<form action="">
		请输入需要的参数：<input type="text" name="sex" placeholder="输入1为男生，输入2为女生">
		<br>
		<input type="submit" value="确认">
	</form>
	
	<%
		//这里面，进行servlet的处理   这个演示了我们在jsp的代码中，直接写java代码，其实就是servlet的处理加java的逻辑处理
		//拿去传递的参数
		String sex = request.getParameter("sex");
		//因为是自己传递给自己，所以第一次进来没有值，直接使用，会报错，所以我们需要处理第一次进来的时候
		if(sex!=null && sex.equals("1")){
			out.print("当前输入的为男生！");
		}
		
		if(sex!=null && sex.equals("2")){
			out.print("当前输入的为女生！");
		}
	%>

</body>
</html>
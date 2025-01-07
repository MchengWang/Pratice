<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	使用 jsp编写  带有java代码的内容
	
	<%
		//这里写的就是java 代码，但是我们需要思考，这里的代码会生成到哪里？
		//他又什么样的作用
		int num = 10;
		
		System.out.println(num);//输出到本地的console控制台中
		out.print("<br>输出的变量num为： "+num);//随着响应流返回浏览器端
		num = num + 120;
	%>
	
	<p>在正常的html中输出我们的java代码中的变量  <% out.print(num); %>
	   上面的写法很繁琐，所以我们可以使用变量的输出语法  <%=num %>
	
	</p>
	
	
	
	
	
</body>
</html>
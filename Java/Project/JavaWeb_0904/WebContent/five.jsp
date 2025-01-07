<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	全局变量的定义
	<%! 
		int num = 0;
		//out.print(num);
		
		//还可以定义一个方法！后我们可以进行方法的调用
		public int add(int num1,int num2){
			return num1+num2;
		}
		
	%>
	<p>调用当前页面中，定义的 方法 add方法 <%=add(3,5) %>
	<p>输出全局变量 num值 <%=num %></p>
	<p>当前访问的次数为第<%=++num %>次</p>
</body>
</html>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<p>输出1-100的值，并且每10个值一换行</p>
	<%
		//使用for循环，循环输出固定的值
		for(int i=1;i<=100;i++){
			out.print(i+"  ");
			//判断当前是否可以被10整除，如果可以整除则增加 <br>
			if(i%10==0){
				out.print("<br/>");
			}
		}
	%>

</body>
</html>
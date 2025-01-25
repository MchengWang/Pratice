<%@page import="com.r2007.bean.Users"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	获取到前一个页面传递过来的数据，并封装到javabean中展示
	<%
	//中文转化 
	request.setCharacterEncoding("UTF-8");//不论是get还是post在jsp中都可以转化中文乱码
	%>
	使用 jsp动作 初始化一个users对象，并把他存放在 request的作用域中
	<jsp:useBean id="user" class="com.r2007.bean.Users" scope="request"></jsp:useBean>
	使用jsp动作，给初始化的 bean设定值，值通过传递过来的参数进行使用，注意！！！！ 传递过来的参数，他的name值必须和
	javabean中属性一一对应才可以！
	<jsp:setProperty property="*" name="user"/>
	
	<p>把bean中的数据展示出来</p>
	<p> <%=user.getUserName() %> </p>
	<p> <%=user.getUserPwd() %> </p>
	<p> <%=user.getNickName() %> </p>
	<p> <%=user.getAge() %> </p>
	使用jsp动作取出数据
	<jsp:getProperty property="age" name="user"/>
</body>
</html>

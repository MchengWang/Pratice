<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isErrorPage="true" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h4>1.JSP的隐式对象是什么意思，包含了那些内容？</h4>
	<p>jsp的隐式对象就是  jsp在生成java代码时，自动给我们生成的对象的变量名称：</p>
	<p>包括8个自动生成的对象内容：</p>
	  <p>request，response，pageContext，session，application，config，out，page</p>
	  <p>还有一个自动生成的对象：</p>
	  <p>exception （他必须指定当前页面为错误处理页面，也就是  isErrorPage="true"的时候才会产生）</p>
	<h4>2.每块分别是什么作用和概念：</h4>
		<ul>
			<li>
				请求与响应的内容：out、request和response
				<ol>
					<li>request 请求的对象，里面包含所有请求的内容，ip，参数……</li>
					<li>response 响应的对象，里面包含所有响应的内容，输出到页面的编码格式，……</li>
					<li>out 随着响应流输出到客户端的内容。</li>
				</ol>
			</li>
			<li>
				作用域通信和控制对象：
				<ol>
					<li>session 谁访问，记录谁的信息，多个浏览器之间互不干扰，各自记录 </li>
					<li>application 为整个项目的全局变量存储地点，他随着tomcat启动而启动，tomcat关闭而关闭 </li>
					<li>pageContext  </li>
				</ol>
			</li>
			<li>
				Servlet其它相关对象：
				<ol>
					<li>page  </li>
					<li>config  </li>
					<li>exception  </li>
				</ol>
			</li>
		</ul>
</body>
</html>
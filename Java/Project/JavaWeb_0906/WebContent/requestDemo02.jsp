<%@page import="java.util.Set"%>
<%@page import="java.util.Map"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	//在老版本的servlet中，我们需要对中文进行处理
	request.setCharacterEncoding("UTF-8");//老版本的中文会乱码
	
	//1.通过 拿去到所有值的map 并循环遍历，拿去所有的数据
		//拿到所有的  前台传递过来的数据，key为 name值所设置的参数名称   value 为对应用户输入或选择的内容
		Map<String,String[]> map = request.getParameterMap();
		//Map的遍历，拿出来所有的key值
		Set<String> keys = map.keySet();
		for(String key:keys){
			//通过key值拿去到所有的value值
			out.print(key+": ");
			String[] values = map.get(key);
			for(String value : values){
				out.print(value+"  ");
			}
			out.print("<br/>");
		}
	%>
	<hr>
	<%
		//2.每一个值分别拿取
		String zhanghu = request.getParameter("zhanghu");
		String youxiang = request.getParameter("youxiang");
		String mima = request.getParameter("mima");
		String chongfumima = request.getParameter("chongfumima");
		String xingming = request.getParameter("xingming");
		String xingbie = request.getParameter("xingbie");
		String guanggao = request.getParameter("guanggao");
		//如果前台传递的name对应多个的时候，也就是会产生多个value值，那么我们需要 使用获取数组的方法拿取到对应的值
		String[] guanggaos = request.getParameterValues("guanggao");
	
		if(!mima.equals(chongfumima)){
			out.print("两次输入的密码不一致");
		}
	%>
	<p>账户：<%=zhanghu %> @ <%=youxiang %></p>
	<p>密码：<%=mima %></p>
	<p>重复密码：<%=chongfumima %></p>
	<p>姓名：<%=xingming %></p>
	<p>性别：<%=xingbie %></p>
	<p>广告：<%=guanggao %></p>
	<p>广告：<%
		for(String str:guanggaos){
			out.print(str+" ");
		}
	 %></p>
	<hr>
	<p>request中的其他方法及概念：</p>
	Attribute : 是一个作用域的概念，也就是你后台设定的参数，在那些情况下会被访问到，
	<%
		//设置访问域的值；	
		request.setAttribute("key", "request中的Attribute 只能在request中访问，一般用于内部转发时，多个页面可以访问到的内容");
		//获取到访问域的值； 所有Attribute 中设置的key 都为 String数据类型  value都为 object对象，我们需要自己转化为对应的数据类型
		String str = (String)request.getAttribute("key");
	%>
	输出<%=str %>
	<p>String getProtocol()	返回使用的协议版本 : <%=request.getProtocol() %></p>
	<p>String getContextPath( ) 	返回请求context 路径(即/站点名称): <%=request.getContextPath() %></p>
	<p>String getMethod( )	返回http 的方法(get、post、put等)  :<%=request.getMethod() %></p>
	<p>String getRequestURI( ) 	返回请求URI，不包括请求的查询字符串 :<%=request.getRequestURI() %></p>
	<p>String getRequestURL( ) 	返回请求的全部URL，包括协议、服务器名字和端口、请求的URI，但不包括请求的查询字符串 :<%=request.getRequestURL() %></p>
	<p>String getRemoteAddr( )  返回浏览器的ip地址 :<%=request.getRemoteAddr() %></p>
	
	<% System.out.println("当前访问的IP为："+request.getRemoteAddr()); %>
</body>
</html>
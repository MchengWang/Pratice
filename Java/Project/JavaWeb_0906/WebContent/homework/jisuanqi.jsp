<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<p>
2.扩展题目
 写一个 计算乘法的 jsp页面， 页面有两个 输入框，提交到自身jsp页面中， 并定义乘法方法计算，输出内容
</p>


	<%
		//1.获取当前页面的值： 注意第一次进来是一定没有值的，需要处理报错的情况
		String num1 = request.getParameter("num1");
		String num2 = request.getParameter("num2");
		String xz = request.getParameter("xz");
		double res = 0;
		//对第一进入的空值做处理
		if(num1!=null && num2!=null && xz!=null){
			//正常的计算, 1.数值类型转换
			double n1 = Double.parseDouble(num1);
			double n2 = Double.parseDouble(num2);
			//2.对比选中的符号，从而进行计算，定义一个接受的结果
			if(xz.equals("+")){
				res = n1 + n2;
			}else if(xz.equals("-")){
				res = n1 - n2;
			}else if(xz.equals("*")){
				res = n1 * n2;
			}else if(xz.equals("/")){
				res = n1 / n2;
			}
			//把计算的结果进行输出
		}else{
			out.print("<p style='color:red;'>请输入对应的数值，以进行计算</p>");
		}
	%>
	
	<form action="">
	<input name="num1" type="number" placeholder="输入第一个值" value="<%=num1!=null?num1:"" %>"> 
	
	<select name="xz">
		<option value="+" <%=xz!=null&&xz.equals("+")?"selected='selected'":"" %> >+</option>
		<option value="-" <%=xz!=null&&xz.equals("-")?"selected='selected'":"" %> >-</option>
		<option value="*" <%=xz!=null&&xz.equals("*")?"selected='selected'":"" %> >*</option>
		<option value="/" <%=xz!=null&&xz.equals("/")?"selected='selected'":"" %> >/</option>
	</select>
	
	<input name="num2" type="number" placeholder="输入第二个值" value="<%=num2!=null?num2:"" %>">
	
	<input type="submit" value="="> <%=res %>
</form>
	
	<p>底部引入访问的人次</p>
	
	<%@ include file="tongji.jsp" %>
	
	
</body>
</html>
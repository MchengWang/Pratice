<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>

<style type="text/css">
	img {
		width: 100px;
	}
</style>

<%
	//拿去到全局变量中定义的内容：
	Integer bzfCount = (Integer)application.getAttribute("bzfCount");
	bzfCount = bzfCount!=null?bzfCount:0;
	
	Integer hsrCount = (Integer)application.getAttribute("hsrCount");
	hsrCount = hsrCount!=null?hsrCount:0;
	
	Integer tcpgCount = (Integer)application.getAttribute("tcpgCount");
	tcpgCount = tcpgCount!=null?tcpgCount:0;
	
	double count = bzfCount+hsrCount+ tcpgCount;
	double b = bzfCount/count;
	double h = hsrCount/count;
	double t = tcpgCount/count;
%>

</head>
<body>
<h1>投票的结果：</h1>
	<h3> 你觉得下面那些东西好吃？  </h3>
		<div> 
			  <img alt="" src="./bzf.jpg"> <br>
			煲仔饭 投票的次数为： <%=bzfCount %><br>
			占比：<%=b*100 %> %
		</div>
		<div>  <img alt="" src="./hsr.jpg"><br>
			红烧肉 投票的次数为： <%=hsrCount %> <br>
			占比：<%=h*100 %> %
		</div>
		<div> <img alt="" src="./tcpg.jpg"><br>
			糖醋排骨  投票的次数为： <%=tcpgCount %><br>
			占比：<%=t*100 %> %
		</div>
</body>
</html>
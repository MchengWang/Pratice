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

</head>
<body>

<h1>投下你心目中重要的票</h1>
	<h3> 你觉得下面那些东西好吃？  </h3>
	<form action="voteHandle.jsp">
		<div> <input type="radio" name="food" value="bzf"> 煲仔饭 <img alt="" src="./bzf.jpg"> </div>
		<div> <input type="radio" name="food" value="hsr"> 红烧肉 <img alt="" src="./hsr.jpg"> </div>
		<div> <input type="radio" name="food" value="tcpg"> 糖醋排骨 <img alt="" src="./tcpg.jpg"> </div>
		<input type="submit" value="投票">
	</form>
</body>
</html>
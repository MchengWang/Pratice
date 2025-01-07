<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>餐桌使用情况</title>
<link rel="stylesheet" href="${APP_CONTEXT}/js/bootstrap-3.3.7-dist/css/bootstrap.css">
<link rel="stylesheet" href="js/layui/css/layui.css">
<script src="${APP_CONTEXT}/js/layui/layui.all.js"></script>
<script src="${APP_CONTEXT}/js/jquery-3.2.1.js"></script>
<script src="${APP_CONTEXT}/js/layui/layui.js"></script>
<script src="${APP_CONTEXT}/js/bootstrap-3.3.7-dist/js/bootstrap.js"></script>
<script src="${APP_CONTEXT}/js/canzuosyqk.js"></script>
</head>
<body>
	 
	<section style="width: 143px;margin-top: 10px;margin-left: 10px;">
		<button id="refresh" type="button" class="btn btn-default btn-sm">
			<span class="glyphicon glyphicon-refresh"></span> 空闲餐桌
		</button>
	</section>
	<section class="col-md-12">
		<c:forEach items="${dtableList1}" var="dtableList1">
		<div class="col-sm-6 col-md-2" style="margin-top:20px;">
			<div class="thumbnail">
				<img src="${APP_CONTEXT}/img/cz.png" class="img-circle" />
			</div>
			<div class="caption text-center">
				<h3>餐桌号：${dtableList1.tableNum}</h3>
				<h3 style="color: red;margin-top: 5px;">可坐人数：${dtableList1.tablePernum}</h3>
				<p style="margin-top: 10px;">
					<button type="button" name="jz1" class="btn btn-default btn-sm">
						<span class="glyphicon glyphicon-ok"></span> 就坐
					</button>
					<input type="text" name="tabid1" value="${dtableList1.id}" readonly="readonly" hidden="hidden">
				</p>
			</div>
		</div>
		</c:forEach>
	</section>
	 <br>
	 <hr>
	 <br>
	<section style="width: 143px;margin-top: 10px;margin-left: 10px;">
		<button id="refresh" type="button" class="btn btn-default btn-sm">
			<span class="glyphicon glyphicon-refresh"></span> 已经使用的餐桌
		</button>
	</section>
	<section class="col-md-12">
		<c:forEach items="${dtableList2}" var="dtableList2">
		<div class="col-sm-6 col-md-2" style="margin-top:20px;">
			<div class="thumbnail">
				<img src="${APP_CONTEXT}/img/cz.png" class="img-circle" />
			</div>
			<div class="caption text-center">
				<h3>餐桌号：${dtableList2.tableNum}</h3>
				<h3 style="color: red;margin-top: 5px;">可坐人数：${dtableList2.tablePernum}</h3>
				<p style="margin-top: 10px;">
					<button type="button" name="jz2" class="btn btn-default btn-sm">
						<span class="glyphicon glyphicon-ok"></span> 离桌
					</button>
					<input type="text" name="tabid2" value="${dtableList2.id}" readonly="readonly" hidden="hidden">
				</p>
			</div>
		</div>
		</c:forEach>
	</section>
</body>
</html>
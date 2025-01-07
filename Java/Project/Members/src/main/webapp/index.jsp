<%--
  Created by IntelliJ IDEA.
  User: CL
  Date: 2023/4/26
  Time: 16:39
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"  %>
<html>
<head>
    <title>Title</title>
    <style>
        table{
            border: 1px solid black;
            border-collapse: collapse;
            padding: 0;
            align-items: center;
        }
        tr{
            height: 30px;
        }
        tr:first-child{
            font-weight: 600;
        }
        td{
            border: 1px solid black;
            width: auto;
            height: 20px;
            text-align: center;
            padding: 5px 10px;
        }
        a{
            text-decoration: none;
        }
    </style>
</head>
<body>
<table >
    <tr>
        <td>id</td>
        <td>memberNo</td>
        <td>realName</td>
        <td>tel</td>
        <td>identityId</td>
        <td colspan="3">操作</td>
    </tr>
    <c:forEach items="${list}" var="s">
        <tr>
            <td>${s.id}</td>
            <td>${s.memberNo}</td>
            <td>${s.realName}</td>
            <td>${s.tel}</td>
            <td>${s.identityId}</td>
            <td><a href="${pageContext.request.contextPath}/del?id=${s.id}">删除</a></td>
            <td><a href="${pageContext.request.contextPath}/getOnce?id=${s.id}">修改</a></td>
            <td><a href="${pageContext.request.contextPath}/add">添加</a></td>
        </tr>
    </c:forEach>
</table>
</body>
</html>

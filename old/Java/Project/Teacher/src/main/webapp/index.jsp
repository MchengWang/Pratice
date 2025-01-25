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
            border: 2px solid black;
            border-collapse: collapse;
            padding: 0;
            align-items: center;
        }
        tr{
            height: 40px;
        }
        tr:first-child{
            font-weight: 400;
        }
        td{
            border: 1px solid black;
            width: auto;
            height: 20px;
            text-align: center;
            padding: 8px 15px;
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
        <td>teacherNo</td>
        <td>teacherName</td>
        <td>tel</td>
        <td>email</td>
        <td colspan="3">权限</td>
    </tr>
    <c:forEach items="${list}" var="teacher">
        <tr>
            <td>${teacher.id}</td>
            <td>${teacher.teacherNo}</td>
            <td>${teacher.teacherName}</td>
            <td>${teacher.tel}</td>
            <td>${teacher.email}</td>
            <td><a href="${pageContext.request.contextPath}/delTeacher?id=${teacher.id}">删除</a></td>
            <td><a href="${pageContext.request.contextPath}/getTeacher?id=${teacher.id}">修改</a></td>
            <td><a href="${pageContext.request.contextPath}/add">添加</a></td>
        </tr>
    </c:forEach>
</table>
</body>
</html>

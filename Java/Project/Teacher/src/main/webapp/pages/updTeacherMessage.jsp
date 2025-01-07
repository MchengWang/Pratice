<%--
  Created by IntelliJ IDEA.
  User: CL
  Date: 2023/4/26
  Time: 20:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
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
    td{
      border: 1px solid black;
      width: auto;
      height: 20px;
      text-align: center;
      padding: 5px 10px;
    }
  </style>
</head>
<body>
<form action="${pageContext.request.contextPath}/updateTeacher">
  <table>
    <tr style="display: none">
      <td><input type="hidden" name="id" value="${one.id}"></td>
    </tr>
    <tr>
      <td><label>teacherNo:</label></td>
      <td><input type="text" name="teacherNo" value="${one.teacherNo}"></td>
    </tr>
    <tr>
      <td><label>teacherName:</label></td>
      <td><input type="text" name="teacherName" value="${one.teacherName}"></td>
    </tr>
    <tr>
      <td><label>tel:</label></td>
      <td><input type="text" name="tel" value="${one.tel}"></td>
    </tr>
    <tr>
      <td><label>email:</label></td>
      <td><input type="text" name="email" value="${one.email}"></td>
    </tr>
    <tr>
      <td class="last" colspan="2"><input type="submit"></td>
    </tr>
  </table>
</form>
</body>
</html>

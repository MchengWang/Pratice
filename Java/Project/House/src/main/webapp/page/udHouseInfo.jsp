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
    <title>update</title>
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
<form action="${pageContext.request.contextPath}/update">
  <table>
    <tr style="display: none">
      <td><input type="hidden" name="id" value="${once.id}"></td>
    </tr>
    <tr>
      <td><label>householdNo:</label></td>
      <td><input type="text" name="householdNo" value="${once.householdNo}"></td>
    </tr>
    <tr>
      <td><label>householdName:</label></td>
      <td><input type="text" name="householdName" value="${once.householdName}"></td>
    </tr>
    <tr>
      <td><label>tel:</label></td>
      <td><input type="text" name="tel" value="${once.tel}"></td>
    </tr>
    <tr>
      <td><label>location:</label></td>
      <td><input type="text" name="location" value="${once.location}"></td>
    </tr>
    <tr>
      <td class="last" colspan="2"><input type="submit"></td>
    </tr>
  </table>
</form>
</body>
</html>
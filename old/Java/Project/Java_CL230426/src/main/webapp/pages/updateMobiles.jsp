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
<form action="${pageContext.request.contextPath}/update" method="post">
  <table>
    <tr style="display: none">
      <td><input type="hidden" name="id" value="${once.id}"></td>
    </tr>
    <tr>
      <td><label>phoneNo:</label></td>
      <td><input type="text" name="phoneNo" value="${once.phoneNo}"></td>
    </tr>
    <tr>
      <td><label>ownerName:</label></td>
      <td><input type="text" name="ownerName" value="${once.ownerName}"></td>
    </tr>
    <tr>
      <td><label>color:</label></td>
      <td><input type="text" name="color" value="${once.color}"></td>
    </tr>
    <tr>
      <td><label>brand:</label></td>
      <td><input type="text" name="brand" value="${once.brand}"></td>
    </tr>
    <tr>
      <td class="last" colspan="2"><input type="submit"></td>
    </tr>
  </table>
</form>
</body>
</html>

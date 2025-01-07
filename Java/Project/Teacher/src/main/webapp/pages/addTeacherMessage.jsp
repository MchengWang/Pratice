<%--
  Created by IntelliJ IDEA.
  User: CL
  Date: 2023/4/26
  Time: 19:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
  <style>
    .last{
      text-align:center;
      vertical-align:middle;
    }
  </style>
</head>
<body>
<form action="${pageContext.request.contextPath}/insertMessage">
  <table>
    <tr>
      <td><label>teacherNo:</label></td>
      <td><input type="text" name="teacherNo"></td>
    </tr>
    <tr>
      <td><label>teacherName:</label></td>
      <td><input type="text" name="teacherName"></td>
    </tr>
    <tr>
      <td><label>tel:</label></td>
      <td><input type="text" name="tel"></td>
    </tr>
    <tr>
      <td><label>email:</label></td>
      <td><input type="text" name="email"></td>
    </tr>
    <tr>
      <td class="last"><input type="submit"></td>
      <td class="last"><input type="reset"></td>
    </tr>
  </table>
</form>
</body>
</html>

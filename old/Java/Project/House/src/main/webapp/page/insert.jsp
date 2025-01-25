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
    <title>insert</title>
  <style>
    .last{
      text-align:center;
      vertical-align:middle;
    }
  </style>
</head>
<body>
<form action="${pageContext.request.contextPath}/insert">
  <table>
    <tr>
      <td><label>householdNo:</label></td>
      <td><input type="text" name="householdNo"></td>
    </tr>
    <tr>
      <td><label>householdName:</label></td>
      <td><input type="text" name="householdName"></td>
    </tr>
    <tr>
      <td><label>tel:</label></td>
      <td><input type="text" name="tel"></td>
    </tr>
    <tr>
      <td><label>location:</label></td>
      <td><input type="text" name="location"></td>
    </tr>
    <tr>
      <td class="last" colspan="2"><input type="submit"></td>
    </tr>
  </table>
</form>
</body>
</html>

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
<form action="${pageContext.request.contextPath}/insert" method="post">
  <table>
    <tr>
      <td><label>phoneNo:</label></td>
      <td><input type="text" name="phoneNo"></td>
    </tr>
    <tr>
      <td><label>ownerName:</label></td>
      <td><input type="text" name="ownerName"></td>
    </tr>
    <tr>
      <td><label>color:</label></td>
      <td><input type="text" name="color"></td>
    </tr>
    <tr>
      <td><label>brand:</label></td>
      <td><input type="text" name="brand"></td>
    </tr>
    <tr>
      <td class="last"><input type="submit"></td>
      <td class="last"><input type="reset"></td>
    </tr>
  </table>
</form>
</body>
</html>

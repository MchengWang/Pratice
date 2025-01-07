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
<form action="${pageContext.request.contextPath}/insert">
  <table>
    <tr>
      <td><label>memberNo:</label></td>
      <td><input type="text" name="memberNo"></td>
    </tr>
    <tr>
      <td><label>realName:</label></td>
      <td><input type="text" name="realName"></td>
    </tr>
    <tr>
      <td><label>tel:</label></td>
      <td><input type="text" name="tel"></td>
    </tr>
    <tr>
      <td><label>identityId:</label></td>
      <td><input type="text" name="identityId"></td>
    </tr>
    <tr>
      <td class="last"><input type="submit"></td>
      <td class="last"><input type="reset"></td>
    </tr>
  </table>
</form>
</body>
</html>

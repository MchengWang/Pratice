<%@ page language="java" pageEncoding="UTF-8"%>
    <%
    	//当前页面只做servlet的处理
    	//获取投票的内容  一共几张票，每一个分别是多少张票
    	String food = request.getParameter("food");
    	//接下来统计每一个分别投了多少次
    	
    	if(food.equals("bzf")){
    		//如果有人投过，则自己再增加1，如果没人投过，则初始化，并设置初始值为1
    		Integer bzfCount = (Integer)application.getAttribute("bzfCount");
    		if(bzfCount!=null){
    			//有值，已经有人投过了，累加
    			application.setAttribute("bzfCount", bzfCount+1);
    		}else{
    			//如果没人投过，则初始化，并设置初始值为1
    			application.setAttribute("bzfCount", 1 );
    		}
    	}else if(food.equals("hsr")){
    		//如果有人投过，则自己再增加1，如果没人投过，则初始化，并设置初始值为1
    		Integer hsrCount = (Integer)application.getAttribute("hsrCount");
    		if(hsrCount!=null){
    			//有值，已经有人投过了，累加
    			application.setAttribute("hsrCount", hsrCount+1);
    		}else{
    			//如果没人投过，则初始化，并设置初始值为1
    			application.setAttribute("hsrCount", 1 );
    		}
    	}else if(food.equals("tcpg")){
    		//如果有人投过，则自己再增加1，如果没人投过，则初始化，并设置初始值为1
    		Integer tcpgCount = (Integer)application.getAttribute("tcpgCount");
    		if(tcpgCount!=null){
    			//有值，已经有人投过了，累加
    			application.setAttribute("tcpgCount", tcpgCount+1);
    		}else{
    			//如果没人投过，则初始化，并设置初始值为1
    			application.setAttribute("tcpgCount", 1 );
    		}
    	}
    	//最后去 结果展示页面
    	response.sendRedirect("voteShow.jsp");
    	
    %>
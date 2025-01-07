package Summarize.JavaWeb.Servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;


/**
 * 快速入门：
 *  1.创建JavaEE项目
 *  2.定义一个类，实现Servlet接口
 *      public class ServletDemo implements Servlet
 *  3.实现接口中的抽象方法
 *  4.配置Servlet
 *      在web.xml文件中配置
 *      <!--配置Servlet-->
 *      <servlet>
 *         <servlet-name>ServletDemo</servlet-name>
 *         <servlet-class>文件的包路径</servlet-class>
 *     </servlet>
 *
 *     <servlet-mapping>
 *         <servlet-name>ServletDemo</servlet-name>
 *         <url-pattern>/servletDemo</url-pattern>
 *     </servlet-mapping>
 * 执行原理：
 *  1.当服务器接收到客户端的请求后，会解析请求URL路径，获取访问的Servlet的资源路径
 *  2.查找Web。xml文件，是否存在对应<url-pattern> 标签内容
 *  3.如果存在，则找到对应的<Servlet-class>全类名
 *  4.tomcat会将字节码文件加载进内存，并且创建其对象
 *  5.调用其方法
 * @author GoodMe
 */
public class ServletDemo extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    /*Servlet中的生命周期方法是：
    *   1.被创建，执行init方法，只执行一次
    *       Servlet什么时候被创建？
    *           默认情况：第一次被访问时，Servlet被创建
    *           可以配置执行Servlet的创建时机
    *               在<Servlet>标签下配置
    *                   1.第一次被访问时创建
    *                       <load-on-startup>的值为负数
    *                   2.在服务器启动后创建
    *                       <load-on-startup>的值为0或正整数
    *       Servlet的init方法，只执行一次，说明一个Servlet的内存中只存在一个对象，Servlet是单例的
    *       多个用户同时访问时，可能存在线程安全问题。
    *       解决：尽量不要在Servlet中定义成员变量，即使定义了成员变量，也不是对修改值
    *   2.提供服务执行：Service（）方法，执行多次
    *       每次访问Servlet时，service（）方法都会被调用一次
    *   3.被销毁:执行destory方法，只执行一次。
    *       servlet：被销毁时执行。服务器关闭时，servlet被销毁，只有服务器正常关闭时，才会执行destory方法
    *       destory方法在servlet被销毁之后执行，一般用于释放资源*/


    /*IDEA与tomcat的相关配置
    *   1.IDEA会为每一个tomcat部署的项目单独建立一份配置文件
    *       查看控制台的log： vsing CATALINA_BASE
    *       “D:\Progrem File”
    *   2.工作空间项目和tomcat的部署的web项目
    *       tomcat真正访问的是“tomcat部署的项目”，“tomcat部署的项目”对应着“工作空间项目”的web目录下的所有资源
    *       WEB-INF 目录下的资源不能被浏览器直接访问
    *   3.断点测试，使用小虫子启动debug启动*/
}

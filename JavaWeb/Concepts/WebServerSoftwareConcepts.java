package Summarize.JavaWeb.Concepts;

public class WebServerSoftwareConcepts {

    /*Web服务器软件
    *   服务器:安装了服务器软件的计算机
    *   服务器软件：接受用户的请求，处理请求，做出响应
    *   Web服务器软件：接受用户的请求，处理请求，做出响应
    *       在Web服务器软件中，可以部署Web项目，让用户通过浏览器来访问这些项目。
    *   Web容器*/

    /*常见的java相关的Web服务器软件
    *   1.WebLogic：Oracle公司，大型的JavaEE服务器，支持所有的JavaEE规范，收费
    *   2.WebSpher：IBM公司，大型的JavaEE服务器，支持所有JavaEE规范，收费的。
    *   3.JBOSS：JBOSS公司，大型的JavaEE服务器，支持所有的JavaEE规范，收费的
    *   4.Tomcat：Apache基金组织，中小型的JavaEE服务器，仅仅支持少量的JavaEE规范，Servlet/jsp,开源的，免费的*/

    /*Tomcat：Web服务器软件
    *   1.下载：https://tomcat.apache.org/
    *   2.安装：解压压缩包即可，
    *       注意：安装目录建议不要有中文和空格
    *   3.卸载：删除目录就行了
    *   4.启动：
    *       bin/StartUp.bat 双击文件即可
    *       访问：浏览器输入http://127.0.0.1:8080/
    *                       http://127.0.0.1:8080/
    *       可能遇到的问题
    *           1.黑窗口一闪而过:
    *               原因：没有正确配置JAVA_HOME环境变量
    *               解决方法：正确配置JAVA_HOME环境变量
    *           2.启动报错：
    *               1.暴力：找到占用的端口号，并且找到相应的进程，杀死进程 netstat -ano
    *               2.温柔：修改自身的端口号：
    *                   Conf/Server.xml
    *                   <Comector port="8088" Protocal="http11.1"
    *                   ConnectionTimeOut="20000"
    *                   redirectPort="8445"/>
    *               一般将Tomcat的默认端口号修改为80，80端口号是http协议的默认端口号
    *               好处：在访问时。就不会再输入端口号。
    *   5.关闭
    *       1.正常关闭：
    *           bin/Shutdown.bat
    *           Ctrl + c
    *       2.强制关闭
    *           点击启动窗口的X
    *   6.配置：
    *       部署项目的方法
    *           1.直接将项目放在Webapps目录下，即可
    *               1. /hello 项目的访问路径 -> 虚拟目录
    *               2. 简化部署，将项目打包成为一个war包，再将war包放置到Webapps目录下，
    *                   war包会自动解压缩。
    *           2.配置Conf/Server.xml文件
    *               在<Host>标签中配置
    *               <Context docBase="D:\hello" path = "/here" />
    *                   docBase:项目存放的路径
    *                   path：虚拟路径
    *           3.在Conf/CataLina/Localhost创建任意名称的xml文件，在文件中编写<Context docBase = "" Path = "">
                    虚拟目录，xml文件的名称*/

    /*静态项目和动态项目：
    *   目录结构：
    *       java语言动态项目的目录结构
    *           项目的根目录
    *               WEB-INF目录
    *                   web.xml:web项目的核心配置文件
    *                   Classes目录：放置字节码文件的目录
    *                   lib目录：放置依赖的jar包
    * 将Tomcat集成到IDEA中，并且创建JavaEE的项目，部署项目*/
}

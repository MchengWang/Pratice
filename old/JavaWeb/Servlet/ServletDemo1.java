package Summarize.JavaWeb.Servlet;

import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import java.lang.annotation.*;

/**
 * Servlet3.0
 *         好处：支持注解配置，可以不需要web.xml了
 *         步骤：
 *             1.创建JavaEE项目，选择servlet的版本3.0以上，可以不创建Web.xml
 *             2.定义一个类，实现Servlet接口、
 *             3.重写方法
 *             4.在类上使用@WebServlet注解，进行配置
 *
 * @author GoodMe
 */

@WebServlet("ServletDemo")
@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.TYPE})
@Documented
public @interface ServletDemo1 {
    String name() default ""; // 相当于<servlet-name>
    String[] value() default {}; // 代表urlRatterns()属性配置
    String[] urlPatterns() default {}; // 相当于<url-pattern>
    int loadonstartup() default -1; // 相当于<load-on-startup>
    WebInitParam[] initParams() default {};
    boolean asyncSupported() default false;
    String smallIcon() default "";
    String largeIcon() default "";
    String descriptIcon() default "";
    String displayIcon() default "";
}

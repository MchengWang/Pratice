import com.chxd.pojo.User;
import com.chxd.service.UserService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class testZG {

    @Test
    public void Testzzz()
    {

        ApplicationContext context=
                new ClassPathXmlApplicationContext("spring.xml");

        UserService userService=(UserService)   context.getBean("userService");

        User user=  new User();
        user.setUsername("张三");
        user.setAge(18);
        user.setGender("男");
        user.setPassword("123456");


        int ret= userService.addUser(user);
        System.out.println(" 添加 result="+ ret);

    }
}

import com.chxd.pojo.User;
import com.chxd.service.UserService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestAop {

    @Test
    public void AopTest()
    {
        ApplicationContext context=
                new ClassPathXmlApplicationContext("spring.xml");

       UserService userService=(UserService) context.getBean("userService");

       User user= new User();
       user.setUsername("张丹");
       user.setAge(18);
       userService.addUser(user);
                

    }
    
}

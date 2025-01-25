import com.weishuning.printer.Printer;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestPrinter {

    @Test
    public void Testppp()
    {
        ApplicationContext context =
                new ClassPathXmlApplicationContext("spring.xml");

        Printer myPrinter= (Printer) context.getBean("myPrinter");
        String cd = "sddugyfdsiuhvjksdbfvjkshgkjsnvcknmxbnvkndbvgkjsddugyfdsiuhvjksdbfv" +
                "jkshgkjsnvcknmxbnvkndbvgkjsddugyfdsiuhvjksdbfvjkshgkjsnvcknmxbnvkndbvgkj" +
                "sddugyfdsiuhvjksdbfvjkshgkjsnvcknmxbnvkndbvgkj";
        myPrinter.print(cd);
    }
}

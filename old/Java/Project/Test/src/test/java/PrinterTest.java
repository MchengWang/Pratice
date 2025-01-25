import com.shilinyu.printer.Printer;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class PrinterTest {
    @Test
    public void test(){
        ApplicationContext context = new ClassPathXmlApplicationContext("ApplicationContext.xml");
        Printer printer = (Printer) context.getBean("printer");
        String content ="vdcgfhghhfvgfvghhhjjkkkkkkkhgfdssswaadrtrggykjhg";
        printer.print(content);
        ((ConfigurableApplicationContext) context).close();
        //System.out.println(content);
    }
}

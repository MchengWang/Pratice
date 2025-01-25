import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestPring {



    @Test
    public void TestDog() {

        ApplicationContext context =
                new ClassPathXmlApplicationContext("spring.xml");
       IPet pet= (IPet) context.getBean("dog");

       pet.eat();
       pet.sleep();

//        Dog dog = new Dog();
//        dog.setColor("红色");
//        dog.setName("小花");
//        dog.eat();
//        dog.sleep();


    }



}

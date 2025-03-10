package cn.itcast.mq.spring;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.amqp.rabbit.core.RabbitTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.HashMap;
import java.util.Map;

@RunWith(SpringRunner.class)
@SpringBootTest
public class SpringAmqpTest {

    /*什么是AMQP？
    *   应用间消息通信的一种协议，与语言和平台无关
    * */

    @Autowired
    private RabbitTemplate rabbitTemplate;

    @Test
    public void testSendMessage2SimpleQueue(){
        /*SpringAMQP如何发送消息？
         *   引入amqp的starter依赖
         *   配置RabbitMQ地址
         *   利用RabbitTemplate的convertAndSend方法*/
        String queueName = "simple.queue";
        String message = "hello , spring amqp !";
        rabbitTemplate.convertAndSend(queueName , message);
    }

    @Test
    public void testSendMessage2WorkQueue() throws InterruptedException {
        String queueName = "simple.queue";
        String message = "hello , message__ ";
        for (int i = 1; i <= 50; i++) {
            rabbitTemplate.convertAndSend(queueName , message + i);
            Thread.sleep(20);
        }
    }

    @Test
    public void testSendFanoutExchange() {
        /*Fanout Exchange会接收到的消息路由到每一个跟其绑定的queue
        * 步骤一：在consumer服务声明Exchange、Queue、Binding
        * 步骤二：在consumer服务声明两个消费者
        * 步骤三：在publisher服务发送消息到FanoutExchange*/
        // 交换机名称
        String exchangeName = "itcast.fanout";
        // 消息
        String message = "hello , every one !";
        // 发送消息
        rabbitTemplate.convertAndSend(exchangeName , "" , message);
    }

    @Test
    public void testSendDirectExchange() {
        // 交换机名称
        String exchangeName = "itcast.direct";
        // 消息
        String message = "hello , red!";
        // 发送消息
        rabbitTemplate.convertAndSend(exchangeName , "red" , message);
    }

    @Test
    public void testSendTopicExchange() {
        // 交换机名称
        String exchangeName = "itcast.topic";
        // 消息
        String message = "王梦成年轻有为，22岁成为世界首富!";
        // 发送消息
        rabbitTemplate.convertAndSend(exchangeName , "china.news" , message);
    }

    @Test
    public void testSendObjectQueue() {
        Map<String , Object> msg = new HashMap<>();
        msg.put("name" , "刘亦菲");
        msg.put("age" , 18);
        rabbitTemplate.convertAndSend("object.queue" , msg);
    }
}

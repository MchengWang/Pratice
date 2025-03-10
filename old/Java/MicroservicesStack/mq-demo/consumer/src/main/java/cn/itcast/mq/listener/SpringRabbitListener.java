package cn.itcast.mq.listener;

import org.springframework.amqp.core.ExchangeTypes;
import org.springframework.amqp.rabbit.annotation.Exchange;
import org.springframework.amqp.rabbit.annotation.Queue;
import org.springframework.amqp.rabbit.annotation.QueueBinding;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

import java.time.LocalTime;
import java.util.Map;

@Component
public class SpringRabbitListener {

//    @RabbitListener(queues = "simple.queue")
//    public void listenSimpleQueue(String message){
//        System.out.println("消费者收到simple.queue的消息：【" + message + "】");
//    }

    @RabbitListener(queues = "simple.queue")
    public void listenWorkQueue1(String message) throws InterruptedException {
        System.out.println("消费者1收到消息：【" + message + "】" + LocalTime.now());
        Thread.sleep(20);
    }

    @RabbitListener(queues = "simple.queue")
    public void listenWorkQueue2(String message) throws InterruptedException {
        System.err.println("消费者2.........收到消息：【" + message + "】" + LocalTime.now());
        Thread.sleep(200);
    }

    @RabbitListener(queues = "fanout.queue1")
    public void listenFanoutQueue1(String message){
        System.out.println("消费者收到fanout.queue1的消息：【" + message + "】");
    }

    @RabbitListener(queues = "fanout.queue2")
    public void listenFanoutQueue2(String message){
        System.out.println("消费者收到fanout.queue2的消息：【" + message + "】");
    }

    @RabbitListener(bindings = @QueueBinding(
            /*Direct Exchange会将接收到的消息根据规则路由到指定的Queue，因此称为路由模式（routes）
            *   每一个Queue都与Exchange设置一个BindingKey
            *   发布者发送消息时，指定消息的RoutingKey
            *   Exchange将消息路由到BingingKey与消息RoutingKey一致的队列*/
            value = @Queue("direct.queue1") ,
            exchange = @Exchange(value = "itcast.direct" , type = ExchangeTypes.DIRECT) ,
            key = {"red" , "blue"}
    ))
    public void listenDirectQueue1(String message){
        /*实现direct交换机步骤如下：
        *   1、利用RabbitListener声明Exchange、Queue、RoutingKey
        *   2、在consumer服务中，编写两个消费者方法，分别监听direct.queue1和direct.queue2
        *   3、在publisher中编写测试方法，想itcast.direct发送消息*/
        System.out.println("消费者收到direct.queue1的消息：【" + message + "】");
    }

    @RabbitListener(bindings = @QueueBinding(
            value = @Queue("direct.queue2") ,
            exchange = @Exchange(value = "itcast.direct" , type = ExchangeTypes.DIRECT) ,
            key = {"red" , "yellow"}
    ))
    public void listenDirectQueue2(String message){
        /*Direct交换机与Fanout交换机的差异
        *   Fanout交换机将消息路由给每一个与之绑定的队列
        *   Direct交换机根据RoutingKey判断路由给哪个队列
        *   如果多个队列既有相同的RoutingKey，则与Fanout功能类似
        * 基于@RabbitListener注解声明队列和交换机有哪些常见注解
        *   @Queue
        *   @Exchange*/
        System.out.println("消费者收到direct.queue2的消息：【" + message + "】");
    }

    @RabbitListener(bindings = @QueueBinding(
            value = @Queue("topic.queue1") ,
            exchange = @Exchange(value = "itcast.topic" , type = ExchangeTypes.TOPIC) ,
            key = "china.#"
    ))
    public void listenTopicQueue1(String message){
        /*1、在consumer服务中，编写两个消费者方法，分别监听topic.queue1和topic.queue2
        * 2、并利用@RabbieListener声明Exchange、Queue、RoutingKey*/
        System.out.println("消费者收到topic.queue1的消息：【" + message + "】");
    }

    @RabbitListener(bindings = @QueueBinding(
            value = @Queue("topic.queue2") ,
            exchange = @Exchange(value = "itcast.topic" , type = ExchangeTypes.TOPIC)
            /*TopicExchange与DirectExchange类似，区别于routingKey必须是多个单词的列表，并且以.分割。
            * Queue与Exchange指定BindingKey时可以使用通配符
            *   #：代指0个或多个单词
            *   *：代指一个单词*/,
            key = "#.news"
    ))
    public void listenTopicQueue2(String message){
        System.out.println("消费者收到topic.queue2的消息：【" + message + "】");
    }


    /**消息转换器
     *   引入依赖jackson-databind
     *   在服务中声明MessageConverter
     *   然后定义一个消费者，监听object.queue队列并消费信息*/
    @RabbitListener(queues = "object.queue")
    public void listenObjectQueue(Map<String , Object> msg){
        System.out.println("接收到object.queue的消息：" + msg);
    }
}

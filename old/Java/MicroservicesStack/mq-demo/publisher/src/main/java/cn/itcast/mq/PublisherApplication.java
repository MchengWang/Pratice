package cn.itcast.mq;

import org.springframework.amqp.support.converter.Jackson2JsonMessageConverter;
import org.springframework.amqp.support.converter.MessageConverter;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class PublisherApplication {
    public static void main(String[] args) {
        SpringApplication.run(PublisherApplication.class);
    }


    /*消息转换器
    *   引入依赖jackson-databind
    *   在服务中声明MessageConverter*/
    @Bean
    public MessageConverter messageConverter(){
        /*SpringAMQP中消息的序列化和反序列化是如何实现的？
        *   利用MessageConverter实现的，默认是JDK的序列化
        *   注意发送方与接收方必须使用相同的MessageConverter*/
        return new Jackson2JsonMessageConverter();
    }
}

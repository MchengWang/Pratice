package cn.itcast.mq.config;

import org.springframework.amqp.core.Binding;
import org.springframework.amqp.core.BindingBuilder;
import org.springframework.amqp.core.FanoutExchange;
import org.springframework.amqp.core.Queue;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class FanoutConfig {

    /*交换机的作用是什么
    *   接收publisher发送的消息
    *   将消息按照规则路由到与之绑定的队列
    *   不能缓存消息，路由失败、消息丢失
    *   FanoutExchange的会将消息路由到每个绑定的队列
    * 声明队列、交换机、绑定关系的Bean是什么
    *   Queue
    *   Exchange
    *   Binding*/


    // 声明FanoutExchange交换价
    @Bean
    public FanoutExchange fanoutExchange(){
        return new FanoutExchange("itcast.fanout");
    }

    // 声明第一个队列
    @Bean
    public Queue fanoutQueue1(){
        return new Queue("fanout.queue1");
    }

    // 绑定队列1和交换机
    @Bean
    public Binding bindingQueue1(Queue fanoutQueue1 , FanoutExchange fanoutExchange){
        return BindingBuilder.bind(fanoutQueue1).to(fanoutExchange);
    }

    // 声明第二个队列
    @Bean
    public Queue fanoutQueue2(){
        return new Queue("fanout.queue2");
    }

    // 绑定队列2和交换机
    @Bean
    public Binding bindingQueue2(Queue fanoutQueue2 , FanoutExchange fanoutExchange){
        return BindingBuilder.bind(fanoutQueue2).to(fanoutExchange);
    }

    @Bean
    public Queue objectQueue(){
        return new Queue("object.queue");
    }
}


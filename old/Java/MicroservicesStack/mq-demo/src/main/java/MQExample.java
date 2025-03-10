public class MQExample {
    /*同步调用的优点：
    *   时效性较强，可以立即得到结果
    * 同步调用的问题：
    *   耦合度高
    *   性能和吞吐能力下降
    *   有额外的资源消耗
    *   有级联失败问题*/

    /*异步通信的优点：
    *   耦合度低
    *   吞吐量提升
    *   故障隔离
    *   流量削锋
    * 异步通信的缺点：
    *   依赖于Broker的可靠性，安全性。吞吐能力
    *   架构复杂了，业务没有明显的流程线，不好追踪管理*/

    /*MQ(MessageQueue)，中文是消息队列，字面来看就是存放消息的队列。也就是事件驱动架构中的Broker
    *               RabbitMQ        ActiveMQ              RocketMQ        kafaka
    * 公司/社区        Rabbit          Apache                阿里           Apache
    * 开发语言         Erlang          Java                 Java           Scala&Java
    * 协议支持       AMQP、XMPP、      OpenWire,STOMP       自定义协议         自定义协议
    *              SMTP、STOMP       REST、XMPP、AMQP
    * 可用性           高               一般                  高               高
    * 单机吞吐量       一般               差                   高              非常高
    * 消息延迟        微秒级             毫秒级                毫秒级           毫秒以内
    * 消息可靠性        高                一般                  高             一般*/
}

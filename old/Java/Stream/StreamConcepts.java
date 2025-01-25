package Summarize.Stream;

public class StreamConcepts {
    /*Stream流 是代码更加优雅
    *   Stream是JDK1.8之后出现的，关注的是做什么，而不是怎么做
    * filter过程 forEach消费循环*/

   /* 示例：
    filter(name -> name.length == 3); // 过滤的字长为3
    forEach(name -> System.out.println(name)); // 遍历name*/

    /*流式思想概述 暂时忘记IO流固有印象
    * 类似于工厂的流水线
    * filter map skip 都是对函数的模型进行操作，集合中的元素没有真正被处理，只有当最终方法count执行的时候，整个模型才会按照指定策略
    * 进行操作。这得益于lambda延迟执行特性*/

    /*Stream（流）是一个来自数据源的元素队列
    *   1.元素特定类型的对象，形成一个队列，Java中的Stream不会存储元素，而是按需计算
    *   2.数据源流的来源，可以是集合，数组等和以前Collection操作不同，Stream操作还有两个基本的特征
    *   3.Pipelining：中间操作都会返回流对象本身，这样多个操作都可以串联成一个管道，如同流域风格（Fluent Style）。
    * 这样可以对操作进行优化，比如延迟执行（laziness）和短路（short-circuiting）。
    *   4.内部迭代：以前对集合遍历都是通过Itrator或者增强for的方式吗，显式的在集合外部进行迭代，这叫做外部迭代，Stream提供了内部迭代的方式，
    * 流可以直接调用遍历方法。*/

    /*当时用一个流的时候，通常包括三个基本步骤：
    *   1、获取一个数据源（Source） 原有Stream对象不变，返回一个新Stream对象，（可以多次转换）
    *   2、数据转换  这就允许对其操作可以像链条一样排列，变成一个管道。
    *   3、执行操作，获取结果*/

    /*获取流：
    *   java.util.stream.Stream<T> 是Java8新加入的最常用的接口（并不是函数式接口）
    * 常见获取流的方式：
    *   所有的Collection集合对可以通过Stream默认方法获取流
    *   Stream接口中的静态方法of可以获取数组对应的流
    * 数组：static <T> Stream<T> of(T... values)  返回其元素是指定值的顺序排序流。
    *   参数：是一个可变参数，那么我们就可以传递数组
    * Collection：default Stream<E> stream()  */

    /*集合转换案例
     *   list，set可以直接转换
     * map通过keyset，values，entryset将map集合转化为单列集合，后转化为Stream流对象
     * 数组转换：Stream.of() 括号中可以直接放元素
     *                       也可以放数组名称*/

    /*常用方法：
    * 方法分为两种
    *   延迟方法：返回值类型认识Stream接口自身类型的方法，因此支持链式调用（除了终结方法外其他方法均为延迟方法）
    *   终结方法：返回值类型不再是Stream接口自身类型的方法，因此不再支持类似StringBuilder那样的链式调用。本小节中
    * 终结方法包括count和forEac方法
    * nums.stream()[创建Stream].filter(num -> num != null)[转换Stream].count()[聚合]
    * 统一处理：forEach和for循环中的for-each昵称不同
    *   void forEach(Consumer<? super T> action)
    * 简单记：forEach方法用来遍历流中的数据，终结方法，使用之后，不能继续调用Stream流中的其他方法
    * 过滤：filter 将一个流转换另一个子集流
    *   Stream<T> filter(Predicate<? super T> predicate)
    * Stream特点：只能使用一次，属于管道流，第一个Stream流调用方法完毕，数据就会流向下一个Stream上，而第一个Stream流已经使用完毕，就会关闭了，
    * 所以第一个Stream流就不能再调用方法了。
    * 常用方法map（映射）：如果将流中元素映射到另一个立足红，可以使用map方法，（延迟方法）
    * <R> Stream<R> map(Function<? super T,? extends R> mapper)  即转换数据类型
    * 统计个数：count（终结方法） 用于统计Stream元素的个数
    * long count()
    * 取用前几个 Stream<T> limit(long maxSize)
    * 跳过前几个 Stream<T> skip(long n)
    * 如果当前长度大于n，则跳过前n个：否则将会得到一个长度为0的空流
    * 组合 concat 如果两个流，希望合并成为一个流，那么可以使用Stream流中的静态方法Concat
    *   static <T> Stream<T> concat(Stream<? extends T> a, Stream<? extends T> b)
    * 这是一个静态方法与java.lang.String当中的concat方法是不同的*/

}

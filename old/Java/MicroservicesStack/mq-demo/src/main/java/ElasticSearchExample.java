public class ElasticSearchExample {

    /*Lucene是一个java语言的搜索引擎类库，时Apache公司的顶级项目，由DougCutting与1999年研发。官网地址：https://lucene.apache.org/
     * Lucene的优势：
     *  易扩展
     *  高性能（基于倒排索引）
     * Lucene的缺点
     *  只限于java语言开发
     *  学习曲线陡峭
     *  不支持水平扩展*/

    /*Elasticsearch
    *   2004年Shay Banon基于Lucene开发了Compass
    *   2010年Shay Banon重写了Compass，取名为Elasticsearch 官网地址：https://www.elastic.co/cn/
    *   目前最新版是：7.12.1
    *   相比于lucene，elasticsearch具备下列优势：
    *       支持分布式，可水平扩展
    *       提供RESTful接口，可被任何语言调用*/

    /*什么是elasticsearch
    * elasticsearch是一款非常强大的开源搜索引擎，可以帮助我们从海量数据中快速找到需要的内容
    * elasticsearch结合kibana、logstash、Beats，也就是elastic stack （ELK）。被广泛应用在日志数据分析，实时监控等领域。
    * elasticsearch时elastic stack的核心，负责存储，搜索，分析数据
    * */

    /*elasticsearch与mysql的关系
    *   elasticsearch是面向文档存储的，可以是数据库中的一条商品数据，一个订单信息。文档数据会被序列化为json格式后存储在elasticsearch中。
    *   mysql：擅长事务类型操作，可以确保数据的安全和一致性
    *   Elasticsearch：擅长海量数据的搜索、分析、计算*/

    /*文档：一条数据就是一个文档，es中是json格式
    * 字段：json文档中的字段
    * 索引：同类型文档的集合
    * 映射：索引中文档的约束，比如字段名称、类型*/

    /*什么是文档和词条？
    *   每一条数据就是一个文档
    *   对文档中的内容分词，得到的词语就是词条
    * 什么是正向索引？
    *   基于文档id创建索引。查询词体哦啊是必须先找到文档，而后判断是否包含词条。
    * 什么是倒排索引？
    *   对文档内容分词，对词条创建索引，并记录词条所在文档的信息。查询时先根据词条查询到文档id，而后获取到文档*/

    /*分词器的作用是什么？
    *   创建倒排索引时对文档分词
    *   用户搜索时，对输入的内容分词
    * IK分词器有几种模式？
    *   ik_smart：智能切分，粗粒度
    *   ik_max_word：最细切分，细粒度
    * Ik分词器如何扩展词条？如何停用词条？
    *   利用config目录的IkAnalyzer.cfg.cml文件添加扩展词典和停用词典
    *   在词典中添加扩展词条或者停用词条*/

    /*Mysql     Elasticsearch       说明
    * Table         Index           索引（index），就是文档的集合，类似数据库的表（table）
    * Row         Document          文档（document），就是一条条的数据，类似数据库中的行（Row），文档都是JSON格式
    * Column       Field            字段（Field），也就是JSON文档中的字段，类似数据库中的列（Column）
    * Schema      Mapping           Mapping（映射）是索引中文档的约束，例如字段类型约束。类似数据库的表结构（Schema）
    * SQL           DSL             DSL是elasticsearch提供的JSON风格的请求语句，用来操作elasticsearch，实现CRUD*/
}

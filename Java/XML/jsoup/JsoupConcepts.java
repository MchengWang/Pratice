package Summarize.XML.jsoup;

/**
 * @author GoodMe
 * 对象的使用
 *  1.Jsoup：工具类，可以解析HTML或XML文档，返回Document
 *      parse：解析xml或HTML文档，返回Document
 *          parse(File in , String clarsetName):解析XML或HTML文件的
 *          parse(String html):解析HTML或XML的字符串
 *          parse(URL url , int timeoutMillis):通过网络路径获取指定的HTML或XML的文档对象
 *  2.Document文档对象，代表内存中的dom树
 *      获取元素对象
 *          getElementById（String id）：根据id属性值获取唯一的element对象
 *          getElementByTag（String tagName）：根据标签名获取元素对象集合
 *          getElementByAttribute（String key）：根据属性名称获取元素对象集合
 *          getElementByAttributeValue（String key , String value）：根据对应的属性名和属性值获取元素对象集合
 *  3.Elements：元素对象的集合，可以当作ArrayList<Element>来使用
 *  4.Element：元素对象：
 *      1.获取元素对象：方法跟2中一样
 *      2.获取属性值：
 *          String attr(String key)根据属性名称获取属性值
 *      3.获取文本信息“
 *          String text()：获取文本内容
 *          String html()：获取标签体中的所有内容（包括字标签的字符串内容）
 *  5.Node节点对象
 *      是Documeng和Element的父类
 */
public class JsoupConcepts {
}

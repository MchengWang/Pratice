package Summarize.IO;

import java.io.*;
import java.util.Properties;
import java.util.Set;

public class DemoIOProperties {
    /*类Properties表示一个持久的属性集，properties可保存在流中或从流中加载，属性列表中每个键值其对应值都是字符串
    properties extends Hashtable<k,v> implements Map<k,v>
    properties 是唯一一个和Io流相结合的集合
    可以使用properies集合中的方法store，吧集合中的临时数据，持久化写入硬盘中存储
    可以使用properies集合中的方法load，可以把硬盘中保存的文件（键值对），读取到集合中使用
    properies集合是一个双列集合，key和value默认都是字符串
    */
    public static void main(String[] args) throws IOException {
        /*使用properties集合存储数据，遍历取出properties集合中的数据
        properties集合有一些操作字符串的特有方法
        String	getProperty​(String key)搜索此属性列表中指定键的属性。
        Object	setProperty​(String key, String value)	调用 方法。Hashtableput
        Set<String>	stringPropertyNames()
        从此属性列表中返回一组不可修改的键，其中键及其对应值是字符串，如果尚未从主属性列表中找到同名键，则在默认属性列表中包括不同的键。
        相当于Map集合中的keyset方法*/
        //创建对象
        Properties prop = new Properties();
        //使用properties往集合中添加数据
        prop.setProperty("胡歌","180");
        prop.setProperty("王梦成","170");
        prop.setProperty("张守慧","170");
        //prop.put(1,true);
        //使用StringPropertyNames把properties集合中的键取出，存储到一个set集合中
        Set<String> names = prop.stringPropertyNames();
        //遍历set集合，取出properties集合中的每一个键
        for (String s : names) {
            //使用getproperty方法通过key取出value
            String s1 = prop.getProperty(s);
            System.out.println(s+ "" + s1);
        }

        /*properties集合中的方法store
        可以使用properties集合中的额方法store，把集合中的临时数据，持久化写入放到硬盘中存储
        void	store​(OutputStream out, String comments)	将此表中的此属性列表（键和元素对）以适合使用load（InputStream） 方法加载到表中的格式写入输出流。PropertiesProperties
        void	store​(Writer writer, String comments)	以适合使用 load（Reader）方法的格式将此表中的此属性列表（键和元素对）写入输出字符流。Properties
        参数：outputStream out：字节输出流，不能写入中文
             Writer writer：字符输出流，可以写中文
             String comments：注释，用来解释说明保存的文件是干什么用的
             不能使用中文，因为会产生乱码，默认是Unicode编码
             一般使用“”空字符串
        使用步骤
            1、创建properties集合对象，添加数据
            2、创建字节/字符输出流，对象构造方法中绑定要输出的目的地
            3、使用properties集合中的方法store，吧集合中的临时数据，持久化写入到硬盘中存储
            4、释放资源
       */
        //2、
        FileWriter fw = new FileWriter("C:\\Users\\GoodMe\\Desktop\\test.txt");
        FileOutputStream fos = new FileOutputStream("C:\\Users\\GoodMe\\Desktop\\test.txt");

        //3
        prop.put(fw,"save date");
        prop.put(fos , "");

        System.out.println(prop);
        fw.close();
        fos.close();

        /*properties中的方法load
          可以使用properties中的方法load，把硬盘中保存的文件（键值对），读取到集合中使用
          void	load​(InputStream inStream)	从输入字节流读取属性列表（键和元素对）。
          void	load​(Reader reader)	以简单的面向行的格式从输入字符流读取属性列表（键和元素对）
          参数：InputStream instream 字节输入流，不能读取含有中文的键值对
               Reader reader 字符输入流，能读取含有中文的键值对
        使用步骤
               1、创建properties集合对象
               2、使用properties集合对象中的方法load读取保存键值对的文件
               3、遍历properties集合
        注意：
           1、存储键值对的文件中，简直默认的连接符号可以使用=，空格（其他符号）
           2、存储键值对的文件中，可以使用并进行注释，被注释的键值对不会再被读取
           3、存储键值对的文件中，键与值都是字符串，不用再加引号*/
        //2、
        FileReader fr = new FileReader("C:\\Users\\GoodMe\\Desktop\\test.txt");
        prop.load(fr);

        //3
        Set<String> set = prop.stringPropertyNames();
        for (String s : set) {
            String s1 = prop.getProperty(s);
            System.out.println(s1+"="+s);
        }
    }
}

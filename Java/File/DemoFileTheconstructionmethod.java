package Summarize.File;

public class DemoFileTheconstructionmethod {
    /*File构造方法
    File​(File parent, String child)	从父抽象路径名和子路径名字符串创建新实例。File
    File​(String pathname)	通过将给定的路径名字符串转换为抽象路径名创建新实例。File
    File​(String parent, String child)	从父路径名字符串和子路径名字符串创建新实例。File

    File​(String pathname) 参数：
    String pathname 字符串路径名称
    路径是可以以文件结尾，也可以以文件夹结尾，可以是相对路径，也可以是相对路径
    路径可以是存在的，也可以是不存在的
    创建File对象：只是把字符串路径封装为File队形，不考虑路径的真假性

    File​(String parent, String child)参数：
    String parent：父路径 C:\\
    String child：子路径 a.txt
    好处：父路径子路径，可以单独书写，使用起来非常灵活，父路径和子路径都可以变化

    File​(File parent, String child)参数：
    File parent：父路径
    String child：子路径
    好处：父路径和子路径了可以单独书写，使用起来非常灵活，父路径和子路径都可以变化，父路径是
    File类型，可以使用Fil的方法对路径进行一些操作，在使用路径创建对象

    File获取功能的方法
    String	getName()	返回由此抽象路径名表示的文件或目录的名称。
    String	getPath()	将此抽象路径名转换为路径名字符串。、
    String	getAbsolutePath()	返回此抽象路径名的绝对路径名字符串。
    long	length()	返回此抽象路径名表示的文件长度。
    示例：getAbsolutePath() 五路路径是绝对还是相对的，getAbsolutePath返回的都是绝对路径
    getPath()是什么返回什么，无论相对/绝对
    getName()构造方法中传递的路径的结尾部分（文件/文件夹）的名称
    length()获取指定文件的大小，亿字节为单位，如果构造方法中路径不存在，length方法返回0，文件夹也无大小概念
    File中判断的方法
    boolean	exists()	测试此抽象路径名表示的文件或目录是否存在。
    boolean	isDirectory()	测试此抽象路径名表示的文件是否是目录。
    boolean	isFile()	测试此抽象路径名表示的文件是否为普通文件。
    注意：电脑的硬盘只有文件/文件夹，两个方法是互斥的
    这两个方法使用前提是，路径是必须存在的，否则都会返回false
    File类创建和删除功能
    boolean	createNewFile()	如果且仅在具有此名称的文件尚不存在时，以原子方式创建一个由此抽象路径名命名的新的空文件。
    创建文件的路径和名称在构造方法中给出的（构造方法的参数）
    返回值：布尔型
          true：文件不存在，创建文件返回true
          false:文件存在，不创建，返回false
    注意：（判断是否为文件及，不要被名称模糊，要看类型）
         1、此方法只能创建文件，不能创建文件夹
         2、创建文件的路径必须存在，否则会抛出异常
    createNewFile()抛出IOException，我们调用这个方法，就必须处理，要么throws要么try catch
    boolean	mkdir()	创建由此抽象路径名命名的目录。
    boolean	mkdirs()创建由此抽象路径名命名的目录，包括任何必要但不存在的父目录。
    创建文件夹的路径和名称在构造方法中给出（构造方法的参数）
    返回值：布尔值
         true：文件夹不存在，创建文件夹，返回true；
         false：文件夹存在，不创建，返回false；构造方法中欸出的路径不存在也返回false
    注意：
    1、此方法只能创建文件夹，不能创建文件
    boolean	delete()	删除此抽象路径名表示的文件或目录。
    此方法，可以删除构造方法中给定的文件/文件夹
    返回值：布尔值
         true：文件/文件夹删除成功，返回true
         false：文件夹中有内容，不会删除返回false，构造方法中路径不存在也返回false
    注意：delete方法是直接从硬盘上删除文件/文件夹，不走回收站，删除要谨慎
    目录的遍历
    String[]	list()	返回一个字符串数组，命名目录中由此抽象路径名表示的文件和目录。
    File[]	listFiles()	返回一个抽象路径名数组，这些参数表示由此抽象路径名表示的目录中的文件。
    注意：
        list方法和listFiles方法遍历的是构造方法中给出的目录
        如果构造方法给出的目录不存在，会抛出空指针异常
        如果构造方法中给出的路径不是一个目录，也会抛出空指针异常
      1、把获取的多个名称存储到一个String类型的数组中
      2、把获取文件/文件夹封装为File对象，多个File对象存储到File数组中*/
}

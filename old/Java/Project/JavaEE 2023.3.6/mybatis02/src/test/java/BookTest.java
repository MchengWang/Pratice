import com.jsj.dao.BookService;
import com.jsj.entries.Book;
import com.jsj.uitils.MybaitsFactory;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BookTest {



    @Test
    public  void TestSelect()
    {
      SqlSession sqlSession= MybaitsFactory.getSqlSession();
      Book book= sqlSession.selectOne("com.jsj.entries.Book.selectBookByid",1);

        System.out.println(book);
    }

    @Test
    public  void Testseldct1()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        Book book=bookService.selectBookByid(6);
        System.out.println(book);

    }

    @Test
    public  void TestselectAll()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
         List<Book> list= bookService.selectAll();
         for(Book book:list)
             System.out.println(book);

         sqlSession.close();

    }

    @Test
    public  void TestInsertBook()
    {
        Book book = new Book();
        book.setBname("大学计算机基础");
        book.setBtype(1);
        book.setPrice(16.8);
        book.setBdesc("计算机入门教材");
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        int ret= bookService.insertBook(book);
        sqlSession.commit();

        System.out.println("insert ret="+ret);

    }

    @Test
    public  void TestdelById()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);

        int ret= bookService.delById(4);
        sqlSession.commit();
        System.out.println("dele ret="+ret);
    }

    @Test
    public  void TestupdateByid()
    {
        Book book = new Book();
        //book.setBname("大学计算机基础");
      //  book.setBtype(1);
        book.setPrice(26.8);
        book.setBid(6);
      //  book.setBdesc("计算机入门教材");
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        int ret=bookService.updateByid(book);
        sqlSession.commit();
        System.out.println("update ret="+ret);
    }

    @Test
    public  void TestupdateByidmap()
    {
       Map map = new HashMap();
       map.put("price1",345.67);
       map.put("id",1);
        //  book.setBdesc("计算机入门教材");
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
         int ret =bookService.updateByMap(map);
        // int ret=bookService.updateByid(book);
        sqlSession.commit();
        System.out.println("update ret="+ret);
    }


    @Test
    public void TestselectBookByNameAndType()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        List<Book> list=bookService.selectBookByNameAndType("",0);
        for(Book book:list)
            System.out.println(book);

        sqlSession.close();
    }

    @Test
    public void TestselectBookByTrim()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        Map map= new HashMap();
      //  map.put("bname","java");
      //  map.put("btype",1);
      //  map.put("price",200);
        List<Book> list=bookService.selectBookByTrim(map);
        for(Book book:list)
            System.out.println(book);

        sqlSession.close();
    }

    @Test
    public void TestPage()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        int iPage=6;
        int PageSize=5;
        String key="%java%";
        int from=(iPage-1)*PageSize;
        List<Book> list=bookService.selectBookByPage(key,from,PageSize);

        for(Book book:list)
            System.out.println(book);

        sqlSession.close();

    }

    @Test
    public  void TestselectBookByList()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        List<Integer> types= new ArrayList<>();
        types.add(6);
        types.add(2);
        types.add(3);
        types.add(5);
        List<Book> list=bookService.selectBookByList(types);
        for(Book book:list)
            System.out.println(book);

        sqlSession.close();
    }

    @Test
    public  void TestselectBookByArray()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
//        List<Integer> types= new ArrayList<>();
//        types.add(6);
//        types.add(2);
//        types.add(3);
//        types.add(5);
        int[] types= new int[]{1,4,3,5,6};
        List<Book> list=bookService.selectBookByArray(types);
        for(Book book:list)
            System.out.println(book);

        sqlSession.close();

    }

    @Test
    public void TestselectBookByContent()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
//        List<Integer> types= new ArrayList<>();
//        types.add(6);
//        types.add(2);
//        types.add(3);
//        types.add(5);
        int[] types= new int[]{1,4,3,5,6};
        Map map= new HashMap();
        map.put("btypes",types);
        map.put("price",50);
        List<Book> list=bookService.selectBookByContent(map);
        for(Book book:list)
            System.out.println(book);

        sqlSession.close();

    }

    @Test
    public  void testselectBookByPageLimit()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        BookService bookService =sqlSession.getMapper(BookService.class);
        int pageIndex=1;
        int pageSize =5;
        int from=(pageIndex-1)*pageSize;
        List<Book> list= bookService.selectBookByPageLimit(10,from,pageSize);
        for(Book book:list)
            System.out.println(book);

        sqlSession.close();
    }
}

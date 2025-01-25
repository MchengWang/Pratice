package com.jsj.dao;

import com.jsj.entries.Book;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface BookService {

    public Book selectBookByid(int id);
    public List<Book> selectAll();
    public int insertBook(Book book);
    public int delById(int id);
    public  int updateByid(Book book);

    List<Book> selectBookByNameAndType(
            @Param("bname") String name, @Param("btype") int type);


    int updateByMap(Map map);

    List<Book> selectBookByTrim(Map map);

    List<Book> selectBookByList(List list);
    List<Book>selectBookByArray(int [] arr);
    List<Book> selectBookByContent(Map map);
    List<Book> selectBookByPageLimit(@Param("price") double price,@Param("from")
          int iStart  ,@Param("count") int pageSize);

    List<Book> selectBookByPage(@Param("key") String keyWord,@Param("from") int from,@Param("pageSize") int pageSize);



}

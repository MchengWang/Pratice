package com.itheima.service;

import com.itheima.domain.Book;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Transactional
public interface BookService {

    /**
     *  添加图书
     * @param book
     * @return
     */
    public boolean save(Book book);

    /**
     * 根据id删除图书
     * @param id
     * @return
     */
    public boolean delete(Integer id);

    /**
     * 根据id修改图书
     * @param book
     * @return
     */
    public boolean update(Book book);

    /**
     *  获取单个图书信息
     * @param id
     * @return
     */
    public Book getById(Integer id);

    /**
     * 获取全部图书
     * @return
     */
    public List<Book> getAll();
}

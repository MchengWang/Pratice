package com.itheima.Dao.impl;

import com.itheima.Dao.BookDao;

public class BookDaoImpl implements BookDao {
    private int connectionNum;
    private String databaseName;

    public void setDatabaseName(String databaseName) {
        this.databaseName = databaseName;
    }

    public void setConnectionNum(int connectionNum) {
        this.connectionNum = connectionNum;
    }

    public void save(){
        System.out.println("book dao save ... " + connectionNum + " , " + databaseName);
    }

}

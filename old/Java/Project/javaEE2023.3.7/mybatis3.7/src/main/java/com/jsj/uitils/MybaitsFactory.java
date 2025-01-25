package com.jsj.uitils;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;

public class MybaitsFactory {

    private static SqlSessionFactory sqlSessionFactory=null;

    static {

        try {
            InputStream inputStream= Resources.getResourceAsStream("mybatis-config.xml");
            sqlSessionFactory= new SqlSessionFactoryBuilder().build(inputStream);
            inputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static SqlSession getSqlSession()
    {
        SqlSession sqlSession =sqlSessionFactory.openSession();
        return sqlSession;
    }



}

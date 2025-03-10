package com.itheima;

import com.itheima.dao.UserDao;
import com.itheima.domain.User;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.ArrayList;
import java.util.List;

@SpringBootTest
class Mybatisplus03DmlApplicationTests {

    @Autowired
    private UserDao userDao;

    @Test
    void testSave() {
        User user = new User();
//        user.setId(43362L);
        user.setName("黑马程序员");
        user.setPassword("itheima");
        user.setAge(12);
        user.setTel("4006184000");
        userDao.insert(user);
    }

    @Test
    void testDelete(){
//        List<Long> list = new ArrayList<>();
//        list.add(1540971822806249473L);
//        list.add(1540974403246997505L);
//        list.add(1540974451888353281L);
//        userDao.deleteBatchIds(list);

        userDao.deleteById(2L);
//        System.out.println(userDao.selectList(null));

//        List<Long> list = new ArrayList<>();
//        list.add(1L);
//        list.add(3L);
//        list.add(4L);
//        userDao.selectBatchIds(list);
    }

    @Test
    void testUpdate(){
//        User user = new User();
//        user.setId(3L);
//        user.setName("Jock666");
//        user.setVersion(1);
//        userDao.updateById(user);

        // 1、先通过要修改的数据id将当前数据查询出来
        User user = userDao.selectById(3L); // version = 3

        User user2 = userDao.selectById(3L); // version = 3

        user2.setName("Jock aaa"); // version => 4
        userDao.updateById(user2);

        // 2、将要修改的属性注意设置进去
        user.setName("Jock bbb"); // version = 3?条件还成立吗？
        userDao.updateById(user);

    }

}

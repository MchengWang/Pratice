package Summarize.Spring_Data_JPA.Test;

import Summarize.Spring_Data_JPA.JPAUtil;
import Summarize.Spring_Data_JPA.domain.Customer;
import org.junit.Test;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;

public class JPAtest {

    @Test
    public void testAdd() {
        // 定义对象
        Customer c = new Customer();
        c.setCustName("传智学院");
        c.setCustLevel("VIP客户");
        c.setCustSource("网络");
        c.setCustIndustry("IT教育");
        c.setCustAddress("昌平区北七家镇");
        c.setCustPhone("010-84389340");
        EntityManager em = null;
        EntityTransaction tx = null;
        try {
            // 获取实体管理对象
            em = JPAUtil.getEntityManager();
            // 获取事务对象
            tx = em.getTransaction();
            // 开启事务
            tx.begin();
            // 执行操作
            em.persist(c);
            // 提交事务
            tx.commit();
        } catch (Exception e) {
            // 回滚事务
            tx.rollback();
            e.printStackTrace();
        } finally {
            // 释放资源
            em.close();
        }

    }

    @Test
    public void testMerge(){
        //定义对象
        EntityManager em=null;
        EntityTransaction tx=null;
        try{
            //获取实体管理对象
            em=JPAUtil.getEntityManager();
            //获取事务对象
            tx=em.getTransaction();
            //开启事务
            tx.begin();
            //执行操作
            Customer c1 = em.find(Customer.class, 6L);
            c1.setCustName("江苏传智学院");
            em.clear();//把c1对象从缓存中清除出去
            em.merge(c1);
            //提交事务
            tx.commit();
        }catch(Exception e){
            //回滚事务
            tx.rollback();
            e.printStackTrace();
        }finally{
            //释放资源
            em.close();
        }
    }

    /**
     * 删除
     */
    @Test
    public void testRemove() {
        // 定义对象
        EntityManager em = null;
        EntityTransaction tx = null;
        try {
            // 获取实体管理对象
            em = JPAUtil.getEntityManager();
            // 获取事务对象
            tx = em.getTransaction();
            // 开启事务
            tx.begin();
            // 执行操作
            Customer c1 = em.find(Customer.class, 6L);
            em.remove(c1);
            // 提交事务
            tx.commit();
        } catch (Exception e) {
            // 回滚事务
            tx.rollback();
            e.printStackTrace();
        } finally {
            // 释放资源
            em.close();
        }
    }

    /**
     * 查询一个： 使用立即加载的策略
     */
    @Test
    public void testGetOne() {
        // 定义对象
        EntityManager em = null;
        EntityTransaction tx = null;
        try {
            // 获取实体管理对象
            em = JPAUtil.getEntityManager();
            // 获取事务对象
            tx = em.getTransaction();
            // 开启事务
            tx.begin();
            // 执行操作
            Customer c1 = em.find(Customer.class, 1L);
            // 提交事务
            tx.commit();
            System.out.println(c1); // 输出查询对象
        } catch (Exception e) {
            // 回滚事务
            tx.rollback();
            e.printStackTrace();
        } finally {
            // 释放资源
            em.close();
        }
    }

    // 查询实体的缓存问题
    @Test
    public void testGetOneH() {
        // 定义对象
        EntityManager em = null;
        EntityTransaction tx = null;
        try {
            // 获取实体管理对象
            em = JPAUtil.getEntityManager();
            // 获取事务对象
            tx = em.getTransaction();
            // 开启事务
            tx.begin();
            // 执行操作
            Customer c1 = em.find(Customer.class, 1L);
            Customer c2 = em.find(Customer.class, 1L);
            System.out.println(c1 == c2);// 输出结果是true，EntityManager也有缓存
            // 提交事务
            tx.commit();
            System.out.println(c1);
        } catch (Exception e) {
            // 回滚事务
            tx.rollback();
            e.printStackTrace();
        } finally {
            // 释放资源
            em.close();
        }
    }

    // 延迟加载策略的方法：
    /**
     * 查询一个： 使用延迟加载策略
     */
    @Test
    public void testLoadOne() {
        // 定义对象
        EntityManager em = null;
        EntityTransaction tx = null;
        try {
            // 获取实体管理对象
            em = JPAUtil.getEntityManager();
            // 获取事务对象
            tx = em.getTransaction();
            // 开启事务
            tx.begin();
            // 执行操作
            Customer c1 = em.getReference(Customer.class, 1L);
            // 提交事务
            tx.commit();
            System.out.println(c1);
        } catch (Exception e) {
            // 回滚事务
            tx.rollback();
            e.printStackTrace();
        } finally {
            // 释放资源
            em.close();
        }
    }

}

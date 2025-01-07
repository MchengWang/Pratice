package Summarize.Spring_Data_JPA;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class JPAUtil {
    // JPA的实体管理器工厂：相当于Hibernate的SessionFactory
    private static final EntityManagerFactory myJPA;
    // 使用静态代码块赋值
    static {
        // 注意：该方法参数必须和persistence.xml中persistence-unit标签name属性取值一致
        myJPA = Persistence.createEntityManagerFactory("MyJPA");
    }

    /**
     * 使用管理器工厂生产一个管理器对象
     *
     * @return
     */
    public static EntityManager getEntityManager() {
        return myJPA.createEntityManager();
    }

}

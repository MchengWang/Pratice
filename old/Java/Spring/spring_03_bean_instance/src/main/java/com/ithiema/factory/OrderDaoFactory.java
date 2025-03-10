package com.ithiema.factory;

import com.ithiema.dao.OrderDao;
import com.ithiema.dao.impl.OrderDaoImpl;

public class OrderDaoFactory {
    public static OrderDao getOrderDao(){
        return new OrderDaoImpl();
    }
}

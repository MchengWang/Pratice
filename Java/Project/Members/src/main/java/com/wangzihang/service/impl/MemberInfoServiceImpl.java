package com.wangzihang.service.impl;

import com.wangzihang.dao.MemberInfoDao;
import com.wangzihang.pojo.MemberInfo;
import com.wangzihang.service.MemberInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MemberInfoServiceImpl implements MemberInfoService {

    @Autowired
    private MemberInfoDao roomsDao;

    @Override
    public boolean save(MemberInfo rooms) {
        roomsDao.insertRooms(rooms);
        return true;
    }


    @Override
    public boolean delete(int id) {
        roomsDao.delete(id);
        return true;
    }

    @Override
    public boolean update(MemberInfo rooms) {
        roomsDao.update(rooms);
        return true;
    }

    @Override
    public MemberInfo getById(Integer id) {
        MemberInfo rooms = roomsDao.selectById(id);
        return rooms;
    }

    @Override
    public List<MemberInfo> getAll() {
        List<MemberInfo> roomsList = roomsDao.getAll();
        return roomsList;
    }
}

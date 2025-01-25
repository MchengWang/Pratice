package com.household.service.impl;

import com.household.dao.HouseHoldInfoDao;
import com.household.pojo.HouseHoldInfo;
import com.household.service.HouseHoldInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class HouseHoldInfoServiceImpl implements HouseHoldInfoService {

    @Autowired
    private HouseHoldInfoDao houseHoldInfoDao;

    public boolean save(HouseHoldInfo houseHoldInfo) {
        houseHoldInfoDao.save(houseHoldInfo);
        return true;
    }

    public boolean delete(int id) {
        houseHoldInfoDao.delete(id);
        return true;
    }

    public boolean update(HouseHoldInfo houseHoldInfo) {
        houseHoldInfoDao.update(houseHoldInfo);
        return true;
    }

    public HouseHoldInfo getById(Integer id) {
        HouseHoldInfo houseHoldInfo = houseHoldInfoDao.getById(id);
        return houseHoldInfo;
    }

    public List<HouseHoldInfo> getAll() {
        List<HouseHoldInfo> houseHoldInfos = houseHoldInfoDao.getAll();
        return houseHoldInfos;
    }
}

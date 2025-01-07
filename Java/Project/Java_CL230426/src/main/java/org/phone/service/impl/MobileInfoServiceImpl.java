package org.phone.service.impl;

import org.phone.dao.MobileInfoDao;
import org.phone.pojo.MobileInfo;
import org.phone.service.MobileInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MobileInfoServiceImpl implements MobileInfoService {

    @Autowired
    private MobileInfoDao mobileInfoDao;

    public boolean save(MobileInfo mobileInfo) {
        mobileInfoDao.save(mobileInfo);
        return true;
    }

    public boolean delete(int id) {
        mobileInfoDao.delete(id);
        return true;
    }

    public boolean update(MobileInfo mobileInfo) {
        mobileInfoDao.update(mobileInfo);
        return true;
    }

    public MobileInfo getById(Integer id) {
        MobileInfo mobileInfo = mobileInfoDao.getById(id);
        return mobileInfo;
    }

    public List<MobileInfo> getAll() {
        List<MobileInfo> mobileInfoList = mobileInfoDao.getAll();
        return mobileInfoList;
    }
}

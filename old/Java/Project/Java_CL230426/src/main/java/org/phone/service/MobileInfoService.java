package org.phone.service;

import org.phone.pojo.MobileInfo;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Transactional
public interface MobileInfoService {

    public boolean save(MobileInfo mobileInfo);


    public boolean delete(int id);

    public boolean update(MobileInfo mobileInfo);

    public MobileInfo getById(Integer id);

    public List<MobileInfo> getAll();
}

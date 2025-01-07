package com.household.service;

import com.household.pojo.HouseHoldInfo;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Transactional
public interface HouseHoldInfoService {

    public boolean save(HouseHoldInfo houseHoldInfo);


    public boolean delete(int id);

    public boolean update(HouseHoldInfo houseHoldInfo);

    public HouseHoldInfo getById(Integer id);

    public List<HouseHoldInfo> getAll();
}

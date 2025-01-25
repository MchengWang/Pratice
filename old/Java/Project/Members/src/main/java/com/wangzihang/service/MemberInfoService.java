package com.wangzihang.service;

import com.wangzihang.pojo.MemberInfo;

import java.util.List;

//@Transactional
public interface MemberInfoService {

    public boolean save(MemberInfo rooms);


    public boolean delete(int id);

    public boolean update(MemberInfo rooms);

    public MemberInfo getById(Integer id);

    public List<MemberInfo> getAll();
}

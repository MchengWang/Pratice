package com.itheima.service;

import com.itheima.domain.Account;

import java.util.List;

public interface AccountService {

    public void save(Account account);

    public void update(Account account);

    public void delete(Integer id);

    public Account findById(Integer id);

    public List<Account> findAll();
}

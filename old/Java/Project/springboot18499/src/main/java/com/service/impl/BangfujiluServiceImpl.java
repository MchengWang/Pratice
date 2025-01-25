package com.service.impl;

import org.springframework.stereotype.Service;
import java.util.Map;
import java.util.List;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.mapper.EntityWrapper;
import com.baomidou.mybatisplus.plugins.Page;
import com.baomidou.mybatisplus.service.impl.ServiceImpl;
import com.utils.PageUtils;
import com.utils.Query;


import com.dao.BangfujiluDao;
import com.entity.BangfujiluEntity;
import com.service.BangfujiluService;
import com.entity.vo.BangfujiluVO;
import com.entity.view.BangfujiluView;

@Service("bangfujiluService")
public class BangfujiluServiceImpl extends ServiceImpl<BangfujiluDao, BangfujiluEntity> implements BangfujiluService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<BangfujiluEntity> page = this.selectPage(
                new Query<BangfujiluEntity>(params).getPage(),
                new EntityWrapper<BangfujiluEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<BangfujiluEntity> wrapper) {
		  Page<BangfujiluView> page =new Query<BangfujiluView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<BangfujiluVO> selectListVO(Wrapper<BangfujiluEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public BangfujiluVO selectVO(Wrapper<BangfujiluEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<BangfujiluView> selectListView(Wrapper<BangfujiluEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public BangfujiluView selectView(Wrapper<BangfujiluEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

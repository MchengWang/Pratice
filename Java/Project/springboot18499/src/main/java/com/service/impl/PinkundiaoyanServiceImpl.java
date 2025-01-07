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


import com.dao.PinkundiaoyanDao;
import com.entity.PinkundiaoyanEntity;
import com.service.PinkundiaoyanService;
import com.entity.vo.PinkundiaoyanVO;
import com.entity.view.PinkundiaoyanView;

@Service("pinkundiaoyanService")
public class PinkundiaoyanServiceImpl extends ServiceImpl<PinkundiaoyanDao, PinkundiaoyanEntity> implements PinkundiaoyanService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<PinkundiaoyanEntity> page = this.selectPage(
                new Query<PinkundiaoyanEntity>(params).getPage(),
                new EntityWrapper<PinkundiaoyanEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<PinkundiaoyanEntity> wrapper) {
		  Page<PinkundiaoyanView> page =new Query<PinkundiaoyanView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<PinkundiaoyanVO> selectListVO(Wrapper<PinkundiaoyanEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public PinkundiaoyanVO selectVO(Wrapper<PinkundiaoyanEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<PinkundiaoyanView> selectListView(Wrapper<PinkundiaoyanEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public PinkundiaoyanView selectView(Wrapper<PinkundiaoyanEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

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


import com.dao.PinkunshenqingDao;
import com.entity.PinkunshenqingEntity;
import com.service.PinkunshenqingService;
import com.entity.vo.PinkunshenqingVO;
import com.entity.view.PinkunshenqingView;

@Service("pinkunshenqingService")
public class PinkunshenqingServiceImpl extends ServiceImpl<PinkunshenqingDao, PinkunshenqingEntity> implements PinkunshenqingService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<PinkunshenqingEntity> page = this.selectPage(
                new Query<PinkunshenqingEntity>(params).getPage(),
                new EntityWrapper<PinkunshenqingEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<PinkunshenqingEntity> wrapper) {
		  Page<PinkunshenqingView> page =new Query<PinkunshenqingView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<PinkunshenqingVO> selectListVO(Wrapper<PinkunshenqingEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public PinkunshenqingVO selectVO(Wrapper<PinkunshenqingEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<PinkunshenqingView> selectListView(Wrapper<PinkunshenqingEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public PinkunshenqingView selectView(Wrapper<PinkunshenqingEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}

    @Override
    public List<Map<String, Object>> selectValue(Map<String, Object> params, Wrapper<PinkunshenqingEntity> wrapper) {
        return baseMapper.selectValue(params, wrapper);
    }

    @Override
    public List<Map<String, Object>> selectTimeStatValue(Map<String, Object> params, Wrapper<PinkunshenqingEntity> wrapper) {
        return baseMapper.selectTimeStatValue(params, wrapper);
    }

    @Override
    public List<Map<String, Object>> selectGroup(Map<String, Object> params, Wrapper<PinkunshenqingEntity> wrapper) {
        return baseMapper.selectGroup(params, wrapper);
    }




}

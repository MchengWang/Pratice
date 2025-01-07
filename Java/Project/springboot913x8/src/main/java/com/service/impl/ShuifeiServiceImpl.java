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


import com.dao.ShuifeiDao;
import com.entity.ShuifeiEntity;
import com.service.ShuifeiService;
import com.entity.vo.ShuifeiVO;
import com.entity.view.ShuifeiView;

@Service("shuifeiService")
public class ShuifeiServiceImpl extends ServiceImpl<ShuifeiDao, ShuifeiEntity> implements ShuifeiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<ShuifeiEntity> page = this.selectPage(
                new Query<ShuifeiEntity>(params).getPage(),
                new EntityWrapper<ShuifeiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<ShuifeiEntity> wrapper) {
		  Page<ShuifeiView> page =new Query<ShuifeiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<ShuifeiVO> selectListVO(Wrapper<ShuifeiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public ShuifeiVO selectVO(Wrapper<ShuifeiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<ShuifeiView> selectListView(Wrapper<ShuifeiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public ShuifeiView selectView(Wrapper<ShuifeiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}

    @Override
    public List<Map<String, Object>> selectValue(Map<String, Object> params, Wrapper<ShuifeiEntity> wrapper) {
        return baseMapper.selectValue(params, wrapper);
    }

    @Override
    public List<Map<String, Object>> selectTimeStatValue(Map<String, Object> params, Wrapper<ShuifeiEntity> wrapper) {
        return baseMapper.selectTimeStatValue(params, wrapper);
    }

    @Override
    public List<Map<String, Object>> selectGroup(Map<String, Object> params, Wrapper<ShuifeiEntity> wrapper) {
        return baseMapper.selectGroup(params, wrapper);
    }




}

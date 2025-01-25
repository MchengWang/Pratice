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


import com.dao.DianfeiDao;
import com.entity.DianfeiEntity;
import com.service.DianfeiService;
import com.entity.vo.DianfeiVO;
import com.entity.view.DianfeiView;

@Service("dianfeiService")
public class DianfeiServiceImpl extends ServiceImpl<DianfeiDao, DianfeiEntity> implements DianfeiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<DianfeiEntity> page = this.selectPage(
                new Query<DianfeiEntity>(params).getPage(),
                new EntityWrapper<DianfeiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<DianfeiEntity> wrapper) {
		  Page<DianfeiView> page =new Query<DianfeiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<DianfeiVO> selectListVO(Wrapper<DianfeiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public DianfeiVO selectVO(Wrapper<DianfeiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<DianfeiView> selectListView(Wrapper<DianfeiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public DianfeiView selectView(Wrapper<DianfeiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}

    @Override
    public List<Map<String, Object>> selectValue(Map<String, Object> params, Wrapper<DianfeiEntity> wrapper) {
        return baseMapper.selectValue(params, wrapper);
    }

    @Override
    public List<Map<String, Object>> selectTimeStatValue(Map<String, Object> params, Wrapper<DianfeiEntity> wrapper) {
        return baseMapper.selectTimeStatValue(params, wrapper);
    }

    @Override
    public List<Map<String, Object>> selectGroup(Map<String, Object> params, Wrapper<DianfeiEntity> wrapper) {
        return baseMapper.selectGroup(params, wrapper);
    }




}

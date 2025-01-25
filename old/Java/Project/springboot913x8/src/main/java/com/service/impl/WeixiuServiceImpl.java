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


import com.dao.WeixiuDao;
import com.entity.WeixiuEntity;
import com.service.WeixiuService;
import com.entity.vo.WeixiuVO;
import com.entity.view.WeixiuView;

@Service("weixiuService")
public class WeixiuServiceImpl extends ServiceImpl<WeixiuDao, WeixiuEntity> implements WeixiuService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<WeixiuEntity> page = this.selectPage(
                new Query<WeixiuEntity>(params).getPage(),
                new EntityWrapper<WeixiuEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<WeixiuEntity> wrapper) {
		  Page<WeixiuView> page =new Query<WeixiuView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<WeixiuVO> selectListVO(Wrapper<WeixiuEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public WeixiuVO selectVO(Wrapper<WeixiuEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<WeixiuView> selectListView(Wrapper<WeixiuEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public WeixiuView selectView(Wrapper<WeixiuEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

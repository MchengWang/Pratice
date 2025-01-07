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


import com.dao.BangfujieduiDao;
import com.entity.BangfujieduiEntity;
import com.service.BangfujieduiService;
import com.entity.vo.BangfujieduiVO;
import com.entity.view.BangfujieduiView;

@Service("bangfujieduiService")
public class BangfujieduiServiceImpl extends ServiceImpl<BangfujieduiDao, BangfujieduiEntity> implements BangfujieduiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<BangfujieduiEntity> page = this.selectPage(
                new Query<BangfujieduiEntity>(params).getPage(),
                new EntityWrapper<BangfujieduiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<BangfujieduiEntity> wrapper) {
		  Page<BangfujieduiView> page =new Query<BangfujieduiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<BangfujieduiVO> selectListVO(Wrapper<BangfujieduiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public BangfujieduiVO selectVO(Wrapper<BangfujieduiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<BangfujieduiView> selectListView(Wrapper<BangfujieduiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public BangfujieduiView selectView(Wrapper<BangfujieduiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

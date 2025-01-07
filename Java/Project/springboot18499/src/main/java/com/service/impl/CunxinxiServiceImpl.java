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


import com.dao.CunxinxiDao;
import com.entity.CunxinxiEntity;
import com.service.CunxinxiService;
import com.entity.vo.CunxinxiVO;
import com.entity.view.CunxinxiView;

@Service("cunxinxiService")
public class CunxinxiServiceImpl extends ServiceImpl<CunxinxiDao, CunxinxiEntity> implements CunxinxiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<CunxinxiEntity> page = this.selectPage(
                new Query<CunxinxiEntity>(params).getPage(),
                new EntityWrapper<CunxinxiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<CunxinxiEntity> wrapper) {
		  Page<CunxinxiView> page =new Query<CunxinxiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<CunxinxiVO> selectListVO(Wrapper<CunxinxiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public CunxinxiVO selectVO(Wrapper<CunxinxiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<CunxinxiView> selectListView(Wrapper<CunxinxiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public CunxinxiView selectView(Wrapper<CunxinxiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

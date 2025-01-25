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


import com.dao.MenjinxinxiDao;
import com.entity.MenjinxinxiEntity;
import com.service.MenjinxinxiService;
import com.entity.vo.MenjinxinxiVO;
import com.entity.view.MenjinxinxiView;

@Service("menjinxinxiService")
public class MenjinxinxiServiceImpl extends ServiceImpl<MenjinxinxiDao, MenjinxinxiEntity> implements MenjinxinxiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<MenjinxinxiEntity> page = this.selectPage(
                new Query<MenjinxinxiEntity>(params).getPage(),
                new EntityWrapper<MenjinxinxiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<MenjinxinxiEntity> wrapper) {
		  Page<MenjinxinxiView> page =new Query<MenjinxinxiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<MenjinxinxiVO> selectListVO(Wrapper<MenjinxinxiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public MenjinxinxiVO selectVO(Wrapper<MenjinxinxiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<MenjinxinxiView> selectListView(Wrapper<MenjinxinxiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public MenjinxinxiView selectView(Wrapper<MenjinxinxiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

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


import com.dao.WeishengtongjiDao;
import com.entity.WeishengtongjiEntity;
import com.service.WeishengtongjiService;
import com.entity.vo.WeishengtongjiVO;
import com.entity.view.WeishengtongjiView;

@Service("weishengtongjiService")
public class WeishengtongjiServiceImpl extends ServiceImpl<WeishengtongjiDao, WeishengtongjiEntity> implements WeishengtongjiService {
	
	
    @Override
    public PageUtils queryPage(Map<String, Object> params) {
        Page<WeishengtongjiEntity> page = this.selectPage(
                new Query<WeishengtongjiEntity>(params).getPage(),
                new EntityWrapper<WeishengtongjiEntity>()
        );
        return new PageUtils(page);
    }
    
    @Override
	public PageUtils queryPage(Map<String, Object> params, Wrapper<WeishengtongjiEntity> wrapper) {
		  Page<WeishengtongjiView> page =new Query<WeishengtongjiView>(params).getPage();
	        page.setRecords(baseMapper.selectListView(page,wrapper));
	    	PageUtils pageUtil = new PageUtils(page);
	    	return pageUtil;
 	}
    
    @Override
	public List<WeishengtongjiVO> selectListVO(Wrapper<WeishengtongjiEntity> wrapper) {
 		return baseMapper.selectListVO(wrapper);
	}
	
	@Override
	public WeishengtongjiVO selectVO(Wrapper<WeishengtongjiEntity> wrapper) {
 		return baseMapper.selectVO(wrapper);
	}
	
	@Override
	public List<WeishengtongjiView> selectListView(Wrapper<WeishengtongjiEntity> wrapper) {
		return baseMapper.selectListView(wrapper);
	}

	@Override
	public WeishengtongjiView selectView(Wrapper<WeishengtongjiEntity> wrapper) {
		return baseMapper.selectView(wrapper);
	}


}

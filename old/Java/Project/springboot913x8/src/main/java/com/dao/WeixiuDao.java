package com.dao;

import com.entity.WeixiuEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.WeixiuVO;
import com.entity.view.WeixiuView;


/**
 * 维修
 * 
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface WeixiuDao extends BaseMapper<WeixiuEntity> {
	
	List<WeixiuVO> selectListVO(@Param("ew") Wrapper<WeixiuEntity> wrapper);
	
	WeixiuVO selectVO(@Param("ew") Wrapper<WeixiuEntity> wrapper);
	
	List<WeixiuView> selectListView(@Param("ew") Wrapper<WeixiuEntity> wrapper);

	List<WeixiuView> selectListView(Pagination page,@Param("ew") Wrapper<WeixiuEntity> wrapper);
	
	WeixiuView selectView(@Param("ew") Wrapper<WeixiuEntity> wrapper);
	

}

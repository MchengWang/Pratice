package com.dao;

import com.entity.PinkundiaoyanEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.PinkundiaoyanVO;
import com.entity.view.PinkundiaoyanView;


/**
 * 孤寡与贫困户调研
 * 
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface PinkundiaoyanDao extends BaseMapper<PinkundiaoyanEntity> {
	
	List<PinkundiaoyanVO> selectListVO(@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);
	
	PinkundiaoyanVO selectVO(@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);
	
	List<PinkundiaoyanView> selectListView(@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);

	List<PinkundiaoyanView> selectListView(Pagination page,@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);
	
	PinkundiaoyanView selectView(@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);
	

}

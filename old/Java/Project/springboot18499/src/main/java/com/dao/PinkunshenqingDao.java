package com.dao;

import com.entity.PinkunshenqingEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.PinkunshenqingVO;
import com.entity.view.PinkunshenqingView;


/**
 * 孤寡与贫困户申请
 * 
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface PinkunshenqingDao extends BaseMapper<PinkunshenqingEntity> {
	
	List<PinkunshenqingVO> selectListVO(@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);
	
	PinkunshenqingVO selectVO(@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);
	
	List<PinkunshenqingView> selectListView(@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);

	List<PinkunshenqingView> selectListView(Pagination page,@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);
	
	PinkunshenqingView selectView(@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);
	

    List<Map<String, Object>> selectValue(@Param("params") Map<String, Object> params,@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);

    List<Map<String, Object>> selectTimeStatValue(@Param("params") Map<String, Object> params,@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);

    List<Map<String, Object>> selectGroup(@Param("params") Map<String, Object> params,@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);



}

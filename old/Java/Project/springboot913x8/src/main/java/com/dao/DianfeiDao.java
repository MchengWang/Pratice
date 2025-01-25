package com.dao;

import com.entity.DianfeiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.DianfeiVO;
import com.entity.view.DianfeiView;


/**
 * 电费
 * 
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface DianfeiDao extends BaseMapper<DianfeiEntity> {
	
	List<DianfeiVO> selectListVO(@Param("ew") Wrapper<DianfeiEntity> wrapper);
	
	DianfeiVO selectVO(@Param("ew") Wrapper<DianfeiEntity> wrapper);
	
	List<DianfeiView> selectListView(@Param("ew") Wrapper<DianfeiEntity> wrapper);

	List<DianfeiView> selectListView(Pagination page,@Param("ew") Wrapper<DianfeiEntity> wrapper);
	
	DianfeiView selectView(@Param("ew") Wrapper<DianfeiEntity> wrapper);
	

    List<Map<String, Object>> selectValue(@Param("params") Map<String, Object> params,@Param("ew") Wrapper<DianfeiEntity> wrapper);

    List<Map<String, Object>> selectTimeStatValue(@Param("params") Map<String, Object> params,@Param("ew") Wrapper<DianfeiEntity> wrapper);

    List<Map<String, Object>> selectGroup(@Param("params") Map<String, Object> params,@Param("ew") Wrapper<DianfeiEntity> wrapper);



}

package com.dao;

import com.entity.MenjinxinxiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.MenjinxinxiVO;
import com.entity.view.MenjinxinxiView;


/**
 * 门禁信息
 * 
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface MenjinxinxiDao extends BaseMapper<MenjinxinxiEntity> {
	
	List<MenjinxinxiVO> selectListVO(@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);
	
	MenjinxinxiVO selectVO(@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);
	
	List<MenjinxinxiView> selectListView(@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);

	List<MenjinxinxiView> selectListView(Pagination page,@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);
	
	MenjinxinxiView selectView(@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);
	

}

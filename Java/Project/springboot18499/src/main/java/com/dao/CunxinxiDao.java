package com.dao;

import com.entity.CunxinxiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.CunxinxiVO;
import com.entity.view.CunxinxiView;


/**
 * 地区信息
 * 
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface CunxinxiDao extends BaseMapper<CunxinxiEntity> {
	
	List<CunxinxiVO> selectListVO(@Param("ew") Wrapper<CunxinxiEntity> wrapper);
	
	CunxinxiVO selectVO(@Param("ew") Wrapper<CunxinxiEntity> wrapper);
	
	List<CunxinxiView> selectListView(@Param("ew") Wrapper<CunxinxiEntity> wrapper);

	List<CunxinxiView> selectListView(Pagination page,@Param("ew") Wrapper<CunxinxiEntity> wrapper);
	
	CunxinxiView selectView(@Param("ew") Wrapper<CunxinxiEntity> wrapper);
	

}

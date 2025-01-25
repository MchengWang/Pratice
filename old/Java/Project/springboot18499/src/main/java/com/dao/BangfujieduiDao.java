package com.dao;

import com.entity.BangfujieduiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.BangfujieduiVO;
import com.entity.view.BangfujieduiView;


/**
 * 帮扶结对
 * 
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface BangfujieduiDao extends BaseMapper<BangfujieduiEntity> {
	
	List<BangfujieduiVO> selectListVO(@Param("ew") Wrapper<BangfujieduiEntity> wrapper);
	
	BangfujieduiVO selectVO(@Param("ew") Wrapper<BangfujieduiEntity> wrapper);
	
	List<BangfujieduiView> selectListView(@Param("ew") Wrapper<BangfujieduiEntity> wrapper);

	List<BangfujieduiView> selectListView(Pagination page,@Param("ew") Wrapper<BangfujieduiEntity> wrapper);
	
	BangfujieduiView selectView(@Param("ew") Wrapper<BangfujieduiEntity> wrapper);
	

}

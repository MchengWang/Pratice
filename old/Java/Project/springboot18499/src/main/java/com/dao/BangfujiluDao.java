package com.dao;

import com.entity.BangfujiluEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.BangfujiluVO;
import com.entity.view.BangfujiluView;


/**
 * 帮扶与募捐记录
 * 
 * @author 
 * @email 
 * @date 2030-03-31 17:44:52
 */
public interface BangfujiluDao extends BaseMapper<BangfujiluEntity> {
	
	List<BangfujiluVO> selectListVO(@Param("ew") Wrapper<BangfujiluEntity> wrapper);
	
	BangfujiluVO selectVO(@Param("ew") Wrapper<BangfujiluEntity> wrapper);
	
	List<BangfujiluView> selectListView(@Param("ew") Wrapper<BangfujiluEntity> wrapper);

	List<BangfujiluView> selectListView(Pagination page,@Param("ew") Wrapper<BangfujiluEntity> wrapper);
	
	BangfujiluView selectView(@Param("ew") Wrapper<BangfujiluEntity> wrapper);
	

}

package com.dao;

import com.entity.WeishengtongjiEntity;
import com.baomidou.mybatisplus.mapper.BaseMapper;
import java.util.List;
import java.util.Map;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.plugins.pagination.Pagination;

import org.apache.ibatis.annotations.Param;
import com.entity.vo.WeishengtongjiVO;
import com.entity.view.WeishengtongjiView;


/**
 * 卫生统计
 * 
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface WeishengtongjiDao extends BaseMapper<WeishengtongjiEntity> {
	
	List<WeishengtongjiVO> selectListVO(@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);
	
	WeishengtongjiVO selectVO(@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);
	
	List<WeishengtongjiView> selectListView(@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);

	List<WeishengtongjiView> selectListView(Pagination page,@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);
	
	WeishengtongjiView selectView(@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);
	

}

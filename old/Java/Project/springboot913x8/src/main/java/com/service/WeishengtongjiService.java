package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.WeishengtongjiEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.WeishengtongjiVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.WeishengtongjiView;


/**
 * 卫生统计
 *
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface WeishengtongjiService extends IService<WeishengtongjiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<WeishengtongjiVO> selectListVO(Wrapper<WeishengtongjiEntity> wrapper);
   	
   	WeishengtongjiVO selectVO(@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);
   	
   	List<WeishengtongjiView> selectListView(Wrapper<WeishengtongjiEntity> wrapper);
   	
   	WeishengtongjiView selectView(@Param("ew") Wrapper<WeishengtongjiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<WeishengtongjiEntity> wrapper);
   	

}


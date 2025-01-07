package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.WeixiuEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.WeixiuVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.WeixiuView;


/**
 * 维修
 *
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface WeixiuService extends IService<WeixiuEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<WeixiuVO> selectListVO(Wrapper<WeixiuEntity> wrapper);
   	
   	WeixiuVO selectVO(@Param("ew") Wrapper<WeixiuEntity> wrapper);
   	
   	List<WeixiuView> selectListView(Wrapper<WeixiuEntity> wrapper);
   	
   	WeixiuView selectView(@Param("ew") Wrapper<WeixiuEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<WeixiuEntity> wrapper);
   	

}


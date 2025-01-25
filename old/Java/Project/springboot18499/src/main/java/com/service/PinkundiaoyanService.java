package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.PinkundiaoyanEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.PinkundiaoyanVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.PinkundiaoyanView;


/**
 * 孤寡与贫困户调研
 *
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface PinkundiaoyanService extends IService<PinkundiaoyanEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<PinkundiaoyanVO> selectListVO(Wrapper<PinkundiaoyanEntity> wrapper);
   	
   	PinkundiaoyanVO selectVO(@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);
   	
   	List<PinkundiaoyanView> selectListView(Wrapper<PinkundiaoyanEntity> wrapper);
   	
   	PinkundiaoyanView selectView(@Param("ew") Wrapper<PinkundiaoyanEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<PinkundiaoyanEntity> wrapper);
   	

}


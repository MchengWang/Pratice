package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.PinkunshenqingEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.PinkunshenqingVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.PinkunshenqingView;


/**
 * 孤寡与贫困户申请
 *
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface PinkunshenqingService extends IService<PinkunshenqingEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<PinkunshenqingVO> selectListVO(Wrapper<PinkunshenqingEntity> wrapper);
   	
   	PinkunshenqingVO selectVO(@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);
   	
   	List<PinkunshenqingView> selectListView(Wrapper<PinkunshenqingEntity> wrapper);
   	
   	PinkunshenqingView selectView(@Param("ew") Wrapper<PinkunshenqingEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<PinkunshenqingEntity> wrapper);
   	

    List<Map<String, Object>> selectValue(Map<String, Object> params,Wrapper<PinkunshenqingEntity> wrapper);

    List<Map<String, Object>> selectTimeStatValue(Map<String, Object> params,Wrapper<PinkunshenqingEntity> wrapper);

    List<Map<String, Object>> selectGroup(Map<String, Object> params,Wrapper<PinkunshenqingEntity> wrapper);



}


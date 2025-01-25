package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.ShuifeiEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.ShuifeiVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.ShuifeiView;


/**
 * 水费
 *
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface ShuifeiService extends IService<ShuifeiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<ShuifeiVO> selectListVO(Wrapper<ShuifeiEntity> wrapper);
   	
   	ShuifeiVO selectVO(@Param("ew") Wrapper<ShuifeiEntity> wrapper);
   	
   	List<ShuifeiView> selectListView(Wrapper<ShuifeiEntity> wrapper);
   	
   	ShuifeiView selectView(@Param("ew") Wrapper<ShuifeiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<ShuifeiEntity> wrapper);
   	

    List<Map<String, Object>> selectValue(Map<String, Object> params,Wrapper<ShuifeiEntity> wrapper);

    List<Map<String, Object>> selectTimeStatValue(Map<String, Object> params,Wrapper<ShuifeiEntity> wrapper);

    List<Map<String, Object>> selectGroup(Map<String, Object> params,Wrapper<ShuifeiEntity> wrapper);



}


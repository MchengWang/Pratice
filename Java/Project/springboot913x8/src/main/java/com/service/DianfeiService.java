package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.DianfeiEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.DianfeiVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.DianfeiView;


/**
 * 电费
 *
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface DianfeiService extends IService<DianfeiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<DianfeiVO> selectListVO(Wrapper<DianfeiEntity> wrapper);
   	
   	DianfeiVO selectVO(@Param("ew") Wrapper<DianfeiEntity> wrapper);
   	
   	List<DianfeiView> selectListView(Wrapper<DianfeiEntity> wrapper);
   	
   	DianfeiView selectView(@Param("ew") Wrapper<DianfeiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<DianfeiEntity> wrapper);
   	

    List<Map<String, Object>> selectValue(Map<String, Object> params,Wrapper<DianfeiEntity> wrapper);

    List<Map<String, Object>> selectTimeStatValue(Map<String, Object> params,Wrapper<DianfeiEntity> wrapper);

    List<Map<String, Object>> selectGroup(Map<String, Object> params,Wrapper<DianfeiEntity> wrapper);



}


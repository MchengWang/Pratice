package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.BangfujieduiEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.BangfujieduiVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.BangfujieduiView;


/**
 * 帮扶结对
 *
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface BangfujieduiService extends IService<BangfujieduiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<BangfujieduiVO> selectListVO(Wrapper<BangfujieduiEntity> wrapper);
   	
   	BangfujieduiVO selectVO(@Param("ew") Wrapper<BangfujieduiEntity> wrapper);
   	
   	List<BangfujieduiView> selectListView(Wrapper<BangfujieduiEntity> wrapper);
   	
   	BangfujieduiView selectView(@Param("ew") Wrapper<BangfujieduiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<BangfujieduiEntity> wrapper);
   	

}


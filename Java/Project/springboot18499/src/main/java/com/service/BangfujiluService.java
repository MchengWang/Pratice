package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.BangfujiluEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.BangfujiluVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.BangfujiluView;


/**
 * 帮扶与募捐记录
 *
 * @author 
 * @email 
 * @date 2030-03-31 17:44:52
 */
public interface BangfujiluService extends IService<BangfujiluEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<BangfujiluVO> selectListVO(Wrapper<BangfujiluEntity> wrapper);
   	
   	BangfujiluVO selectVO(@Param("ew") Wrapper<BangfujiluEntity> wrapper);
   	
   	List<BangfujiluView> selectListView(Wrapper<BangfujiluEntity> wrapper);
   	
   	BangfujiluView selectView(@Param("ew") Wrapper<BangfujiluEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<BangfujiluEntity> wrapper);
   	

}


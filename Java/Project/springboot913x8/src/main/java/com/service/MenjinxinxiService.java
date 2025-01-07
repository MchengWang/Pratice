package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.MenjinxinxiEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.MenjinxinxiVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.MenjinxinxiView;


/**
 * 门禁信息
 *
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public interface MenjinxinxiService extends IService<MenjinxinxiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<MenjinxinxiVO> selectListVO(Wrapper<MenjinxinxiEntity> wrapper);
   	
   	MenjinxinxiVO selectVO(@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);
   	
   	List<MenjinxinxiView> selectListView(Wrapper<MenjinxinxiEntity> wrapper);
   	
   	MenjinxinxiView selectView(@Param("ew") Wrapper<MenjinxinxiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<MenjinxinxiEntity> wrapper);
   	

}


package com.service;

import com.baomidou.mybatisplus.mapper.Wrapper;
import com.baomidou.mybatisplus.service.IService;
import com.utils.PageUtils;
import com.entity.CunxinxiEntity;
import java.util.List;
import java.util.Map;
import com.entity.vo.CunxinxiVO;
import org.apache.ibatis.annotations.Param;
import com.entity.view.CunxinxiView;


/**
 * 地区信息
 *
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public interface CunxinxiService extends IService<CunxinxiEntity> {

    PageUtils queryPage(Map<String, Object> params);
    
   	List<CunxinxiVO> selectListVO(Wrapper<CunxinxiEntity> wrapper);
   	
   	CunxinxiVO selectVO(@Param("ew") Wrapper<CunxinxiEntity> wrapper);
   	
   	List<CunxinxiView> selectListView(Wrapper<CunxinxiEntity> wrapper);
   	
   	CunxinxiView selectView(@Param("ew") Wrapper<CunxinxiEntity> wrapper);
   	
   	PageUtils queryPage(Map<String, Object> params,Wrapper<CunxinxiEntity> wrapper);
   	

}


package com.entity.view;

import com.entity.DianfeiEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import org.apache.commons.beanutils.BeanUtils;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
 

/**
 * 电费
 * 后端返回视图实体辅助类   
 * （通常后端关联的表或者自定义的字段需要返回使用）
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
@TableName("dianfei")
public class DianfeiView  extends DianfeiEntity implements Serializable {
	private static final long serialVersionUID = 1L;

	public DianfeiView(){
	}
 
 	public DianfeiView(DianfeiEntity dianfeiEntity){
 	try {
			BeanUtils.copyProperties(this, dianfeiEntity);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		
	}
}

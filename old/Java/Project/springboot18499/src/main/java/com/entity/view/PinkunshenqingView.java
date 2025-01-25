package com.entity.view;

import com.entity.PinkunshenqingEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import org.apache.commons.beanutils.BeanUtils;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
 

/**
 * 孤寡与贫困户申请
 * 后端返回视图实体辅助类   
 * （通常后端关联的表或者自定义的字段需要返回使用）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("pinkunshenqing")
public class PinkunshenqingView  extends PinkunshenqingEntity implements Serializable {
	private static final long serialVersionUID = 1L;

	public PinkunshenqingView(){
	}
 
 	public PinkunshenqingView(PinkunshenqingEntity pinkunshenqingEntity){
 	try {
			BeanUtils.copyProperties(this, pinkunshenqingEntity);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		
	}
}

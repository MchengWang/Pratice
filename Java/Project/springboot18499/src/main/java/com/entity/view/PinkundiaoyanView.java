package com.entity.view;

import com.entity.PinkundiaoyanEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import org.apache.commons.beanutils.BeanUtils;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
 

/**
 * 孤寡与贫困户调研
 * 后端返回视图实体辅助类   
 * （通常后端关联的表或者自定义的字段需要返回使用）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("pinkundiaoyan")
public class PinkundiaoyanView  extends PinkundiaoyanEntity implements Serializable {
	private static final long serialVersionUID = 1L;

	public PinkundiaoyanView(){
	}
 
 	public PinkundiaoyanView(PinkundiaoyanEntity pinkundiaoyanEntity){
 	try {
			BeanUtils.copyProperties(this, pinkundiaoyanEntity);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		
	}
}

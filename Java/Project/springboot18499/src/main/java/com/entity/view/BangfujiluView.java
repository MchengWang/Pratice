package com.entity.view;

import com.entity.BangfujiluEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import org.apache.commons.beanutils.BeanUtils;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
 

/**
 * 帮扶与募捐记录
 * 后端返回视图实体辅助类   
 * （通常后端关联的表或者自定义的字段需要返回使用）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:52
 */
@TableName("bangfujilu")
public class BangfujiluView  extends BangfujiluEntity implements Serializable {
	private static final long serialVersionUID = 1L;

	public BangfujiluView(){
	}
 
 	public BangfujiluView(BangfujiluEntity bangfujiluEntity){
 	try {
			BeanUtils.copyProperties(this, bangfujiluEntity);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		
	}
}

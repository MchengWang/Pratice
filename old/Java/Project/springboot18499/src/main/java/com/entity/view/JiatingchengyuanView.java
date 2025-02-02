package com.entity.view;

import com.entity.JiatingchengyuanEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import org.apache.commons.beanutils.BeanUtils;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
 

/**
 * 家庭成员
 * 后端返回视图实体辅助类   
 * （通常后端关联的表或者自定义的字段需要返回使用）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("jiatingchengyuan")
public class JiatingchengyuanView  extends JiatingchengyuanEntity implements Serializable {
	private static final long serialVersionUID = 1L;

	public JiatingchengyuanView(){
	}
 
 	public JiatingchengyuanView(JiatingchengyuanEntity jiatingchengyuanEntity){
 	try {
			BeanUtils.copyProperties(this, jiatingchengyuanEntity);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		
	}
}

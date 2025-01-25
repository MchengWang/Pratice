package com.entity.vo;

import com.entity.BangfujieduiEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 帮扶结对
 * 手机端接口返回实体辅助类 
 * （主要作用去除一些不必要的字段）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public class BangfujieduiVO  implements Serializable {
	private static final long serialVersionUID = 1L;

	 			
	/**
	 * 户主姓名
	 */
	
	private String huzhuxingming;
		
	/**
	 * 结对人
	 */
	
	private String jieduiren;
		
	/**
	 * 结对时间
	 */
		
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
	@DateTimeFormat 
	private Date jieduishijian;
		
	/**
	 * 结对说明
	 */
	
	private String jieduishuoming;
				
	
	/**
	 * 设置：户主姓名
	 */
	 
	public void setHuzhuxingming(String huzhuxingming) {
		this.huzhuxingming = huzhuxingming;
	}
	
	/**
	 * 获取：户主姓名
	 */
	public String getHuzhuxingming() {
		return huzhuxingming;
	}
				
	
	/**
	 * 设置：结对人
	 */
	 
	public void setJieduiren(String jieduiren) {
		this.jieduiren = jieduiren;
	}
	
	/**
	 * 获取：结对人
	 */
	public String getJieduiren() {
		return jieduiren;
	}
				
	
	/**
	 * 设置：结对时间
	 */
	 
	public void setJieduishijian(Date jieduishijian) {
		this.jieduishijian = jieduishijian;
	}
	
	/**
	 * 获取：结对时间
	 */
	public Date getJieduishijian() {
		return jieduishijian;
	}
				
	
	/**
	 * 设置：结对说明
	 */
	 
	public void setJieduishuoming(String jieduishuoming) {
		this.jieduishuoming = jieduishuoming;
	}
	
	/**
	 * 获取：结对说明
	 */
	public String getJieduishuoming() {
		return jieduishuoming;
	}
			
}

package com.entity.model;

import com.entity.JiatingchengyuanEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 家庭成员
 * 接收传参的实体类  
 *（实际开发中配合移动端接口开发手动去掉些没用的字段， 后端一般用entity就够用了） 
 * 取自ModelAndView 的model名称
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public class JiatingchengyuanModel  implements Serializable {
	private static final long serialVersionUID = 1L;

	 			
	/**
	 * 户主姓名
	 */
	
	private String huzhuxingming;
		
	/**
	 * 家庭地址
	 */
	
	private String jiatingdizhi;
		
	/**
	 * 成员姓名
	 */
	
	private String chengyuanxingming;
		
	/**
	 * 成员性别
	 */
	
	private String chengyuanxingbie;
		
	/**
	 * 年龄
	 */
	
	private String nianling;
		
	/**
	 * 联系方式
	 */
	
	private String lianxifangshi;
		
	/**
	 * 工作
	 */
	
	private String gongzuo;
				
	
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
	 * 设置：家庭地址
	 */
	 
	public void setJiatingdizhi(String jiatingdizhi) {
		this.jiatingdizhi = jiatingdizhi;
	}
	
	/**
	 * 获取：家庭地址
	 */
	public String getJiatingdizhi() {
		return jiatingdizhi;
	}
				
	
	/**
	 * 设置：成员姓名
	 */
	 
	public void setChengyuanxingming(String chengyuanxingming) {
		this.chengyuanxingming = chengyuanxingming;
	}
	
	/**
	 * 获取：成员姓名
	 */
	public String getChengyuanxingming() {
		return chengyuanxingming;
	}
				
	
	/**
	 * 设置：成员性别
	 */
	 
	public void setChengyuanxingbie(String chengyuanxingbie) {
		this.chengyuanxingbie = chengyuanxingbie;
	}
	
	/**
	 * 获取：成员性别
	 */
	public String getChengyuanxingbie() {
		return chengyuanxingbie;
	}
				
	
	/**
	 * 设置：年龄
	 */
	 
	public void setNianling(String nianling) {
		this.nianling = nianling;
	}
	
	/**
	 * 获取：年龄
	 */
	public String getNianling() {
		return nianling;
	}
				
	
	/**
	 * 设置：联系方式
	 */
	 
	public void setLianxifangshi(String lianxifangshi) {
		this.lianxifangshi = lianxifangshi;
	}
	
	/**
	 * 获取：联系方式
	 */
	public String getLianxifangshi() {
		return lianxifangshi;
	}
				
	
	/**
	 * 设置：工作
	 */
	 
	public void setGongzuo(String gongzuo) {
		this.gongzuo = gongzuo;
	}
	
	/**
	 * 获取：工作
	 */
	public String getGongzuo() {
		return gongzuo;
	}
			
}

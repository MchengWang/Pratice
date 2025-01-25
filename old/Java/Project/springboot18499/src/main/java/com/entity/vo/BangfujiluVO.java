package com.entity.vo;

import com.entity.BangfujiluEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 帮扶与募捐记录
 * 手机端接口返回实体辅助类 
 * （主要作用去除一些不必要的字段）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:52
 */
public class BangfujiluVO  implements Serializable {
	private static final long serialVersionUID = 1L;

	 			
	/**
	 * 联系方式
	 */
	
	private String lianxifangshi;
		
	/**
	 * 帮扶政策
	 */
	
	private String bangfuzhengce;
		
	/**
	 * 记录时间
	 */
		
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
	@DateTimeFormat 
	private Date jilushijian;
		
	/**
	 * 帮扶进度
	 */
	
	private String bangfujindu;
		
	/**
	 * 地区名
	 */
	
	private String cunming;
		
	/**
	 * 户主姓名
	 */
	
	private String huzhuxingming;
				
	
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
	 * 设置：帮扶政策
	 */
	 
	public void setBangfuzhengce(String bangfuzhengce) {
		this.bangfuzhengce = bangfuzhengce;
	}
	
	/**
	 * 获取：帮扶政策
	 */
	public String getBangfuzhengce() {
		return bangfuzhengce;
	}
				
	
	/**
	 * 设置：记录时间
	 */
	 
	public void setJilushijian(Date jilushijian) {
		this.jilushijian = jilushijian;
	}
	
	/**
	 * 获取：记录时间
	 */
	public Date getJilushijian() {
		return jilushijian;
	}
				
	
	/**
	 * 设置：帮扶进度
	 */
	 
	public void setBangfujindu(String bangfujindu) {
		this.bangfujindu = bangfujindu;
	}
	
	/**
	 * 获取：帮扶进度
	 */
	public String getBangfujindu() {
		return bangfujindu;
	}
				
	
	/**
	 * 设置：地区名
	 */
	 
	public void setCunming(String cunming) {
		this.cunming = cunming;
	}
	
	/**
	 * 获取：地区名
	 */
	public String getCunming() {
		return cunming;
	}
				
	
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
			
}

package com.entity;

import com.baomidou.mybatisplus.annotations.TableId;
import com.baomidou.mybatisplus.annotations.TableName;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import java.lang.reflect.InvocationTargetException;

import java.io.Serializable;
import java.util.Date;
import java.util.List;

import org.springframework.format.annotation.DateTimeFormat;
import com.fasterxml.jackson.annotation.JsonFormat;
import org.apache.commons.beanutils.BeanUtils;
import com.baomidou.mybatisplus.annotations.TableField;
import com.baomidou.mybatisplus.enums.FieldFill;
import com.baomidou.mybatisplus.enums.IdType;


/**
 * 家庭成员
 * 数据库通用操作实体类（普通增删改查）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("jiatingchengyuan")
public class JiatingchengyuanEntity<T> implements Serializable {
	private static final long serialVersionUID = 1L;


	public JiatingchengyuanEntity() {
		
	}
	
	public JiatingchengyuanEntity(T t) {
		try {
			BeanUtils.copyProperties(this, t);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	/**
	 * 主键id
	 */
	@TableId
	private Long id;
	/**
	 * 地区名
	 */
					
	private String cunming;
	
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
	
	
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
	@DateTimeFormat
	private Date addtime;

	public Date getAddtime() {
		return addtime;
	}
	public void setAddtime(Date addtime) {
		this.addtime = addtime;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
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

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
 * 帮扶结对
 * 数据库通用操作实体类（普通增删改查）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("bangfujiedui")
public class BangfujieduiEntity<T> implements Serializable {
	private static final long serialVersionUID = 1L;


	public BangfujieduiEntity() {
		
	}
	
	public BangfujieduiEntity(T t) {
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

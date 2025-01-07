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
 * 帮扶与募捐记录
 * 数据库通用操作实体类（普通增删改查）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:52
 */
@TableName("bangfujilu")
public class BangfujiluEntity<T> implements Serializable {
	private static final long serialVersionUID = 1L;


	public BangfujiluEntity() {
		
	}
	
	public BangfujiluEntity(T t) {
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
	 * 帮扶负责人
	 */
					
	private String bangfufuzeren;
	
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
	 * 设置：帮扶负责人
	 */
	public void setBangfufuzeren(String bangfufuzeren) {
		this.bangfufuzeren = bangfufuzeren;
	}
	/**
	 * 获取：帮扶负责人
	 */
	public String getBangfufuzeren() {
		return bangfufuzeren;
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

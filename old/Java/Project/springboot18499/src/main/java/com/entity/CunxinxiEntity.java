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
 * 地区信息
 * 数据库通用操作实体类（普通增删改查）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("cunxinxi")
public class CunxinxiEntity<T> implements Serializable {
	private static final long serialVersionUID = 1L;


	public CunxinxiEntity() {
		
	}
	
	public CunxinxiEntity(T t) {
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
	 * 地区地址
	 */
					
	private String cundizhi;
	
	/**
	 * 贫困人数
	 */
					
	private String pinkunrenshu;
	
	/**
	 * 联系人
	 */
					
	private String lianxiren;
	
	/**
	 * 联系方式
	 */
					
	private String lianxifangshi;
	
	/**
	 * 地图
	 */
					
	private String ditu;
	
	
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
	 * 设置：地区地址
	 */
	public void setCundizhi(String cundizhi) {
		this.cundizhi = cundizhi;
	}
	/**
	 * 获取：地区地址
	 */
	public String getCundizhi() {
		return cundizhi;
	}
	/**
	 * 设置：贫困人数
	 */
	public void setPinkunrenshu(String pinkunrenshu) {
		this.pinkunrenshu = pinkunrenshu;
	}
	/**
	 * 获取：贫困人数
	 */
	public String getPinkunrenshu() {
		return pinkunrenshu;
	}
	/**
	 * 设置：联系人
	 */
	public void setLianxiren(String lianxiren) {
		this.lianxiren = lianxiren;
	}
	/**
	 * 获取：联系人
	 */
	public String getLianxiren() {
		return lianxiren;
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
	 * 设置：地图
	 */
	public void setDitu(String ditu) {
		this.ditu = ditu;
	}
	/**
	 * 获取：地图
	 */
	public String getDitu() {
		return ditu;
	}

}

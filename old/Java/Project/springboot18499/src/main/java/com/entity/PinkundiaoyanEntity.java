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
 * 孤寡与贫困户调研
 * 数据库通用操作实体类（普通增删改查）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("pinkundiaoyan")
public class PinkundiaoyanEntity<T> implements Serializable {
	private static final long serialVersionUID = 1L;


	public PinkundiaoyanEntity() {
		
	}
	
	public PinkundiaoyanEntity(T t) {
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
	 * 家庭人数
	 */
					
	private String jiatingrenshu;
	
	/**
	 * 调研时间
	 */
				
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd")
	@DateTimeFormat 		
	private Date diaoyanshijian;
	
	/**
	 * 调研人
	 */
					
	private String diaoyanren;
	
	/**
	 * 调研文件
	 */
					
	private String diaoyanwenjian;
	
	/**
	 * 调研内容
	 */
					
	private String diaoyanneirong;
	
	/**
	 * 跨表用户id
	 */
					
	private Long crossuserid;
	
	/**
	 * 跨表主键id
	 */
					
	private Long crossrefid;
	
	
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
	 * 设置：家庭人数
	 */
	public void setJiatingrenshu(String jiatingrenshu) {
		this.jiatingrenshu = jiatingrenshu;
	}
	/**
	 * 获取：家庭人数
	 */
	public String getJiatingrenshu() {
		return jiatingrenshu;
	}
	/**
	 * 设置：调研时间
	 */
	public void setDiaoyanshijian(Date diaoyanshijian) {
		this.diaoyanshijian = diaoyanshijian;
	}
	/**
	 * 获取：调研时间
	 */
	public Date getDiaoyanshijian() {
		return diaoyanshijian;
	}
	/**
	 * 设置：调研人
	 */
	public void setDiaoyanren(String diaoyanren) {
		this.diaoyanren = diaoyanren;
	}
	/**
	 * 获取：调研人
	 */
	public String getDiaoyanren() {
		return diaoyanren;
	}
	/**
	 * 设置：调研文件
	 */
	public void setDiaoyanwenjian(String diaoyanwenjian) {
		this.diaoyanwenjian = diaoyanwenjian;
	}
	/**
	 * 获取：调研文件
	 */
	public String getDiaoyanwenjian() {
		return diaoyanwenjian;
	}
	/**
	 * 设置：调研内容
	 */
	public void setDiaoyanneirong(String diaoyanneirong) {
		this.diaoyanneirong = diaoyanneirong;
	}
	/**
	 * 获取：调研内容
	 */
	public String getDiaoyanneirong() {
		return diaoyanneirong;
	}
	/**
	 * 设置：跨表用户id
	 */
	public void setCrossuserid(Long crossuserid) {
		this.crossuserid = crossuserid;
	}
	/**
	 * 获取：跨表用户id
	 */
	public Long getCrossuserid() {
		return crossuserid;
	}
	/**
	 * 设置：跨表主键id
	 */
	public void setCrossrefid(Long crossrefid) {
		this.crossrefid = crossrefid;
	}
	/**
	 * 获取：跨表主键id
	 */
	public Long getCrossrefid() {
		return crossrefid;
	}

}

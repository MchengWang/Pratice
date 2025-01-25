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
 * 孤寡与贫困户
 * 数据库通用操作实体类（普通增删改查）
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@TableName("pinkunhu")
public class PinkunhuEntity<T> implements Serializable {
	private static final long serialVersionUID = 1L;


	public PinkunhuEntity() {
		
	}
	
	public PinkunhuEntity(T t) {
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
					
	private Integer jiatingrenshu;
	
	/**
	 * 贫困状况
	 */
					
	private String pinkunzhuangkuang;
	
	/**
	 * 人均收入
	 */
					
	private Float renjunshouru;
	
	/**
	 * 家庭支出
	 */
					
	private String jiatingzhichu;
	
	/**
	 * 致贫原因
	 */
					
	private String zhipinyuanyin;
	
	/**
	 * 致贫说明
	 */
					
	private String zhipinshuoming;
	
	/**
	 * 登记时间
	 */
				
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd")
	@DateTimeFormat 		
	private Date dengjishijian;
	
	
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
	public void setJiatingrenshu(Integer jiatingrenshu) {
		this.jiatingrenshu = jiatingrenshu;
	}
	/**
	 * 获取：家庭人数
	 */
	public Integer getJiatingrenshu() {
		return jiatingrenshu;
	}
	/**
	 * 设置：贫困状况
	 */
	public void setPinkunzhuangkuang(String pinkunzhuangkuang) {
		this.pinkunzhuangkuang = pinkunzhuangkuang;
	}
	/**
	 * 获取：贫困状况
	 */
	public String getPinkunzhuangkuang() {
		return pinkunzhuangkuang;
	}
	/**
	 * 设置：人均收入
	 */
	public void setRenjunshouru(Float renjunshouru) {
		this.renjunshouru = renjunshouru;
	}
	/**
	 * 获取：人均收入
	 */
	public Float getRenjunshouru() {
		return renjunshouru;
	}
	/**
	 * 设置：家庭支出
	 */
	public void setJiatingzhichu(String jiatingzhichu) {
		this.jiatingzhichu = jiatingzhichu;
	}
	/**
	 * 获取：家庭支出
	 */
	public String getJiatingzhichu() {
		return jiatingzhichu;
	}
	/**
	 * 设置：致贫原因
	 */
	public void setZhipinyuanyin(String zhipinyuanyin) {
		this.zhipinyuanyin = zhipinyuanyin;
	}
	/**
	 * 获取：致贫原因
	 */
	public String getZhipinyuanyin() {
		return zhipinyuanyin;
	}
	/**
	 * 设置：致贫说明
	 */
	public void setZhipinshuoming(String zhipinshuoming) {
		this.zhipinshuoming = zhipinshuoming;
	}
	/**
	 * 获取：致贫说明
	 */
	public String getZhipinshuoming() {
		return zhipinshuoming;
	}
	/**
	 * 设置：登记时间
	 */
	public void setDengjishijian(Date dengjishijian) {
		this.dengjishijian = dengjishijian;
	}
	/**
	 * 获取：登记时间
	 */
	public Date getDengjishijian() {
		return dengjishijian;
	}

}

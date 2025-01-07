package com.entity.model;

import com.entity.PinkunhuEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 孤寡与贫困户
 * 接收传参的实体类  
 *（实际开发中配合移动端接口开发手动去掉些没用的字段， 后端一般用entity就够用了） 
 * 取自ModelAndView 的model名称
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public class PinkunhuModel  implements Serializable {
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
		
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
	@DateTimeFormat 
	private Date dengjishijian;
				
	
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

package com.entity.model;

import com.entity.PinkundiaoyanEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 孤寡与贫困户调研
 * 接收传参的实体类  
 *（实际开发中配合移动端接口开发手动去掉些没用的字段， 后端一般用entity就够用了） 
 * 取自ModelAndView 的model名称
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
public class PinkundiaoyanModel  implements Serializable {
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
	
	private String jiatingrenshu;
		
	/**
	 * 调研时间
	 */
		
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
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

package com.entity.model;

import com.entity.WeixiuEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 维修
 * 接收传参的实体类  
 *（实际开发中配合移动端接口开发手动去掉些没用的字段， 后端一般用entity就够用了） 
 * 取自ModelAndView 的model名称
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public class WeixiuModel  implements Serializable {
	private static final long serialVersionUID = 1L;

	 			
	/**
	 * 学号
	 */
	
	private String xuehao;
		
	/**
	 * 宿舍号
	 */
	
	private String sushehao;
		
	/**
	 * 宿管账号
	 */
	
	private String suguanzhanghao;
		
	/**
	 * 宿管姓名
	 */
	
	private String suguanxingming;
		
	/**
	 * 维修需求
	 */
	
	private String weixiuxuqiu;
		
	/**
	 * 设施图片
	 */
	
	private String sheshitupian;
		
	/**
	 * 设施维修原因
	 */
	
	private String sheshiweixiuyuanyin;
		
	/**
	 * 申请维修时间
	 */
		
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
	@DateTimeFormat 
	private Date shenqingweixiushijian;
		
	/**
	 * 维修状态
	 */
	
	private String weixiuzhuangtai;
		
	/**
	 * 是否审核
	 */
	
	private String sfsh;
		
	/**
	 * 审核回复
	 */
	
	private String shhf;
				
	
	/**
	 * 设置：学号
	 */
	 
	public void setXuehao(String xuehao) {
		this.xuehao = xuehao;
	}
	
	/**
	 * 获取：学号
	 */
	public String getXuehao() {
		return xuehao;
	}
				
	
	/**
	 * 设置：宿舍号
	 */
	 
	public void setSushehao(String sushehao) {
		this.sushehao = sushehao;
	}
	
	/**
	 * 获取：宿舍号
	 */
	public String getSushehao() {
		return sushehao;
	}
				
	
	/**
	 * 设置：宿管账号
	 */
	 
	public void setSuguanzhanghao(String suguanzhanghao) {
		this.suguanzhanghao = suguanzhanghao;
	}
	
	/**
	 * 获取：宿管账号
	 */
	public String getSuguanzhanghao() {
		return suguanzhanghao;
	}
				
	
	/**
	 * 设置：宿管姓名
	 */
	 
	public void setSuguanxingming(String suguanxingming) {
		this.suguanxingming = suguanxingming;
	}
	
	/**
	 * 获取：宿管姓名
	 */
	public String getSuguanxingming() {
		return suguanxingming;
	}
				
	
	/**
	 * 设置：维修需求
	 */
	 
	public void setWeixiuxuqiu(String weixiuxuqiu) {
		this.weixiuxuqiu = weixiuxuqiu;
	}
	
	/**
	 * 获取：维修需求
	 */
	public String getWeixiuxuqiu() {
		return weixiuxuqiu;
	}
				
	
	/**
	 * 设置：设施图片
	 */
	 
	public void setSheshitupian(String sheshitupian) {
		this.sheshitupian = sheshitupian;
	}
	
	/**
	 * 获取：设施图片
	 */
	public String getSheshitupian() {
		return sheshitupian;
	}
				
	
	/**
	 * 设置：设施维修原因
	 */
	 
	public void setSheshiweixiuyuanyin(String sheshiweixiuyuanyin) {
		this.sheshiweixiuyuanyin = sheshiweixiuyuanyin;
	}
	
	/**
	 * 获取：设施维修原因
	 */
	public String getSheshiweixiuyuanyin() {
		return sheshiweixiuyuanyin;
	}
				
	
	/**
	 * 设置：申请维修时间
	 */
	 
	public void setShenqingweixiushijian(Date shenqingweixiushijian) {
		this.shenqingweixiushijian = shenqingweixiushijian;
	}
	
	/**
	 * 获取：申请维修时间
	 */
	public Date getShenqingweixiushijian() {
		return shenqingweixiushijian;
	}
				
	
	/**
	 * 设置：维修状态
	 */
	 
	public void setWeixiuzhuangtai(String weixiuzhuangtai) {
		this.weixiuzhuangtai = weixiuzhuangtai;
	}
	
	/**
	 * 获取：维修状态
	 */
	public String getWeixiuzhuangtai() {
		return weixiuzhuangtai;
	}
				
	
	/**
	 * 设置：是否审核
	 */
	 
	public void setSfsh(String sfsh) {
		this.sfsh = sfsh;
	}
	
	/**
	 * 获取：是否审核
	 */
	public String getSfsh() {
		return sfsh;
	}
				
	
	/**
	 * 设置：审核回复
	 */
	 
	public void setShhf(String shhf) {
		this.shhf = shhf;
	}
	
	/**
	 * 获取：审核回复
	 */
	public String getShhf() {
		return shhf;
	}
			
}

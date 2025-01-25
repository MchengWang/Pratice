package com.entity.vo;

import com.entity.WeishengtongjiEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 卫生统计
 * 手机端接口返回实体辅助类 
 * （主要作用去除一些不必要的字段）
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public class WeishengtongjiVO  implements Serializable {
	private static final long serialVersionUID = 1L;

	 			
	/**
	 * 统计类型
	 */
	
	private String tongjileixing;
		
	/**
	 * 学期
	 */
	
	private String xueqi;
		
	/**
	 * 月份
	 */
	
	private String yuefen;
		
	/**
	 * 宿舍号
	 */
	
	private String sushehao;
		
	/**
	 * 宿舍类型
	 */
	
	private String susheleixing;
		
	/**
	 * 清扫次数
	 */
	
	private String qingsaocishu;
		
	/**
	 * 宿舍排名
	 */
	
	private String sushepaiming;
		
	/**
	 * 登记日期
	 */
		
	@JsonFormat(locale="zh", timezone="GMT+8", pattern="yyyy-MM-dd HH:mm:ss")
	@DateTimeFormat 
	private Date dengjiriqi;
		
	/**
	 * 宿管账号
	 */
	
	private String suguanzhanghao;
		
	/**
	 * 宿管姓名
	 */
	
	private String suguanxingming;
				
	
	/**
	 * 设置：统计类型
	 */
	 
	public void setTongjileixing(String tongjileixing) {
		this.tongjileixing = tongjileixing;
	}
	
	/**
	 * 获取：统计类型
	 */
	public String getTongjileixing() {
		return tongjileixing;
	}
				
	
	/**
	 * 设置：学期
	 */
	 
	public void setXueqi(String xueqi) {
		this.xueqi = xueqi;
	}
	
	/**
	 * 获取：学期
	 */
	public String getXueqi() {
		return xueqi;
	}
				
	
	/**
	 * 设置：月份
	 */
	 
	public void setYuefen(String yuefen) {
		this.yuefen = yuefen;
	}
	
	/**
	 * 获取：月份
	 */
	public String getYuefen() {
		return yuefen;
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
	 * 设置：宿舍类型
	 */
	 
	public void setSusheleixing(String susheleixing) {
		this.susheleixing = susheleixing;
	}
	
	/**
	 * 获取：宿舍类型
	 */
	public String getSusheleixing() {
		return susheleixing;
	}
				
	
	/**
	 * 设置：清扫次数
	 */
	 
	public void setQingsaocishu(String qingsaocishu) {
		this.qingsaocishu = qingsaocishu;
	}
	
	/**
	 * 获取：清扫次数
	 */
	public String getQingsaocishu() {
		return qingsaocishu;
	}
				
	
	/**
	 * 设置：宿舍排名
	 */
	 
	public void setSushepaiming(String sushepaiming) {
		this.sushepaiming = sushepaiming;
	}
	
	/**
	 * 获取：宿舍排名
	 */
	public String getSushepaiming() {
		return sushepaiming;
	}
				
	
	/**
	 * 设置：登记日期
	 */
	 
	public void setDengjiriqi(Date dengjiriqi) {
		this.dengjiriqi = dengjiriqi;
	}
	
	/**
	 * 获取：登记日期
	 */
	public Date getDengjiriqi() {
		return dengjiriqi;
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
			
}

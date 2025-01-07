package com.entity.model;

import com.entity.MenjinxinxiEntity;

import com.baomidou.mybatisplus.annotations.TableName;
import java.util.Date;
import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.io.Serializable;
 

/**
 * 门禁信息
 * 接收传参的实体类  
 *（实际开发中配合移动端接口开发手动去掉些没用的字段， 后端一般用entity就够用了） 
 * 取自ModelAndView 的model名称
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
public class MenjinxinxiModel  implements Serializable {
	private static final long serialVersionUID = 1L;

	 			
	/**
	 * 学生姓名
	 */
	
	private String xueshengxingming;
		
	/**
	 * 门禁卡号
	 */
	
	private String menjinkahao;
		
	/**
	 * 统计类型
	 */
	
	private String tongjileixing;
		
	/**
	 * 月份
	 */
	
	private String yuefen;
		
	/**
	 * 学期
	 */
	
	private String xueqi;
		
	/**
	 * 进出次数
	 */
	
	private String jinchucishu;
		
	/**
	 * 备注
	 */
	
	private String beizhu;
		
	/**
	 * 宿管账号
	 */
	
	private String suguanzhanghao;
		
	/**
	 * 宿管姓名
	 */
	
	private String suguanxingming;
				
	
	/**
	 * 设置：学生姓名
	 */
	 
	public void setXueshengxingming(String xueshengxingming) {
		this.xueshengxingming = xueshengxingming;
	}
	
	/**
	 * 获取：学生姓名
	 */
	public String getXueshengxingming() {
		return xueshengxingming;
	}
				
	
	/**
	 * 设置：门禁卡号
	 */
	 
	public void setMenjinkahao(String menjinkahao) {
		this.menjinkahao = menjinkahao;
	}
	
	/**
	 * 获取：门禁卡号
	 */
	public String getMenjinkahao() {
		return menjinkahao;
	}
				
	
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
	 * 设置：进出次数
	 */
	 
	public void setJinchucishu(String jinchucishu) {
		this.jinchucishu = jinchucishu;
	}
	
	/**
	 * 获取：进出次数
	 */
	public String getJinchucishu() {
		return jinchucishu;
	}
				
	
	/**
	 * 设置：备注
	 */
	 
	public void setBeizhu(String beizhu) {
		this.beizhu = beizhu;
	}
	
	/**
	 * 获取：备注
	 */
	public String getBeizhu() {
		return beizhu;
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

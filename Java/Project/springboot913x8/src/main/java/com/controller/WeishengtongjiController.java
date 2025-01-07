package com.controller;

import java.math.BigDecimal;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Date;
import java.util.List;
import javax.servlet.http.HttpServletRequest;

import com.utils.ValidatorUtils;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import com.baomidou.mybatisplus.mapper.EntityWrapper;
import com.baomidou.mybatisplus.mapper.Wrapper;
import com.annotation.IgnoreAuth;

import com.entity.WeishengtongjiEntity;
import com.entity.view.WeishengtongjiView;

import com.service.WeishengtongjiService;
import com.service.TokenService;
import com.utils.PageUtils;
import com.utils.R;
import com.utils.MD5Util;
import com.utils.MPUtil;
import com.utils.CommonUtil;
import java.io.IOException;

/**
 * 卫生统计
 * 后端接口
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
@RestController
@RequestMapping("/weishengtongji")
public class WeishengtongjiController {
    @Autowired
    private WeishengtongjiService weishengtongjiService;


    


    /**
     * 后端列表
     */
    @RequestMapping("/page")
    public R page(@RequestParam Map<String, Object> params,WeishengtongjiEntity weishengtongji,
		HttpServletRequest request){
		String tableName = request.getSession().getAttribute("tableName").toString();
		if(tableName.equals("susheguanliyuan")) {
			weishengtongji.setSuguanzhanghao((String)request.getSession().getAttribute("username"));
		}
        EntityWrapper<WeishengtongjiEntity> ew = new EntityWrapper<WeishengtongjiEntity>();

		PageUtils page = weishengtongjiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, weishengtongji), params), params));

        return R.ok().put("data", page);
    }
    
    /**
     * 前端列表
     */
	@IgnoreAuth
    @RequestMapping("/list")
    public R list(@RequestParam Map<String, Object> params,WeishengtongjiEntity weishengtongji, 
		HttpServletRequest request){
        EntityWrapper<WeishengtongjiEntity> ew = new EntityWrapper<WeishengtongjiEntity>();

		PageUtils page = weishengtongjiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, weishengtongji), params), params));
        return R.ok().put("data", page);
    }

	/**
     * 列表
     */
    @RequestMapping("/lists")
    public R list( WeishengtongjiEntity weishengtongji){
       	EntityWrapper<WeishengtongjiEntity> ew = new EntityWrapper<WeishengtongjiEntity>();
      	ew.allEq(MPUtil.allEQMapPre( weishengtongji, "weishengtongji")); 
        return R.ok().put("data", weishengtongjiService.selectListView(ew));
    }

	 /**
     * 查询
     */
    @RequestMapping("/query")
    public R query(WeishengtongjiEntity weishengtongji){
        EntityWrapper< WeishengtongjiEntity> ew = new EntityWrapper< WeishengtongjiEntity>();
 		ew.allEq(MPUtil.allEQMapPre( weishengtongji, "weishengtongji")); 
		WeishengtongjiView weishengtongjiView =  weishengtongjiService.selectView(ew);
		return R.ok("查询卫生统计成功").put("data", weishengtongjiView);
    }
	
    /**
     * 后端详情
     */
    @RequestMapping("/info/{id}")
    public R info(@PathVariable("id") Long id){
        WeishengtongjiEntity weishengtongji = weishengtongjiService.selectById(id);
        return R.ok().put("data", weishengtongji);
    }

    /**
     * 前端详情
     */
	@IgnoreAuth
    @RequestMapping("/detail/{id}")
    public R detail(@PathVariable("id") Long id){
        WeishengtongjiEntity weishengtongji = weishengtongjiService.selectById(id);
        return R.ok().put("data", weishengtongji);
    }
    



    /**
     * 后端保存
     */
    @RequestMapping("/save")
    public R save(@RequestBody WeishengtongjiEntity weishengtongji, HttpServletRequest request){
    	weishengtongji.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(weishengtongji);
        weishengtongjiService.insert(weishengtongji);
        return R.ok();
    }
    
    /**
     * 前端保存
     */
    @RequestMapping("/add")
    public R add(@RequestBody WeishengtongjiEntity weishengtongji, HttpServletRequest request){
    	weishengtongji.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(weishengtongji);
        weishengtongjiService.insert(weishengtongji);
        return R.ok();
    }



    /**
     * 修改
     */
    @RequestMapping("/update")
    @Transactional
    public R update(@RequestBody WeishengtongjiEntity weishengtongji, HttpServletRequest request){
        //ValidatorUtils.validateEntity(weishengtongji);
        weishengtongjiService.updateById(weishengtongji);//全部更新
        return R.ok();
    }



    

    /**
     * 删除
     */
    @RequestMapping("/delete")
    public R delete(@RequestBody Long[] ids){
        weishengtongjiService.deleteBatchIds(Arrays.asList(ids));
        return R.ok();
    }
    
	









}

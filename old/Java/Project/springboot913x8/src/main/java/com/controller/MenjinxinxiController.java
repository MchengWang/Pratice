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

import com.entity.MenjinxinxiEntity;
import com.entity.view.MenjinxinxiView;

import com.service.MenjinxinxiService;
import com.service.TokenService;
import com.utils.PageUtils;
import com.utils.R;
import com.utils.MD5Util;
import com.utils.MPUtil;
import com.utils.CommonUtil;
import java.io.IOException;

/**
 * 门禁信息
 * 后端接口
 * @author 
 * @email 
 * @date 2030-05-30 20:23:47
 */
@RestController
@RequestMapping("/menjinxinxi")
public class MenjinxinxiController {
    @Autowired
    private MenjinxinxiService menjinxinxiService;


    


    /**
     * 后端列表
     */
    @RequestMapping("/page")
    public R page(@RequestParam Map<String, Object> params,MenjinxinxiEntity menjinxinxi,
		HttpServletRequest request){
		String tableName = request.getSession().getAttribute("tableName").toString();
		if(tableName.equals("xuesheng")) {
			menjinxinxi.setXuehao((String)request.getSession().getAttribute("username"));
		}
        EntityWrapper<MenjinxinxiEntity> ew = new EntityWrapper<MenjinxinxiEntity>();

		PageUtils page = menjinxinxiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, menjinxinxi), params), params));

        return R.ok().put("data", page);
    }
    
    /**
     * 前端列表
     */
	@IgnoreAuth
    @RequestMapping("/list")
    public R list(@RequestParam Map<String, Object> params,MenjinxinxiEntity menjinxinxi, 
		HttpServletRequest request){
        EntityWrapper<MenjinxinxiEntity> ew = new EntityWrapper<MenjinxinxiEntity>();

		PageUtils page = menjinxinxiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, menjinxinxi), params), params));
        return R.ok().put("data", page);
    }

	/**
     * 列表
     */
    @RequestMapping("/lists")
    public R list( MenjinxinxiEntity menjinxinxi){
       	EntityWrapper<MenjinxinxiEntity> ew = new EntityWrapper<MenjinxinxiEntity>();
      	ew.allEq(MPUtil.allEQMapPre( menjinxinxi, "menjinxinxi")); 
        return R.ok().put("data", menjinxinxiService.selectListView(ew));
    }

	 /**
     * 查询
     */
    @RequestMapping("/query")
    public R query(MenjinxinxiEntity menjinxinxi){
        EntityWrapper< MenjinxinxiEntity> ew = new EntityWrapper< MenjinxinxiEntity>();
 		ew.allEq(MPUtil.allEQMapPre( menjinxinxi, "menjinxinxi")); 
		MenjinxinxiView menjinxinxiView =  menjinxinxiService.selectView(ew);
		return R.ok("查询门禁信息成功").put("data", menjinxinxiView);
    }
	
    /**
     * 后端详情
     */
    @RequestMapping("/info/{id}")
    public R info(@PathVariable("id") Long id){
        MenjinxinxiEntity menjinxinxi = menjinxinxiService.selectById(id);
        return R.ok().put("data", menjinxinxi);
    }

    /**
     * 前端详情
     */
	@IgnoreAuth
    @RequestMapping("/detail/{id}")
    public R detail(@PathVariable("id") Long id){
        MenjinxinxiEntity menjinxinxi = menjinxinxiService.selectById(id);
        return R.ok().put("data", menjinxinxi);
    }
    



    /**
     * 后端保存
     */
    @RequestMapping("/save")
    public R save(@RequestBody MenjinxinxiEntity menjinxinxi, HttpServletRequest request){
    	menjinxinxi.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(menjinxinxi);
        menjinxinxiService.insert(menjinxinxi);
        return R.ok();
    }
    
    /**
     * 前端保存
     */
    @RequestMapping("/add")
    public R add(@RequestBody MenjinxinxiEntity menjinxinxi, HttpServletRequest request){
    	menjinxinxi.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(menjinxinxi);
        menjinxinxiService.insert(menjinxinxi);
        return R.ok();
    }



    /**
     * 修改
     */
    @RequestMapping("/update")
    @Transactional
    public R update(@RequestBody MenjinxinxiEntity menjinxinxi, HttpServletRequest request){
        //ValidatorUtils.validateEntity(menjinxinxi);
        menjinxinxiService.updateById(menjinxinxi);//全部更新
        return R.ok();
    }



    

    /**
     * 删除
     */
    @RequestMapping("/delete")
    public R delete(@RequestBody Long[] ids){
        menjinxinxiService.deleteBatchIds(Arrays.asList(ids));
        return R.ok();
    }
    
	









}

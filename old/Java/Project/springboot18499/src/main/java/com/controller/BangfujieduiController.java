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

import com.entity.BangfujieduiEntity;
import com.entity.view.BangfujieduiView;

import com.service.BangfujieduiService;
import com.service.TokenService;
import com.utils.PageUtils;
import com.utils.R;
import com.utils.MD5Util;
import com.utils.MPUtil;
import com.utils.CommonUtil;
import java.io.IOException;

/**
 * 帮扶结对
 * 后端接口
 * @author 
 * @email 
 * @date 2030-03-31 17:44:51
 */
@RestController
@RequestMapping("/bangfujiedui")
public class BangfujieduiController {
    @Autowired
    private BangfujieduiService bangfujieduiService;


    


    /**
     * 后端列表
     */
    @RequestMapping("/page")
    public R page(@RequestParam Map<String, Object> params,BangfujieduiEntity bangfujiedui,
		HttpServletRequest request){
        EntityWrapper<BangfujieduiEntity> ew = new EntityWrapper<BangfujieduiEntity>();

		PageUtils page = bangfujieduiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, bangfujiedui), params), params));

        return R.ok().put("data", page);
    }
    
    /**
     * 前端列表
     */
	@IgnoreAuth
    @RequestMapping("/list")
    public R list(@RequestParam Map<String, Object> params,BangfujieduiEntity bangfujiedui, 
		HttpServletRequest request){
        EntityWrapper<BangfujieduiEntity> ew = new EntityWrapper<BangfujieduiEntity>();

		PageUtils page = bangfujieduiService.queryPage(params, MPUtil.sort(MPUtil.between(MPUtil.likeOrEq(ew, bangfujiedui), params), params));
        return R.ok().put("data", page);
    }

	/**
     * 列表
     */
    @RequestMapping("/lists")
    public R list( BangfujieduiEntity bangfujiedui){
       	EntityWrapper<BangfujieduiEntity> ew = new EntityWrapper<BangfujieduiEntity>();
      	ew.allEq(MPUtil.allEQMapPre( bangfujiedui, "bangfujiedui")); 
        return R.ok().put("data", bangfujieduiService.selectListView(ew));
    }

	 /**
     * 查询
     */
    @RequestMapping("/query")
    public R query(BangfujieduiEntity bangfujiedui){
        EntityWrapper< BangfujieduiEntity> ew = new EntityWrapper< BangfujieduiEntity>();
 		ew.allEq(MPUtil.allEQMapPre( bangfujiedui, "bangfujiedui")); 
		BangfujieduiView bangfujieduiView =  bangfujieduiService.selectView(ew);
		return R.ok("查询帮扶结对成功").put("data", bangfujieduiView);
    }
	
    /**
     * 后端详情
     */
    @RequestMapping("/info/{id}")
    public R info(@PathVariable("id") Long id){
        BangfujieduiEntity bangfujiedui = bangfujieduiService.selectById(id);
        return R.ok().put("data", bangfujiedui);
    }

    /**
     * 前端详情
     */
	@IgnoreAuth
    @RequestMapping("/detail/{id}")
    public R detail(@PathVariable("id") Long id){
        BangfujieduiEntity bangfujiedui = bangfujieduiService.selectById(id);
        return R.ok().put("data", bangfujiedui);
    }
    



    /**
     * 后端保存
     */
    @RequestMapping("/save")
    public R save(@RequestBody BangfujieduiEntity bangfujiedui, HttpServletRequest request){
    	bangfujiedui.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(bangfujiedui);
        bangfujieduiService.insert(bangfujiedui);
        return R.ok();
    }
    
    /**
     * 前端保存
     */
    @RequestMapping("/add")
    public R add(@RequestBody BangfujieduiEntity bangfujiedui, HttpServletRequest request){
    	bangfujiedui.setId(new Date().getTime()+new Double(Math.floor(Math.random()*1000)).longValue());
    	//ValidatorUtils.validateEntity(bangfujiedui);
        bangfujieduiService.insert(bangfujiedui);
        return R.ok();
    }



    /**
     * 修改
     */
    @RequestMapping("/update")
    @Transactional
    public R update(@RequestBody BangfujieduiEntity bangfujiedui, HttpServletRequest request){
        //ValidatorUtils.validateEntity(bangfujiedui);
        bangfujieduiService.updateById(bangfujiedui);//全部更新
        return R.ok();
    }


    

    /**
     * 删除
     */
    @RequestMapping("/delete")
    public R delete(@RequestBody Long[] ids){
        bangfujieduiService.deleteBatchIds(Arrays.asList(ids));
        return R.ok();
    }
    
    /**
     * 提醒接口
     */
	@RequestMapping("/remind/{columnName}/{type}")
	public R remindCount(@PathVariable("columnName") String columnName, HttpServletRequest request, 
						 @PathVariable("type") String type,@RequestParam Map<String, Object> map) {
		map.put("column", columnName);
		map.put("type", type);
		
		if(type.equals("2")) {
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
			Calendar c = Calendar.getInstance();
			Date remindStartDate = null;
			Date remindEndDate = null;
			if(map.get("remindstart")!=null) {
				Integer remindStart = Integer.parseInt(map.get("remindstart").toString());
				c.setTime(new Date()); 
				c.add(Calendar.DAY_OF_MONTH,remindStart);
				remindStartDate = c.getTime();
				map.put("remindstart", sdf.format(remindStartDate));
			}
			if(map.get("remindend")!=null) {
				Integer remindEnd = Integer.parseInt(map.get("remindend").toString());
				c.setTime(new Date());
				c.add(Calendar.DAY_OF_MONTH,remindEnd);
				remindEndDate = c.getTime();
				map.put("remindend", sdf.format(remindEndDate));
			}
		}
		
		Wrapper<BangfujieduiEntity> wrapper = new EntityWrapper<BangfujieduiEntity>();
		if(map.get("remindstart")!=null) {
			wrapper.ge(columnName, map.get("remindstart"));
		}
		if(map.get("remindend")!=null) {
			wrapper.le(columnName, map.get("remindend"));
		}


		int count = bangfujieduiService.selectCount(wrapper);
		return R.ok().put("count", count);
	}
	









}

package com.household.controller;

import com.household.pojo.HouseHoldInfo;
import com.household.service.HouseHoldInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@Controller
@RequestMapping
public class HouseHoldInfoController {

    @Autowired
    private HouseHoldInfoService houseHoldInfoService;

    @RequestMapping("/insert")
    public String save(HouseHoldInfo houseHoldInfo) {
        houseHoldInfoService.save(houseHoldInfo);
        return "index";
    }

    @RequestMapping("/del")
    public String delete(int id) {
        houseHoldInfoService.delete(id);
        return "index";
    }

    @RequestMapping("/update")
    public String update(HouseHoldInfo houseHoldInfo) {
        houseHoldInfoService.update(houseHoldInfo);
        return "index";
    }

    @RequestMapping("/getOnce")
    public ModelAndView getById(int id) {
        HouseHoldInfo once = houseHoldInfoService.getById(id);
//        System.out.println(once);
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/page/udHouseInfo.jsp");
        mav.addObject("once" , once);
        return mav;
    }

    @RequestMapping("/index")
    public ModelAndView getAll() {
        List<HouseHoldInfo> all = houseHoldInfoService.getAll();
        ModelAndView mav = new ModelAndView();
        mav.addObject("list" , all);
        mav.setViewName("index.jsp");
        return mav;
    }

    @RequestMapping("/add")
    public ModelAndView add(){
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/page/insert.jsp");
        return mav;
    }
}

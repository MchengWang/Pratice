package org.phone.controller;

import org.phone.pojo.MobileInfo;
import org.phone.service.MobileInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@Controller
@RequestMapping
public class MobileInfoController {

    @Autowired
    private MobileInfoService mobileInfoService;

    @RequestMapping("/insert")
    public String save(MobileInfo mobileInfo) {
        mobileInfoService.save(mobileInfo);
        return "index";
    }

    @RequestMapping("/del")
    public String delete(int id) {
        mobileInfoService.delete(id);
        return "index";
    }

    @RequestMapping("/update")
    public String update(MobileInfo mobileInfo) {
        mobileInfoService.update(mobileInfo);
        return "index";
    }

    @RequestMapping("/getOnce")
    public ModelAndView getById(int id) {
        MobileInfo once = mobileInfoService.getById(id);
//        System.out.println(once);
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/pages/updateMobiles.jsp");
        mav.addObject("once" , once);
        return mav;
    }

    @RequestMapping("/index")
    public ModelAndView getAll() {
        List<MobileInfo> all = mobileInfoService.getAll();
        ModelAndView mav = new ModelAndView();
        mav.addObject("list" , all);
        mav.setViewName("index.jsp");
        return mav;
    }

    @RequestMapping("/add")
    public ModelAndView add(){
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/pages/addMobile.jsp");
        return mav;
    }
}

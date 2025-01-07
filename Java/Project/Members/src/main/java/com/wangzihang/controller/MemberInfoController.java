package com.wangzihang.controller;


import com.wangzihang.dao.MemberInfoDao;
import com.wangzihang.pojo.MemberInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@Controller
@RequestMapping
public class MemberInfoController {

    @Autowired
    private MemberInfoDao roomsService;

    @RequestMapping("/insert")
    public String save(MemberInfo memberInfo) {
        roomsService.insertRooms(memberInfo);
        return "index";
    }

    @RequestMapping("/del")
    public String delete(int id) {
        roomsService.delete(id);
        return "index";
    }

    @RequestMapping("/update")
    public String update(MemberInfo memberInfo) {
        roomsService.update(memberInfo);
        return "index";
    }

    @RequestMapping("/getOnce")
    public ModelAndView getById(int id) {
        MemberInfo once = roomsService.selectById(id);
//        System.out.println(once);
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/pages/modifyMe.jsp");
        mav.addObject("once" , once);
        return mav;
    }

    @RequestMapping("/index")
    public ModelAndView getAll() {
        List<MemberInfo> rooms = roomsService.getAll();
//        System.out.println(rooms);
        ModelAndView mav = new ModelAndView();
        mav.addObject("list" , rooms);
        mav.setViewName("index.jsp");
        return mav;
    }

    @RequestMapping("/add")
    public ModelAndView add(){
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/pages/addMe.jsp");
        return mav;
    }
}

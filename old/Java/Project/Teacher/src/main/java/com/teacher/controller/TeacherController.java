package com.teacher.controller;

import com.teacher.service.TeacherService;
import com.teacher.pojo.TeacherInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@Controller
@RequestMapping
public class TeacherController {

    @Autowired
    private TeacherService teacherService;

    @RequestMapping("/insertMessage")
    public String save(TeacherInfo teacherInfo) {
        teacherService.save(teacherInfo);
        return "index";
    }

    @RequestMapping("/delTeacher")
    public String delete(int id) {
        teacherService.delete(id);
        return "index";
    }

    @RequestMapping("/updateTeacher")
    public String update(TeacherInfo teacherInfo) {
        teacherService.update(teacherInfo);
        return "index";
    }

    @RequestMapping("/getTeacher")
    public ModelAndView getById(int id) {
        TeacherInfo once = teacherService.getById(id);
//        System.out.println(once);
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/pages/updTeacherMessage.jsp");
        mav.addObject("one" , once);
        return mav;
    }

    @RequestMapping("/index")
    public ModelAndView getAll() {
        List<TeacherInfo> all = teacherService.getAll();
        ModelAndView mav = new ModelAndView();
        mav.addObject("list" , all);
        mav.setViewName("index.jsp");
        return mav;
    }

    @RequestMapping("/add")
    public ModelAndView add(){
        ModelAndView mav = new ModelAndView();
        mav.setViewName("/pages/addTeacherMessage.jsp");
        return mav;
    }
}

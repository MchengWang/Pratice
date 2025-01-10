package hnzj.edu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import hnzj.edu.service.CityService;
import hnzj.edu.service.CompanyService;
import hnzj.edu.service.SalaryService;
// ¿ØÖÆ²ã
@Controller
public class IndexController {
	@Autowired //×Ô¶¯Æ¥Åä
	private CityService cityService;
	@Autowired
	private SalaryService salaryService;
	@Autowired
	private CompanyService CompanyService;
	@RequestMapping(value = "/")
	public String index() {
		return "index";
	}
	@RequestMapping(value = "/city",produces = "application/json;charset=UTF-8")
	@ResponseBody
	public String getcity() {
		String data=cityService.getCityData();
		return data;
	}
	@RequestMapping(value = "/salary",produces = "application/json;charset=UTF-8")
	@ResponseBody
	public String getsalary() {
		String data=cityService.getCityData();
		return data;
	}
	@RequestMapping(value = "/company",produces = "application/json;charset=UTF-8")
	@ResponseBody
	public String getcompany() {
		String data=cityService.getCityData();
		return data;
	}
}

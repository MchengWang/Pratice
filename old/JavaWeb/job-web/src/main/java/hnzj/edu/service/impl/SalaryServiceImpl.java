package hnzj.edu.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import hnzj.edu.mapper.SalaryMapper;
import hnzj.edu.pojo.CityPojo;
import hnzj.edu.pojo.SalaryPojo;
import hnzj.edu.service.SalaryService;

public class SalaryServiceImpl implements SalaryService {
	@Autowired
	private SalaryMapper mapper;
	@Transactional
	public String getSalaryData() {
		List<SalaryPojo> lists=mapper.selectSalary();
		List<String> resultData=new ArrayList<String>();
		for (SalaryPojo cityPojo : lists) {
			resultData.add(cityPojo.toString());
		}
		ObjectMapper om=new ObjectMapper();
		String beanjson=null;
		try {
			beanjson=om.writeValueAsString(resultData);
		} catch (JsonProcessingException e) {
			e.printStackTrace();
		}
		return beanjson;
	}
}

package hnzj.edu.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import hnzj.edu.mapper.CityMapper;
import hnzj.edu.pojo.CityPojo;
import hnzj.edu.service.CityService;
@Service
public class CityServiceImpl implements CityService {
	@Autowired
	private CityMapper cityMapper;
	
	@Transactional
	public String getCityData() {
		List<CityPojo> lists=cityMapper.selectCity();
		List<String> resultData=new ArrayList<String>();
		for (CityPojo cityPojo : lists) {
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

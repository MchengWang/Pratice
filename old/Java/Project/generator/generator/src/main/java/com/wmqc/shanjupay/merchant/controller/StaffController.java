package com.wmqc.shanjupay.merchant.controller;


import org.springframework.stereotype.Controller;
import com.wmqc.shanjupay.merchant.service.IStaffService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author author
 * @since 2024-01-30
 */
@Slf4j
@Controller
@Api(value = "", tags = "", description="")
public class StaffController {

    @Autowired
    private StaffDTOService staffDTOService;
}

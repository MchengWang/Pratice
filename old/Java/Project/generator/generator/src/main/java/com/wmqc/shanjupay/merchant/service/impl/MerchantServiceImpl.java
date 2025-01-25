package com.wmqc.shanjupay.merchant.service.impl;

import com.wmqc.shanjupay.merchant.dto.MerchantDTO;
import com.wmqc.shanjupay.merchant.mapper.MerchantMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.wmqc.shanjupay.merchant.service.IMerchantService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.beans.factory.annotation.Autowired;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author author
 * @since 2024-01-30
 */
@Slf4j
@Service
@Transactional
public class MerchantServiceImpl extends ServiceImpl<MerchantMapper, MerchantDTO> implements IMerchantService {

}

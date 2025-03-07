package com.parking.controller;

import com.parking.dao.*;
import com.parking.pojo.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Controller
public class OperateController {

    @Autowired
    private UserMapper userMapper; // 自动装载接口UserMapper
    @Autowired
    private AnnouncementMapper announcementMapper; // 自动装载接口AnnouncementMapper
    @Autowired
    private ParkingSpacesMapper parkingSpacesMapper; // 自动装载接口ParkingSpacesMapper
    @Autowired
    private CustomerMapper customerMapper; // 自动装载接口CustomerMapper
    @Autowired
    private VehicleMapper vehicleMapper;
    private User user;

    @RequestMapping("/")
    public String index(Model model){
        List<Announcement> all = announcementMapper.getAll(); // 进入首页就加载通知
        model.addAttribute("information" , all); // 将通知放进模型中，传递到主页面
        return "index"; // 去往首页面
    }

    @RequestMapping("/clear")
    public String clear(){
        user = null; // 将user设置为空
        return "User/login"; // 去往用户下的登陆页面
    }

    @RequestMapping("/enroll")
    public String enroll(Model model){
        return "User/enroll"; // 注册
    }

    @PostMapping("/enroll")
    public String enroll(@RequestParam(name = "account") String account , @RequestParam(name = "password") String password ){
        userMapper.enrollInsert(account , password); // 用户信息注册
        return "User/login"; // 去登陆页面
    }

    @RequestMapping("/login")
    public String login(){
        return "User/login"; // 去登陆
    }

    @PostMapping("/login")
    public String login(@RequestParam(name = "account") String account , @RequestParam(name = "password") String password , Model model){
        user = userMapper.loginUser(account, password);
        if(user != null) return "redirect:/ParkingSpaces"; // 如果user对象不为空，前往信息管理
        model.addAttribute("message" , "账户或密码错误，请重新输入"); // 否则进行提示
        return "User/login"; //返回到用户登录页面
    }

    @RequestMapping("/message")
    public String message(Model model){
        if(user != null){ // 如果用户信息不为空
            return  "Information/message";  // 将展示用户的信息
        }else{
            model.addAttribute("dd" , "请先登录"); // 没有用户信息，将提示用户即将前往登录页面
            return "User/login";
        }
    }

    @RequestMapping("/InformationPublishing")
    public String InformationPublishing(){ // 去往添加通知页面
        return "Information/InformationPublishing";
    }

    @PostMapping("/insertMessage")
    public String insertMessage(@RequestParam(name = "title") String tille , @RequestParam(name = "type") String type , @RequestParam(name = "content") String content , Model model){
        announcementMapper.InsertMessage(tille , type , content); // 执行插入语句
        model.addAttribute("message" , "插入成功"); // 提示
        return "redirect:/selectAllInformation"; // 返回页面
    }

    @RequestMapping("/ParkingSpaces")
    public String ParkingSpaces(){
        return "Parking/ParkingSpaces"; // 车位信息主页面
    }

    @RequestMapping("/selectAllInformation")
    public String selectAllInformation(Model model){
        List<Announcement> all = announcementMapper.getAll(); // 查询全部的通知
        model.addAttribute("AnList",all); // 携带通知去页面
        return "Information/SelectAllInformation";
    }

    @RequestMapping("/SelectOnce")
    public String SelectOnce(@RequestParam(name = "id") int id , Model model){
        Announcement once = announcementMapper.getOnce(id); // 通过id获取对应的对象
        model.addAttribute("Once" , once);
        return "Information/SelectOnce";
    }

    @RequestMapping("/CusMessage")
    public String CusMessage(Model model){
        if(user != null){
            List<Customer> all = customerMapper.getAll(); // 获取全部的住户信息
            model.addAttribute("CustomerList", all);
            return "Customer/CusMessage";
        }else{
            model.addAttribute("dd" , "请登录");
            return "User/login";
        }

    }

    @GetMapping("/delCustomer")
    public String delCustomer(@RequestParam(name = "id") int id){
        customerMapper.delCustomer(id); // 通过id删除用户信息
        return "redirect:/CusMessage"; // 内部转发到查询页面
    }

    @RequestMapping("/InsertCustomer")
    public String InsertCustomer(){
        return "Customer/InsertCustomer"; // 返回到templates下的InsertCustomer
    }

    @PostMapping("/InsertCustomer") // URL映射
    public String InsertCustomer(@RequestParam(name = "name") String name , @RequestParam(name = "tel") String tel , @RequestParam(name = "licensePlate") String licensePlate , @RequestParam(name = "extra") String extra , Model model){
        customerMapper.InsertCustomer(name , tel , licensePlate , extra); // 插入信息
        return "forward:/CusMessage"; // 重定向到查询页面
    }

    @RequestMapping("/SearchCustomer")
    public String SearchCustomer(@RequestParam(name = "condition") String select , @RequestParam(name = "search") String search  , Model model){
        if(select.equals("姓名")){
            List<Customer> nameList = customerMapper.getName("%" + search + "%"); // 条件查询
            model.addAttribute("CustomerList", nameList);
            return "Customer/CusMessage";
        }else{
            List<Customer> licensePlate = customerMapper.getLicensePlate("%" + search + "%");
            model.addAttribute("CustomerList", licensePlate);
            return "Customer/CusMessage";
        }
    }

    @RequestMapping("/SearchParking")
    public String SearchParking(@RequestParam(name = "condition") String select , @RequestParam(name = "search") String search  , Model model){
        if(select.equals("车位类型")){
            List<ParkingSpaces> listByType = parkingSpacesMapper.getListByType("%" + search + "%");
            model.addAttribute("parking" , listByType);
        }else if(select.equals("车位状态")){
            List<ParkingSpaces> listByType = parkingSpacesMapper.getListByState("%" + search + "%");
            model.addAttribute("parking" , listByType);
        }else{
            ParkingSpaces listByType = parkingSpacesMapper.getListByLocal("%" + search + "%");
            model.addAttribute("parking" , listByType);
        }
        return "Parking/ParkingDetails";
    }

    @RequestMapping("/updCustomer")
    public String updCustomer(@RequestParam(name = "id") int id , Model model){
        List<Customer> idList = customerMapper.getID(id); // 通过id获取住户信息，并设置进更改页面
        model.addAttribute("idlist" , idList);
        return "Customer/updateCustomer";
    }

    @PostMapping("/updCustomer")
    public String updCustomer(@RequestParam(name = "name") String name , @RequestParam(name = "tel") String tel , @RequestParam(name = "licensePlate") String licensePlate , @RequestParam(name = "extra") String extra , @RequestParam(name = "id") int id , Model model){
        customerMapper.updateCustomer(name , tel , licensePlate , extra , id); // 通过id修改住户信息
        return "redirect:/CusMessage";
    }

    @RequestMapping("/ParkingDetails")
    public String parkingDetails(Model model){
        List<ParkingSpaces> all = parkingSpacesMapper.getAll(); // 获取全部停车位信息
        model.addAttribute("parking" , all);
        return "Parking/ParkingDetails";
    }

    @RequestMapping("/Usage")
    public String Usage(Model model){ // 分类统计车位的使用情况
        String[] strs = {"已停车" , "未停车" , "整改中" , "小型车位" , "中型车位" , "大型车位"};
        int nums[] = new int[9];
        for (int i = 0; i < strs.length; i++) {
            if(i <= 2) nums[i] = parkingSpacesMapper.parkingSpaces(strs[i]);
            else nums[i] = parkingSpacesMapper.smallCar(strs[i]);
        }
        nums[6] = parkingSpacesMapper.parkWithType("已停车" , "小型车位");
        nums[7] = parkingSpacesMapper.parkWithType("已停车" , "中型车位");
        nums[8] = parkingSpacesMapper.parkWithType("已停车" , "大型车位");

        nums[3] -= nums[6];
        nums[4] -= nums[7];
        nums[5] -= nums[8];
        model.addAttribute("nums" , nums);

        return "Parking/Usage";
    }

    @PostMapping("/updateMessage")
    public String updateMessage(@RequestParam(name = "id") int id , @RequestParam(name = "title") String title , @RequestParam(name = "type") String type , @RequestParam(name = "text") String content){
        announcementMapper.updateMessage(title , type , content , id); // 修改通知
        return "redirect:/selectAllInformation";
    }

    @RequestMapping("/updatePark")
    public String updatePark(@RequestParam(name = "id") int id , Model model){
        ParkingSpaces oncePark = parkingSpacesMapper.getOnceById(id); // 获取单个车位信息
        model.addAttribute("once" , oncePark);
        return "Parking/updatePark";
    }

    @PostMapping("/updParking")
    public String updParking(@RequestParam(name = "id") int id , @RequestParam(name = "type") String type , @RequestParam(name = "state") String state , @RequestParam(name = "local") String local){
        parkingSpacesMapper.Update(type , state , local , id); // 修改车位信息
        return "redirect:/ParkingDetails";
    }

    @RequestMapping("/InsertVehicle")
    public String InsertVehicle(@RequestParam(name = "local")String local , Model model){
        model.addAttribute("local" , local);
        return "vehicle/InsertVehicle";
    }

    @PostMapping("/InsertVehicle")
    public String InsertVehicle(@RequestParam(name = "name")String name , @RequestParam(name = "tel") String tel , @RequestParam(name = "licensePlate") String licensePlate , @RequestParam(name = "local") String local , @RequestParam(name = "illustrate") String illustrate , @RequestParam(name = "extra") String extra , Model model){
        vehicleMapper.insert(licensePlate, local, illustrate);
        customerMapper.InsertCustomer(name , tel , licensePlate , extra);
        parkingSpacesMapper.UpdateLocal(local);
        return "redirect:/ParkingDetails";
    }

    @RequestMapping("/delInformation")
    public String delInformation(@RequestParam(name = "id") int id){
        announcementMapper.delInformation(id);
        return "redirect:/selectAllInformation";
    }

//    @RequestMapping("/select")
//    public String select(@RequestParam(name = "local")String local , Model model){
//        Vehicle byLocal = vehicleMapper.getByLocal(local);
//        Customer customer = customerMapper.getByLicensePlate(byLocal.getLicensePlate());
//        model.addAttribute("local" , byLocal);
//        model.addAttribute("customer" , customer);
//        return "vehicle/SelectMessage";
//    }

    @RequestMapping("/SearchInformation")
    public String SearchInformation(@RequestParam(name = "condition") String select , @RequestParam(name = "search") String search  , Model model){
        List<Announcement> message = null;
        if(select.equals("标题")){
            message = announcementMapper.getMessageByTitle("%" + search + "%");
        }else{
            message = announcementMapper.getMessageByType("%" + search + "%");
        }
        model.addAttribute("AnList" , message);
        return "Information/SelectAllInformation";
    }

    @RequestMapping("/verify")
    public void verify(){

    }
}

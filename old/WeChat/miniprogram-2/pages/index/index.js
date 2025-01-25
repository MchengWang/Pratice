// 注册页面的js代码
Page({
  data: {
    phone: '',
    password: '',
    confirmPassword: '',
    error: '',
    options: ['选项1', '选项2', '选项3'], // 下拉菜单的选项列表
    selectedOption: '' // 保存用户选择的选项
  },
  
  bindInputPhone: function(e) {
    this.setData({
      phone: e.detail.value
    });
  },
  
  bindInputPassword: function(e) {
    this.setData({
      password: e.detail.value
    });
  },
  
  bindInputConfirmPassword: function(e) {
    this.setData({
      confirmPassword: e.detail.value
    });
  },
  
  register: function() {
    // 验证输入
    
    if (!this.data.phone || !this.data.password || !this.data.confirmPassword) {
      this.setData({
        error: '请输入完整的注册信息'
      });
      return;
    }
    
    if (this.data.password !== this.data.confirmPassword) {
      this.setData({
        error: '两次输入的密码不一致'
      });
      return;
    }
    
    // 执行注册逻辑
    // ...
    
    // 注册成功，跳转到登录页面或其他页面
    wx.navigateTo({
      url: '/pages/login/login'
    });
  }

});
// pages/login/login.js
Page({
  data: {
    username: '',
    password: '',
    loading: false
  },

  // 获取用户名
  getUsername(e) {
    this.setData({
      username: e.detail.value.trim()
    });
  },

  // 获取密码
  getPassword(e) {
    this.setData({
      password: e.detail.value.trim()
    });
  },
  // 处理登录成功
  handleLoginSuccess(data) {
    wx.showToast({
      title: '登录成功',
      icon: 'success'
    });

    // 存储 token（根据实际返回字段调整）
    wx.setStorageSync('token', data.token || '');
    
    // 跳转到首页
    setTimeout(() => {
      wx.reLaunch({
        url: '/pages/index/index'
      });
    }, 1500);
  },

  // 统一错误处理
  handleLoginError(data) {
    console.error('错误详情:', data.devMessage);

    // 根据错误类型处理
    switch (data.code) {
      case 400:
        wx.showToast({
          title: data.userMessage || '用户不存在',
          icon: 'none'
        });
        // 2秒后跳转注册页面
        setTimeout(() => {
          wx.reLaunch({
            url: '/pages/register/register'
          });
        }, 2000);
        break;
        
      // 可扩展其他错误码
      default:
        wx.showToast({
          title: data.userMessage || '登录失败，请重试',
          icon: 'none'
        });
    }
  },
  // 登录请求
  async login() {
    const { username, password } = this.data;
    const salt = "111111"; // 保持与后端约定好的盐值

    if (!username || !password) {
      wx.showToast({
        title: '请填写完整信息',
        icon: 'none'
      });
      return;
    }

    // 防止重复点击
    if (this.data.loading) return;
    this.setData({ loading: true });

      const res = await wx.request({
        url: 'http://localhost:8080/auth/login',
        method: 'POST',
        data: { username, password, salt },
        header: {
          'Content-Type': 'application/json' // 建议添加请求头
        },
        success:(res)=>{
          console.log(res.data);
          const code = res.data.code;
          console.log(code)
          if(code === 200){
           this.handleLoginSuccess(res.data);
          }else {
           this.handleLoginError(res.data);
          }
        },
        fail:(res)=>{
          console.log(res);
        }
      });

    

    
  }


});
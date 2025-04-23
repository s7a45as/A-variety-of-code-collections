// pages/register/register.js
Page({
  data: {
    formValid: false,    // 表单是否有效
    showPasswordError: false, // 显示密码错误提示
    showConfirmError: false  // 显示确认密码错误提示
  },

  // 实时验证输入
  checkInput(e) {
    const field = e.currentTarget.dataset.field
    const value = e.detail.value
    const newData = { [field]: value }
    
    // 更新数据后立即验证
    this.setData(newData, () => {
      this.validateForm()
    })
  },

  // 表单验证
  validateForm() {
    const { username, password, confirmPwd } = this.data
    const validUsername = username && username.length >= 3
    const validPassword = password && password.length >= 6
    const validConfirm = confirmPwd === password

    this.setData({
      formValid: validUsername && validPassword && validConfirm,
      showPasswordError: password && !validPassword,
      showConfirmError: confirmPwd && !validConfirm
    })
  },

  // 表单提交
  formSubmit(e) {
    const formData = e.detail.value
    
    // // 最终表单验证
    // if (!this.data.formValid) {
    //   wx.showToast({
    //     title: '请填写完整信息',
    //     icon: 'none'
    //   })
    //   return
    // }

    wx.showLoading({
      title: '注册中...',
    })

    // 实际开发中替换为你的API地址
    wx.request({
      url: 'http://localhost:8080/auth/register',
      method: 'POST',
      data: {
        username: formData.username,
        password: formData.password
      },
      success: (res) => {
        wx.hideLoading()
        if (res.statusCode === 200) {
          this.registerSuccess()
        } else {
          this.showError(res.data.message || '注册失败')
        }
      },
      fail: (err) => {
        wx.hideLoading()
        this.showError('网络连接失败')
      }
    })
  },

  // 注册成功处理
  registerSuccess() {
    wx.showToast({
      title: '注册成功',
      icon: 'success',
      duration: 1500,
      success: () => {
        setTimeout(() => {
          wx.navigateTo({
            url: '/pages/login/login'
          })
        }, 1500)
      }
    })
  },

  // 显示错误信息
  showError(msg) {
    wx.showToast({
      title: msg,
      icon: 'none',
      duration: 3000
    })
  },
  onReady() {
    this.createBubbles()
  },
  
  createBubbles() {
    const query = wx.createSelectorQuery()
    query.select('.bubble-bg').boundingClientRect()
    query.exec(res => {
      const area = res[0]
      for(let i=0; i<30; i++) {
        const bubble = wx.createIntersectionObserver()
        const size = Math.random()*40 + 20
        const left = Math.random()*area.width
        const delay = Math.random()*5
        this.setData({
          bubbles: [...this.data.bubbles, {
            size,
            left,
            delay,
            duration: 8 + Math.random()*5
          }]
        })
      }
    })
  }
})
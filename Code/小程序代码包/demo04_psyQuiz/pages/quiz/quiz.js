// pages/quiz/quiz.js
// 导入工具
const tool = require('../../util/tool')

Page({
  /**
   * 页面的初始数据
   */
  data: {
    userInfo: {
      avatar: '/images/PixPin_2025-04-07_18-45-32.png',
      name: '吴宏昊',
      class: '软件225班',
      studentId: '202200406213'
    }
  },
  /**
   * 自定义函数--监听表单提交
   */
  onSubmit: function (e) {
    // 获得表单选项值
    let rs = e.detail.value
    // 尝试打印输出表单结果（用完可删除或注释掉）
    console.log(rs)

    // 检查是否全部做完
    for (let i = 1; i <= this.data.qBank.length; i++) {
      // 获得当前题目答案
      let answer = rs['quiz' + i]
      // 有没做的题
      if (answer == '') {
        // 弹出提示框
        wx.showModal({
          title: '信息',
          content: '请完成第' + i + '题再查看结果。',
          showCancel: false
        })
        // 停止遍历
        return
      }
    }

    console.log(JSON.stringify(rs))

    // 关闭所有页面，打开结果页
    wx.reLaunch({
      // 传递参数rs给结果页使用
      url: '../result/result?rs=' + JSON.stringify(rs)
    })
  },
   /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    // 获取题库
    const qBank = tool.quizBank
    // 把题库传给页面显示
    this.setData({
      qBank: qBank
    })
  }
})
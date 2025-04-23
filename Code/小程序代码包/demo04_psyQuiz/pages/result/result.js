// pages/result/result.js
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
   * 自定义函数--返回首页
   */
  goToHome: function () {
    wx.redirectTo({
      url: '../index/index',
    })
  },
  /**
 * 生命周期函数--监听页面加载
 */
  onLoad: function (options) {
    // 获取测试页传来的答案(string转回object)
    let rs = JSON.parse(options.rs)

    // 获取题库和解析
    let qBank = tool.quizBank
    // 声明一个新数组用于存放题目和解析
    let rsBank = []

    // 开始查找对应的解析
    for (let i = 1; i <= qBank.length; i++) {
      // 获取当前题
      let oneQuiz = qBank[i - 1]
      // 获取题干
      let question = oneQuiz.question
      // 获取当前题的选项
      let sign = rs['quiz' + i]
      // 获取当前题的解析
      let analysis = oneQuiz.analysis[sign]

      // 将当前题目的题干和解析加到数组中
      rsBank.push({
        id: i,
        question: question,
        analysis: analysis
      })
    }

    // 将解析结果更新到页面上
    this.setData({
      rsBank: rsBank
    })
  }

})
//index.js
// 服务器地址
const baseUrl = 'http://localhost:8080/'

Page({

  /**
   * 页面的初始数据
   */
  data: {
    result:'',
    tip:''
  },

  /**
   * 自定义函数--监听表单提交并查成语
   */
  search: function (e) {
    console.log(e)
    // 获取成语单词
    let idiom = e.detail.value.idiom

    // 没有输入任何内容
    if (idiom == '') {
      wx.showToast({
        title: '成语不能为空！',
        icon: 'none'
      })
    }
    // 发起网络请求
    else {
      wx.request({
        url: baseUrl+'find',
        data: {
          word: idiom
        },
        fail:err=>{
          console.log(err)
        },
        success: res=> {
          console.log(res.data)
          // 查到结果了
          if (res.data.code == 200) {
            this.setData({
              result: res.data.data,
              tip:''
            })
          }
          // 查无此词
          else{
            this.setData({
              result:'',
              tip:'查询不到该成语的相关信息。'
            })
          }
        }
      })
    }
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})
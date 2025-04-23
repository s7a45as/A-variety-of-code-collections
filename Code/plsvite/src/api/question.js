import request from './request'

export const questionApi = {
  // 获取题目列表
  getQuestionList: (params) => {
    return request({
      url: '/questions',
      method: 'get',
      params
    })
  },

  // 获取随机题目
  getRandomQuestion: (type) => {
    // 确保 type 是数字类型
    const questionType = parseInt(type)
    if (isNaN(questionType)) {
      console.error('Invalid type:', type)
      return Promise.reject(new Error('Invalid question type'))
    }

    return request({
      url: '/questions/random',
      method: 'get',
      params: { 
        type: questionType  // 确保传递数字类型
      }
    })
  },

  // 添加题目
  addQuestion: (data) => {
    return request({
      url: '/questions',
      method: 'post',
      data
    })
  },

  // 更新题目
  updateQuestion: (id, data) => {
    return request({
      url: `/questions/${id}`,
      method: 'put',
      data
    })
  },

  // 删除题目
  deleteQuestion: (id) => {
    return request({
      url: `/questions/${id}`,
      method: 'delete'
    })
  }
} 
import axios from 'axios'
import { message } from 'ant-design-vue'

const request = axios.create({
  baseURL: '/api',
  timeout: 5000
})

// 请求拦截器
request.interceptors.request.use(
  config => {
    const token = localStorage.getItem('token')
    if (token) {
      config.headers.Authorization = `Bearer ${token}`
    }
    return config
  },
  error => {
    return Promise.reject(error)
  }
)

// 响应拦截器
request.interceptors.response.use(
  response => {
    const { data } = response
    if (data.code === 200) {
        // console.log(data)
      return data.data
    } else {
      message.error(data.message)

      return Promise.reject(new Error(data.message))
    }
  },
  error => {
    message.error(error.message)
    return Promise.reject(error)
  }
)

export default request 
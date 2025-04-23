import { createApp } from 'vue'
import { createPinia } from 'pinia'
import Antd from 'ant-design-vue'
import router from './router'
import App from './App.vue'

// 导入样式
import 'ant-design-vue/dist/reset.css'
import './styles/variables.scss'
import './style.css'

// 创建应用实例
const app = createApp(App)

// 使用插件
const pinia = createPinia()
app.use(pinia)
app.use(router)
app.use(Antd)

// 全局错误处理
app.config.errorHandler = (err, vm, info) => {
  console.error('全局错误:', err)
  console.error('错误信息:', info)
}

// 全局属性
app.config.globalProperties.$filters = {
  // 可以添加一些全局过滤器
  formatDate: (value) => {
    if (!value) return ''
    return new Date(value).toLocaleString()
  }
}

// 挂载应用
app.mount('#app')

// 开发环境下的热更新处理
if (import.meta.hot) {
  import.meta.hot.accept()
}

Component({
  properties: {
    // 基础属性
    avatar: {
      type: String,
      value: ''
    },
    title: String,
    subtitle: String,
    studentid:String,
 
    
    // 样式控制
    shadow: {
      type: Boolean,
      value: true
    }
  },

  methods: {
    // 点击事件传递
    onTap() {
      this.triggerEvent('cardtap', { detail: this.data })
    }
  }
})
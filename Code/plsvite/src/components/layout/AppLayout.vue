<template>
  <a-layout class="app-layout">
    <a-layout-sider v-model:collapsed="collapsed" collapsible>
      <div class="logo">题库系统</div>
      <a-menu
        v-model:selectedKeys="selectedKeys"
        theme="dark"
        mode="inline"
      >
        <a-menu-item key="dashboard" @click="$router.push('/dashboard')">
          <dashboard-outlined />
          <span>仪表盘</span>
        </a-menu-item>
        <a-sub-menu key="questions">
          <template #title>
            <span>
              <read-outlined />
              <span>题目管理</span>
            </span>
          </template>
          <a-menu-item key="choice" @click="$router.push('/questions/choice')">选择题</a-menu-item>
          <a-menu-item key="essay" @click="$router.push('/questions/essay')">简答题</a-menu-item>
        </a-sub-menu>
        <a-sub-menu key="practice">
          <template #title>
            <span>
              <form-outlined />
              <span>练习模式</span>
            </span>
          </template>
          <a-menu-item key="sequential" @click="$router.push('/practice/sequential')">顺序练习</a-menu-item>
          <a-menu-item key="random" @click="$router.push('/practice/random')">随机练习</a-menu-item>
        </a-sub-menu>
      </a-menu>
    </a-layout-sider>
    
    <a-layout>
      <a-layout-header class="header">
        <a-space>
          <menu-unfold-outlined 
            v-if="collapsed"
            class="trigger"
            @click="() => (collapsed = !collapsed)"
          />
          <menu-fold-outlined
            v-else
            class="trigger"
            @click="() => (collapsed = !collapsed)"
          />
        </a-space>
      </a-layout-header>
      
      <a-layout-content class="content">
        <router-view></router-view>
      </a-layout-content>
    </a-layout>
  </a-layout>
</template>

<script setup>
import { ref } from 'vue'
import {
  DashboardOutlined,
  ReadOutlined,
  FormOutlined,
  MenuUnfoldOutlined,
  MenuFoldOutlined
} from '@ant-design/icons-vue'

const collapsed = ref(false)
const selectedKeys = ref(['dashboard'])
</script>

<style scoped>
.app-layout {
  min-height: 100vh;
}

.logo {
  height: 32px;
  margin: 16px;
  color: white;
  font-size: 18px;
  text-align: center;
  line-height: 32px;
}

.header {
  background: #fff;
  padding: 0 24px;
}

.trigger {
  font-size: 18px;
  cursor: pointer;
  transition: color 0.3s;
}

.trigger:hover {
  color: #1890ff;
}

.content {
  margin: 24px 16px;
  padding: 24px;
  background: #fff;
  min-height: 280px;
}
</style> 
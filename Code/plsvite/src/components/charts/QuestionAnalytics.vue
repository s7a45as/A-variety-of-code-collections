<template>
  <div class="question-analytics">
    <a-row :gutter="[16, 16]">
      <a-col :span="12">
        <a-card title="题目难度分布">
          <div ref="difficultyChartRef" style="height: 300px"></div>
        </a-card>
      </a-col>
      
      <a-col :span="12">
        <a-card title="答题正确率趋势">
          <div ref="accuracyChartRef" style="height: 300px"></div>
        </a-card>
      </a-col>
      
      <a-col :span="24">
        <a-card title="知识点覆盖率">
          <div ref="knowledgeChartRef" style="height: 400px"></div>
        </a-card>
      </a-col>
      
      <a-col :span="12">
        <a-card title="每日练习题量">
          <div ref="practiceChartRef" style="height: 300px"></div>
        </a-card>
      </a-col>
      
      <a-col :span="12">
        <a-card title="题型分布">
          <div ref="typeChartRef" style="height: 300px"></div>
        </a-card>
      </a-col>
    </a-row>
  </div>
</template>

<script setup>
import { ref, onMounted, onUnmounted } from 'vue'
import * as echarts from 'echarts'
import { formatDate } from '@/utils'

const difficultyChartRef = ref(null)
const accuracyChartRef = ref(null)
const knowledgeChartRef = ref(null)
const practiceChartRef = ref(null)
const typeChartRef = ref(null)

const charts = []

// 难度分布图表
const initDifficultyChart = () => {
  const chart = echarts.init(difficultyChartRef.value)
  charts.push(chart)
  
  chart.setOption({
    tooltip: {
      trigger: 'item'
    },
    legend: {
      orient: 'vertical',
      left: 'left'
    },
    series: [
      {
        type: 'pie',
        radius: ['40%', '70%'],
        avoidLabelOverlap: false,
        itemStyle: {
          borderRadius: 10,
          borderColor: '#fff',
          borderWidth: 2
        },
        label: {
          show: false,
          position: 'center'
        },
        emphasis: {
          label: {
            show: true,
            fontSize: '20',
            fontWeight: 'bold'
          }
        },
        labelLine: {
          show: false
        },
        data: [
          { value: 40, name: '简单' },
          { value: 35, name: '中等' },
          { value: 25, name: '困难' }
        ]
      }
    ]
  })
}

// 正确率趋势图表
const initAccuracyChart = () => {
  const chart = echarts.init(accuracyChartRef.value)
  charts.push(chart)
  
  const dates = Array.from({ length: 7 }, (_, i) => {
    const date = new Date()
    date.setDate(date.getDate() - i)
    return formatDate(date, 'MM-DD')
  }).reverse()
  
  chart.setOption({
    tooltip: {
      trigger: 'axis'
    },
    xAxis: {
      type: 'category',
      data: dates
    },
    yAxis: {
      type: 'value',
      min: 0,
      max: 100,
      axisLabel: {
        formatter: '{value}%'
      }
    },
    series: [
      {
        data: [85, 88, 82, 90, 87, 92, 89],
        type: 'line',
        smooth: true,
        areaStyle: {}
      }
    ]
  })
}

// 知识点覆盖率图表
const initKnowledgeChart = () => {
  const chart = echarts.init(knowledgeChartRef.value)
  charts.push(chart)
  
  chart.setOption({
    tooltip: {
      trigger: 'item'
    },
    radar: {
      indicator: [
        { name: '数据结构', max: 100 },
        { name: '算法', max: 100 },
        { name: '网络', max: 100 },
        { name: '操作系统', max: 100 },
        { name: '数据库', max: 100 }
      ]
    },
    series: [
      {
        type: 'radar',
        data: [
          {
            value: [80, 75, 85, 90, 70],
            name: '知识点覆盖率'
          }
        ]
      }
    ]
  })
}

// 每日练习量图表
const initPracticeChart = () => {
  const chart = echarts.init(practiceChartRef.value)
  charts.push(chart)
  
  chart.setOption({
    tooltip: {
      trigger: 'axis',
      axisPointer: {
        type: 'shadow'
      }
    },
    xAxis: {
      type: 'category',
      data: ['周一', '周二', '周三', '周四', '周五', '周六', '周日']
    },
    yAxis: {
      type: 'value'
    },
    series: [
      {
        data: [15, 12, 18, 20, 16, 25, 22],
        type: 'bar',
        showBackground: true,
        backgroundStyle: {
          color: 'rgba(180, 180, 180, 0.2)'
        }
      }
    ]
  })
}

// 题型分布图表
const initTypeChart = () => {
  const chart = echarts.init(typeChartRef.value)
  charts.push(chart)
  
  chart.setOption({
    tooltip: {
      trigger: 'item'
    },
    legend: {
      top: '5%',
      left: 'center'
    },
    series: [
      {
        type: 'pie',
        radius: ['40%', '70%'],
        avoidLabelOverlap: false,
        label: {
          show: false,
          position: 'center'
        },
        emphasis: {
          label: {
            show: true,
            fontSize: '20',
            fontWeight: 'bold'
          }
        },
        labelLine: {
          show: false
        },
        data: [
          { value: 60, name: '选择题' },
          { value: 40, name: '简答题' }
        ]
      }
    ]
  })
}

onMounted(() => {
  initDifficultyChart()
  initAccuracyChart()
  initKnowledgeChart()
  initPracticeChart()
  initTypeChart()
  
  window.addEventListener('resize', handleResize)
})

onUnmounted(() => {
  charts.forEach(chart => chart.dispose())
  window.removeEventListener('resize', handleResize)
})

const handleResize = () => {
  charts.forEach(chart => chart.resize())
}
</script>

<style scoped>
.question-analytics {
  padding: 24px;
}
</style> 
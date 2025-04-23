<template>
  <div class="dashboard">
    <!-- 统计卡片 -->
    <div class="statistics">
      <a-row :gutter="16">
        <a-col :span="6">
          <a-card>
            <statistic
              title="题目总数"
              :value="statistics.totalQuestions"
              :loading="loading"
            >
              <template #suffix>
                <question-outlined />
              </template>
            </statistic>
          </a-card>
        </a-col>
        <a-col :span="6">
          <a-card>
            <statistic
              title="选择题数量"
              :value="statistics.choiceQuestions"
              :loading="loading"
            >
              <template #suffix>
                <check-circle-outlined />
              </template>
            </statistic>
          </a-card>
        </a-col>
        <a-col :span="6">
          <a-card>
            <statistic
              title="简答题数量"
              :value="statistics.essayQuestions"
              :loading="loading"
            >
              <template #suffix>
                <form-outlined />
              </template>
            </statistic>
          </a-card>
        </a-col>
        <a-col :span="6">
          <a-card>
            <statistic
              title="今日练习题数"
              :value="statistics.todayPracticed"
              :loading="loading"
            >
              <template #suffix>
                <calendar-outlined />
              </template>
            </statistic>
          </a-card>
        </a-col>
      </a-row>
    </div>

    <!-- 最近练习记录 -->
    <a-card title="最近练习记录" class="recent-practice">
      <a-table
        :columns="columns"
        :data-source="practiceRecords"
        :loading="loading"
        :pagination="false"
      >
        <template #bodyCell="{ column, record }">
          <template v-if="column.key === 'type'">
            <a-tag :color="record.type === 'choice' ? 'blue' : 'green'">
              {{ record.type === 'choice' ? '选择题' : '简答题' }}
            </a-tag>
          </template>
        </template>
      </a-table>
    </a-card>

    <!-- 题目类型分布 -->
    <a-card title="题目类型分布" class="question-distribution">
      <div ref="chartRef" style="height: 300px"></div>
    </a-card>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { Statistic } from 'ant-design-vue'
import {
  QuestionOutlined,
  CheckCircleOutlined,
  FormOutlined,
  CalendarOutlined
} from '@ant-design/icons-vue'
import * as echarts from 'echarts'

const loading = ref(false)
const chartRef = ref(null)

const statistics = ref({
  totalQuestions: 0,
  choiceQuestions: 0,
  essayQuestions: 0,
  todayPracticed: 0
})

const columns = [
  {
    title: '题目类型',
    dataIndex: 'type',
    key: 'type'
  },
  {
    title: '题目内容',
    dataIndex: 'title',
    key: 'title'
  },
  {
    title: '练习时间',
    dataIndex: 'practiceTime',
    key: 'practiceTime'
  },
  {
    title: '得分',
    dataIndex: 'score',
    key: 'score'
  }
]

const practiceRecords = ref([])

const initChart = () => {
  const chart = echarts.init(chartRef.value)
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
        name: '题目分布',
        type: 'pie',
        radius: '50%',
        data: [
          { value: statistics.value.choiceQuestions, name: '选择题' },
          { value: statistics.value.essayQuestions, name: '简答题' }
        ],
        emphasis: {
          itemStyle: {
            shadowBlur: 10,
            shadowOffsetX: 0,
            shadowColor: 'rgba(0, 0, 0, 0.5)'
          }
        }
      }
    ]
  })
}

const fetchDashboardData = async () => {
  loading.value = true
  try {
    // 这里应该调用后端 API 获取数据
    statistics.value = {
      totalQuestions: 100,
      choiceQuestions: 60,
      essayQuestions: 40,
      todayPracticed: 15
    }
    
    practiceRecords.value = [
      // 模拟数据
    ]
    
    initChart()
  } finally {
    loading.value = false
  }
}

onMounted(() => {
  fetchDashboardData()
})
</script>

<style scoped>
.dashboard {
  padding: 24px;
}

.statistics {
  margin-bottom: 24px;
}

.recent-practice {
  margin-bottom: 24px;
}

.question-distribution {
  margin-bottom: 24px;
}
</style> 
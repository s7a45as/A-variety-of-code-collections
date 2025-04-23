<template>
  <div class="random-practice">
    <div class="header">
      <a-space>
        <a-select
          v-model:value="type"
          style="width: 120px"
          @change="handleTypeChange"
        >
          <a-select-option :value="0">选择题</a-select-option>
          <a-select-option :value="1">简答题</a-select-option>
        </a-select>
        <a-button type="primary" @click="getNextQuestion">
          <template #icon><RedoOutlined /></template>
          换一题
        </a-button>
        <a-tag :color="currentQuestion?.item?.param2Text?.includes('多选') ? 'purple' : 'blue'">
          {{ currentQuestion?.item?.param2Text?.includes('多选') ? '多选题' : '单选题' }}
        </a-tag>
        <span>已答题数：{{ answeredCount }}</span>
      </a-space>
    </div>

    <div class="content">
      <a-spin :spinning="loading">
        <template v-if="currentQuestion">
          <!-- 选择题卡片 -->
          <choice-question-card
            v-if="type === 0"
            :question="formatChoiceQuestion(currentQuestion)"
            @submit="handleSubmit"
          />
          <!-- 简答题卡片 -->
          <essay-question-card
            v-else
            :question="formatEssayQuestion(currentQuestion)"
            @submit="handleSubmit"
          />
        </template>
      </a-spin>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { message } from 'ant-design-vue'
import { RedoOutlined } from '@ant-design/icons-vue'
import ChoiceQuestionCard from '@/components/question/ChoiceQuestionCard.vue'
import EssayQuestionCard from '@/components/question/EssayQuestionCard.vue'
import { questionApi } from "@/api/question.js"

// 确保 type 是数字类型
const type = ref(0)
const answeredCount = ref(0)
const currentQuestion = ref(null)
const loading = ref(false)

// 格式化选择题数据
const formatChoiceQuestion = (question) => {
  if (!question) return null
  
  // 从 item 中获取数据
  const questionData = question.item || question
  
  // 构建选项数组
  const options = []
  const optionMap = [
    { label: 'A', content: questionData.param7Text },
    { label: 'B', content: questionData.param10Text },
    { label: 'C', content: questionData.param13Text },
    { label: 'D', content: questionData.param16Text },
    { label: 'E', content: questionData.param19Text },
    { label: 'F', content: questionData.param22Text }
  ]
  
  // 过滤掉没有内容的选项
  optionMap.forEach(({ label, content }) => {
    if (content) {
      options.push({ label, content })
    }
  })
  
  return {
    id: questionData.id,
    content: questionData.question || '',  // 题目内容
    options: options,
    answer: questionData.answer || '',
    analysis: questionData.param23Text?.replace('本题得分：', '')?.trim() || '',
    type: questionData.param2Text?.includes('多选') ? 'multiple' : 'single',
    score: parseInt(questionData.param3Text?.match(/\d+/)?.[0] || '1')
  }
}

// 格式化简答题数据
const formatEssayQuestion = (question) => {
  if (!question) return null
  
  // 获取题目数据
  const questionData = question.item || question
  
  return {
    id: questionData.id,
    content: questionData.question || '',  // 题目内容
    answer: questionData.answer || '',     // 答案
    analysis: questionData.analysis || '', // 解析
    score: questionData.score || 0,       // 分数
    type: 'essay'                         // 题目类型
  }
}

const getNextQuestion = async () => {
  loading.value = true
  try {
    console.log('请求类型:', type.value) // 调试日志
    const response = await questionApi.getRandomQuestion(type.value)
    currentQuestion.value = response
    console.log('原始数据:', response)
    if(!response) {
      message.error('没有更多题目了')
      return
    }
    console.log('格式化后的数据:', type.value === 0 ? formatChoiceQuestion(response) : formatEssayQuestion(response))
  } catch (error) {
    console.error('获取题目失败:', error)
    message.error('获取题目失败')
  } finally {
    loading.value = false
  }
}

const handleTypeChange = () => {
  answeredCount.value = 0
  getNextQuestion()
}

const handleSubmit = (answer) => {
  const question = currentQuestion.value?.item || currentQuestion.value
  if (!question) return
  
  // 验证答案
  if (type.value === 0) { // 选择题
    const correctAnswer = question.answer || ''
    const isCorrect = Array.isArray(answer) 
      ? answer.sort().join(',') === correctAnswer.split(',').sort().join(',')
      : answer === correctAnswer
      
    message[isCorrect ? 'success' : 'error'](
      isCorrect ? '回答正确！' : `回答错误，正确答案是：${correctAnswer}`
    )
  } else {
    // 简答题逻辑
    message.success('提交成功')
  }
  
  answeredCount.value++
}

// 手动换题按钮的处理函数
const handleNextQuestion = () => {
  getNextQuestion()
}

// 初始化加载第一题
getNextQuestion()
</script>

<style scoped>
.random-practice {
  padding: 24px;
}

.header {
  margin-bottom: 24px;
  display: flex;
  align-items: center;
  gap: 16px;
}

.content {
  min-height: 400px;
  background: #fff;
  padding: 24px;
  border-radius: 4px;
  box-shadow: 0 1px 2px rgba(0, 0, 0, 0.1);
}
</style> 
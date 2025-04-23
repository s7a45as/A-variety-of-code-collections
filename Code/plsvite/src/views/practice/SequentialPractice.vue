<template>
  <div class="sequential-practice">
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
        <span>当前进度：{{ currentIndex + 1 }}/{{ total }}</span>
        <a-input-number 
          v-model:value="pageSize" 
          :min="1" 
          :max="100"
          style="width: 90px"
          addon-after="条/页"
          @change="handlePageSizeChange"
        />
        <span>第{{ current }}页</span>
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
            @next="handleNext"
          />
          <!-- 简答题卡片 -->
          <essay-question-card
            v-else
            :question="currentQuestion"
            @submit="handleSubmit"
            @next="handleNext"
          />
        </template>
        
        <div class="navigation">
          <a-space>
            <a-button 
              :disabled="current === 1"
              @click="handlePrevPage"
            >
              上一页
            </a-button>
            <a-button 
              :disabled="currentIndex === 0"
              @click="handlePrev"
            >
              上一题
            </a-button>
            <a-button 
              :disabled="currentIndex === total - 1"
              type="primary"
              @click="handleNext"
            >
              下一题
            </a-button>
            <a-button 
              type="primary"
              @click="handleNextPage"
            >
              下一页
            </a-button>
          </a-space>
        </div>
      </a-spin>
    </div>
  </div>
</template>

<script setup>
import { ref, onMounted, computed } from 'vue'
import { message } from 'ant-design-vue'
import { useQuestionStore } from '@/store/modules/question'
import ChoiceQuestionCard from '@/components/question/ChoiceQuestionCard.vue'
import EssayQuestionCard from '@/components/question/EssayQuestionCard.vue'
import { questionApi } from "@/api/question.js"

const type = ref(0)
const questions = ref([])
const currentIndex = ref(0)
const loading = ref(false)
const total = ref(0)
const current = ref(1)
const pageSize = ref(10)

// 格式化选择题数据
const formatChoiceQuestion = (question) => {
  if (!question) return null
  
  // 提取选项
  const options = []
  const optionLetters = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
  
  optionLetters.forEach((letter, index) => {
    const textIndex = 5 + (index * 3) // 5, 8, 11, 14, 17
    if (question[`param${textIndex}Text`] === letter && question[`param${textIndex + 2}Text`]) {
      options.push({
        label: letter,
        content: question[`param${textIndex + 2}Text`].replace(/^"(.+)"$/, '$1') // 移除引号
      })
    }
  })
  
  return {
    id: question.id,
    content: question.question,
    options: options, // 使用解析后的选项数组
    answer: question.answer,
    analysis: question.param23Text?.replace('本题得分：', '')?.trim() || '',
    type: question.param2Text?.includes('多选') ? 'multiple' : 'single',
    score: question.param3Text?.match(/\d+/)?.[0] || 0
  }
}

const currentQuestion = computed(() => {
  if (!questions.value || questions.value.length === 0) return null
  return questions.value[currentIndex.value]
})

const fetchQuestions = async () => {
  loading.value = true
  questions.value = []
  total.value = 0
  currentIndex.value = 0
  
  try {
    const res = await questionApi.getQuestionList({
      type: type.value,
      current: current.value,
      size: pageSize.value
    })
    console.log('获取题目:', res)
    if (res?.items?.records && Array.isArray(res.items.records)) {
      questions.value = res.items.records
      total.value = res.items.records.length
    } else {
      message.warning('没有找到题目')
    }
  } catch (error) {
    console.error('获取题目失败:', error)
    message.error('获取题目失败')
  } finally {
    loading.value = false
  }
}

const handleTypeChange = () => {
  fetchQuestions()
}

const handleSubmit = (answer) => {
  const question = currentQuestion.value
  if (!question) return
  
  // 验证答案
  if (type.value === 0) { // 选择题
    const isCorrect = Array.isArray(answer) 
      ? answer.sort().join(',') === question.answer.split(',').sort().join(',')
      : answer === question.answer
      
    message[isCorrect ? 'success' : 'error'](
      isCorrect ? '回答正确！' : `回答错误，正确答案是：${question.answer}`
    )
  } else {
    // 简答题逻辑
    message.success('提交成功')
  }
}

const handleNext = () => {
  if (currentIndex.value < total.value - 1) {
    currentIndex.value++
  }
}

const handlePrev = () => {
  if (currentIndex.value > 0) {
    currentIndex.value--
  }
}

const handlePrevPage = () => {
  if (current.value > 1) {
    current.value--
    fetchQuestions()
  }
}

const handleNextPage = () => {
  current.value++
  fetchQuestions()
}

const handlePageSizeChange = () => {
  current.value = 1
  fetchQuestions()
}

onMounted(() => {
  fetchQuestions()
})
</script>

<style scoped>
.sequential-practice {
  padding: 24px;
}

.header {
  margin-bottom: 24px;
}

.content {
  min-height: 400px;
}

.navigation {
  display: flex;
  justify-content: center;
  margin-top: 24px;
}
</style> 
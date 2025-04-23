<template>
  <a-card class="question-card" :bordered="false">
    <template #title>
      <div class="question-header">
        <span class="question-type">{{ typeText }}</span>
        <span class="question-id">#{{ question.id }}</span>
      </div>
    </template>
    
    <div class="question-content">
      <div class="question-title">{{ question.title }}</div>
      
      <!-- 选择题选项 -->
      <template v-if="question.type === 'choice'">
        <div class="options-list">
          <a-radio-group v-model:value="selectedAnswer">
            <a-radio v-for="(option, index) in question.options" 
                    :key="index" 
                    :value="option.value">
              {{ option.label }}
            </a-radio>
          </a-radio-group>
        </div>
      </template>
      
      <!-- 简答题答题区域 -->
      <template v-else>
        <a-textarea
          v-model:value="essayAnswer"
          :rows="4"
          placeholder="请输入你的答案"
        />
      </template>
    </div>

    <template #actions>
      <a-space>
        <a-button type="primary" @click="handleSubmit">提交答案</a-button>
        <a-button @click="handleNext">下一题</a-button>
      </a-space>
    </template>
  </a-card>
</template>

<script setup>
import { ref, computed } from 'vue'
import { message } from 'ant-design-vue'

const props = defineProps({
  question: {
    type: Object,
    required: true
  }
})

const emit = defineEmits(['submit', 'next'])

const selectedAnswer = ref('')
const essayAnswer = ref('')

const typeText = computed(() => {
  return props.question.type === 'choice' ? '选择题' : '简答题'
})

const handleSubmit = () => {
  const answer = props.question.type === 'choice' ? selectedAnswer.value : essayAnswer.value
  if (!answer) {
    message.warning('请填写答案')
    return
  }
  emit('submit', answer)
}

const handleNext = () => {
  selectedAnswer.value = ''
  essayAnswer.value = ''
  emit('next')
}
</script>

<style scoped>
.question-card {
  max-width: 800px;
  margin: 20px auto;
  border-radius: 8px;
  box-shadow: 0 2px 8px rgba(0, 0, 0, 0.15);
}

.question-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.question-type {
  color: #1890ff;
  font-weight: bold;
}

.question-id {
  color: #999;
}

.question-title {
  font-size: 16px;
  font-weight: 500;
  margin-bottom: 16px;
}

.options-list {
  display: flex;
  flex-direction: column;
  gap: 12px;
}
</style> 
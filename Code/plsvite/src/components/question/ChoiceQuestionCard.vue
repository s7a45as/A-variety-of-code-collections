<template>
  <div class="choice-question-card">
    <a-card>
      <div class="question-content">
        <div class="question-title">
          {{ question.content }}
        </div>
        
        <div class="options">
          <a-radio-group 
            v-if="question.type === 'single'"
            v-model:value="selectedAnswer"
          >
            <a-radio 
              v-for="option in question.options" 
              :key="option.label"
              :value="option.label"
              class="option-item"
            >
              {{ option.label }}. {{ option.content }}
            </a-radio>
          </a-radio-group>

          <a-checkbox-group
            v-else
            v-model:value="selectedAnswer"
          >
            <a-checkbox
              v-for="option in question.options"
              :key="option.label"
              :value="option.label"
              class="option-item"
            >
              {{ option.label }}. {{ option.content }}
            </a-checkbox>
          </a-checkbox-group>
        </div>

        <div v-if="showAnalysis" class="analysis">
          <div class="correct-answer">
            <strong>正确答案：</strong>
            {{ question.answer }}
          </div>
          <div v-if="question.analysis" class="explanation">
            <strong>解析：</strong>
            {{ question.analysis }}
          </div>
        </div>
      </div>

      <div class="actions">
        <a-space>
          <a-button 
            type="primary" 
            @click="handleSubmit"
            :disabled="!canSubmit || showAnalysis"
          >
            提交答案
          </a-button>
        </a-space>
      </div>
    </a-card>
  </div>
</template>

<script setup>
import { ref, computed, watch } from 'vue'

const props = defineProps({
  question: {
    type: Object,
    required: true
  }
})

const emit = defineEmits(['submit'])

const selectedAnswer = ref(props.question.type === 'single' ? '' : [])
const showAnalysis = ref(false)

// 监听题目变化，重置状态
watch(() => props.question.id, () => {
  selectedAnswer.value = props.question.type === 'single' ? '' : []
  showAnalysis.value = false
})

const canSubmit = computed(() => {
  if (props.question.type === 'single') {
    return selectedAnswer.value !== ''
  } else {
    return selectedAnswer.value.length > 0
  }
})

const handleSubmit = () => {
  if (!canSubmit.value) return
  emit('submit', selectedAnswer.value)
  showAnalysis.value = true
}
</script>

<style scoped>
.choice-question-card {
  margin-bottom: 24px;
}

.question-title {
  font-size: 16px;
  margin-bottom: 24px;
  white-space: pre-wrap;
}

.options {
  margin-bottom: 24px;
}

.option-item {
  display: block;
  margin-bottom: 12px;
}

.analysis {
  margin: 24px 0;
  padding: 16px;
  background-color: #f5f5f5;
  border-radius: 4px;
}

.correct-answer {
  margin-bottom: 12px;
}

.actions {
  display: flex;
  justify-content: center;
  margin-top: 16px;
}
</style> 
<template>
  <div class="essay-question-card">
    <a-card>
      <div class="question-content">
        <div class="question-title">
          {{ question.content }}
        </div>
        
        <a-textarea
          v-model:value="answer"
          :rows="6"
          placeholder="请输入你的答案"
          :disabled="showAnalysis"
        />

        <div v-if="showAnalysis" class="analysis">
          <div class="correct-answer">
            <strong>参考答案：</strong>
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
import { ref, computed } from 'vue'

const props = defineProps({
  question: {
    type: Object,
    required: true
  }
})

const emit = defineEmits(['submit'])

const answer = ref('')
const showAnalysis = ref(false)

const canSubmit = computed(() => {
  return answer.value.trim().length > 0
})

const handleSubmit = () => {
  if (!canSubmit.value) return
  emit('submit', answer.value)
  showAnalysis.value = true
}
</script>

<style scoped>
.essay-question-card {
  margin-bottom: 24px;
}

.question-title {
  font-size: 16px;
  margin-bottom: 24px;
  white-space: pre-wrap;
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
<template>
  <a-form
    :model="formState"
    :rules="rules"
    layout="vertical"
    @finish="handleFinish"
  >
    <a-form-item label="题目内容" name="title">
      <a-textarea
        v-model:value="formState.title"
        :rows="4"
        placeholder="请输入题目内容"
      />
    </a-form-item>

    <template v-if="formState.type === 'choice'">
      <a-form-item
        v-for="(option, index) in formState.options"
        :key="index"
        :label="`选项${option.label}`"
      >
        <a-space>
          <a-input v-model:value="option.content" style="width: 400px" />
          <a-checkbox v-model:checked="option.isAnswer">
            正确答案
          </a-checkbox>
          <a-button
            v-if="formState.options.length > 2"
            type="text"
            danger
            @click="() => removeOption(index)"
          >
            <delete-outlined />
          </a-button>
        </a-space>
      </a-form-item>

      <a-button
        type="dashed"
        block
        @click="addOption"
        :disabled="formState.options.length >= 6"
        style="margin-bottom: 16px"
      >
        <plus-outlined /> 添加选项
      </a-button>
    </template>

    <a-form-item>
      <a-space>
        <a-button type="primary" html-type="submit">保存</a-button>
        <a-button @click="handleReset">重置</a-button>
      </a-space>
    </a-form-item>
  </a-form>
</template>

<script setup>
import { ref, reactive, watch } from 'vue'
import { PlusOutlined, DeleteOutlined } from '@ant-design/icons-vue'

const props = defineProps({
  initialValues: {
    type: Object,
    default: () => ({})
  }
})

const emit = defineEmits(['submit'])

// 创建一个新的表单状态
const createFormState = (values = {}) => ({
  title: '',
  type: 'choice',
  options: [
    { label: 'A', content: '', isAnswer: false },
    { label: 'B', content: '', isAnswer: false }
  ],
  answer: [],
  ...values
})

// 使用函数创建响应式状态
const formState = reactive(createFormState())

// 监听 initialValues 的变化
watch(
  () => props.initialValues,
  (newValues) => {
    if (newValues) {
      // 重置表单状态
      const options = newValues.options?.map(opt => ({
        label: opt.label,
        content: opt.content,
        isAnswer: newValues.answer?.includes(opt.label) || false
      })) || [
        { label: 'A', content: '', isAnswer: false },
        { label: 'B', content: '', isAnswer: false }
      ]

      Object.assign(formState, {
        ...createFormState(),
        ...newValues,
        options
      })
    } else {
      // 如果没有初始值，重置为默认状态
      Object.assign(formState, createFormState())
    }
  },
  { immediate: true, deep: true }
)

// 当选项变化时更新答案
watch(() => formState.options, (newOptions) => {
  formState.answer = newOptions
    .filter(option => option.isAnswer)
    .map(option => option.label)
}, { deep: true })

const rules = {
  type: [{ required: true, message: '请选择题目类型' }],
  title: [{ required: true, message: '请输入题目内容' }],
  answer: [{ required: true, message: '请输入答案' }]
}

const addOption = () => {
  const newLabel = String.fromCharCode(65 + formState.options.length)
  formState.options.push({ label: newLabel, content: '', isAnswer: false })
}

const removeOption = (index) => {
  formState.options.splice(index, 1)
  // 更新剩余选项的标签
  formState.options.forEach((opt, idx) => {
    opt.label = String.fromCharCode(65 + idx)
  })
}

const handleFinish = (values) => {
  emit('submit', values)
}

const handleReset = () => {
  Object.assign(formState, createFormState())
}
</script> 
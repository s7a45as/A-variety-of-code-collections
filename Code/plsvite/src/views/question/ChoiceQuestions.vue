<template>
  <div class="choice-questions">
    <div class="header">
      <a-space>
        <a-button type="primary" @click="showAddModal">
          新增选择题
        </a-button>
        <a-input-search
          v-model:value="queryParams.keyword"
          placeholder="搜索题目"
          style="width: 200px"
          @search="handleSearch"
        />
        <question-import-export @import="handleImport" />
      </a-space>
    </div>

    <a-table
      :columns="columns"
      :data-source="questions"
      :loading="loading"
      :pagination="{
        total: total,
        current: queryParams.current,
        pageSize: queryParams.size,
        onChange: handlePageChange,
        showSizeChanger: true,
        showTotal: (total) => `共 ${total} 条`,
        pageSizeOptions: ['10', '20', '50', '100']
      }"
    >
      <template #bodyCell="{ column, record }">
        <template v-if="column.key === 'title'">
          <div class="question-content">
            <div class="question-title">{{ record.title }}</div>
            <div class="question-options">
              <div v-for="option in record.options" :key="option.label" class="option">
                <span class="option-label" :class="{ 'is-answer': record.answer.includes(option.label) }">
                  {{ option.label }}.
                </span>
                <span class="option-content">{{ option.content }}</span>
              </div>
            </div>
            <div v-if="record.answer.length" class="question-answer">
              <a-tag color="success">正确答案: {{ record.answer.join('、') }}</a-tag>
            </div>
            <div v-if="record.note" class="question-note">
              <a-tag color="warning">{{ record.note }}</a-tag>
            </div>
          </div>
        </template>
        
        <template v-if="column.key === 'action'">
          <a-space>
            <a @click="handleEdit(record)">编辑</a>
            <a-popconfirm
              title="确定要删除这道题目吗？"
              @confirm="handleDelete(record.id)"
            >
              <a class="danger">删除</a>
            </a-popconfirm>
          </a-space>
        </template>
      </template>
    </a-table>

    <a-modal
      v-model:open="modalVisible"
      :title="modalTitle"
      @ok="handleModalOk"
    >
      <question-form
        ref="formRef"
        :initial-values="currentQuestion"
        type="choice"
      />
    </a-modal>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { message } from 'ant-design-vue'
import { useQuestionStore } from '@/store/modules/question'
import QuestionForm from '@/components/question/QuestionForm.vue'
import QuestionImportExport from '@/components/question/QuestionImportExport.vue'
import { questionApi } from "@/api/question.js"
import { cloneDeep } from 'lodash-es'

const columns = [
  {
    title: '题目内容',
    dataIndex: 'title',
    key: 'title',
    ellipsis: true
  },
  {
    title: '题目类型',
    dataIndex: 'type',
    key: 'type',
    width: 100,
    customRender: ({ record }) => record.type === 'multiple' ? '多选题' : '单选题'
  },
  {
    title: '分值',
    dataIndex: 'score',
    key: 'score',
    width: 80,
    align: 'center',
    customRender: ({ text }) => `${text}分`
  },
  {
    title: '操作',
    key: 'action',
    width: 150,
    fixed: 'right'
  }
]

const questionStore = useQuestionStore()
const loading = ref(false)
const modalVisible = ref(false)
const modalTitle = ref('新增选择题')
const formRef = ref(null)
const currentQuestion = ref(null)
const questions = ref([])
const total = ref(0)
const queryParams = ref({
  current: 1,
  size: 10,
  type: 0,
  keyword: ''
})

// 处理后端返回的题目数据
const formatQuestionData = (record) => {
  // 提取选项
  const options = []
  // 遍历所有可能的选项（A-E）
  const optionLetters = ['A', 'B', 'C', 'D', 'E']
  
  optionLetters.forEach((letter, index) => {
    const textIndex = 5 + (index * 3) // 5, 8, 11, 14, 17
    if (record[`param${textIndex}Text`] === letter && record[`param${textIndex + 2}Text`]) {
      options.push({
        label: letter,
        content: record[`param${textIndex + 2}Text`].replace(/^"(.+)"$/, '$1') // 移除引号
      })
    }
  })

  // 处理答案字符串，确保格式一致
  let answers = []
  if (record.answer) {
    // 移除所有空格，并按逗号分割
    answers = record.answer.replace(/\s+/g, '').split(',')
  }

  return {
    id: record.id,
    title: record.question.trim(),
    type: record.param2Text?.includes('多选') ? 'multiple' : 'single',
    score: record.param3Text?.match(/\d+/)?.[0] || 0,
    options: options,
    answer: answers,
    explanation: record.param23Text?.replace('本题得分：', '')?.trim() || '',
    note: record.param26Text || ''
  }
}

// 获取题目列表
const getQuestions = async () => {
  loading.value = true
  try {
    console.log('请求参数:', queryParams.value) // 添加调试日志
    const res = await questionApi.getQuestionList({
      ...queryParams.value,
      type: 0
    })
    questions.value = res.items.records.map(formatQuestionData)
    total.value = res.items.total
  } catch (error) {
    message.error('获取题目列表失败')
  } finally {
    loading.value = false
  }
}

// 搜索处理
const handleSearch = () => {
  queryParams.value.current = 1
  getQuestions()
}

// 分页处理
const handlePageChange = (page, pageSize) => {
  console.log('当前页码:', page) // 调试日志
  queryParams.value = {
    ...queryParams.value,
    current: page,
    size: pageSize
  }
  getQuestions()
}

// 显示新增模态框
const showAddModal = () => {
  modalTitle.value = '新增选择题'
  currentQuestion.value = null
  modalVisible.value = true
}

// 编辑题目
const handleEdit = (record) => {
  modalTitle.value = '编辑选择题'
  const editData = cloneDeep(record)
  // 确保编辑时答案正确显示
  if (typeof editData.answer === 'string') {
    editData.answer = editData.answer.replace(/\s+/g, '').split(',')
  }
  currentQuestion.value = editData
  modalVisible.value = true
}

// 删除题目
const handleDelete = async (id) => {
  try {
    await questionStore.deleteQuestion(id)
    message.success('删除成功')
    getQuestions()
  } catch (error) {
    message.error('删除失败')
  }
}

// 导入题目
const handleImport = async (questions) => {
  try {
    for (const question of questions) {
      await questionStore.addQuestion({
        ...question,
        type: 0
      })
    }
    message.success('导入成功')
    getQuestions()
  } catch (error) {
    message.error('导入失败')
  }
}

// 模态框确认
const handleModalOk = async () => {
  try {
    const values = await formRef.value.validate()
    if (currentQuestion.value?.id) {
      await questionStore.updateQuestion(currentQuestion.value.id, {
        ...values,
        type: 'choice'
      })
      message.success('更新成功')
    } else {
      await questionStore.addQuestion({
        ...values,
        type: 'choice'
      })
      message.success('添加成功')
    }
    modalVisible.value = false
    getQuestions()
  } catch (error) {
    console.error('表单提交错误:', error)
    message.error('操作失败')
  }
}

// 初始化加载
onMounted(() => {
  getQuestions()
})
</script>

<style scoped>
.choice-questions {
  padding: 24px;
}

.header {
  margin-bottom: 24px;
}

.question-content {
  padding: 12px 0;
}

.question-title {
  margin-bottom: 12px;
  white-space: pre-wrap;
  font-weight: 500;
  color: #1f1f1f;
}

.question-options {
  padding-left: 24px;
}

.option {
  margin-bottom: 8px;
  line-height: 1.5;
}

.option-label {
  margin-right: 8px;
  font-weight: 500;
  color: #1890ff;
}

.option-content {
  color: #595959;
}

.question-note {
  margin-top: 8px;
}

.danger {
  color: #ff4d4f;
}

.option-label.is-answer {
  color: #52c41a;  /* 正确答案选项标签显示为绿色 */
  font-weight: bold;
}

.question-answer {
  margin-top: 8px;
}

.question-note {
  margin-top: 8px;
}
</style> 
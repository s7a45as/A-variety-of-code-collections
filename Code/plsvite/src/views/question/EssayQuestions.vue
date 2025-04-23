<template>
  <div class="choice-questions">
    <div class="header">
      <a-space>
        <a-button type="primary" @click="showAddModal">
          新增简答题
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
            <div class="question-title">{{ record.question }}</div>
            <div class="question-answer">
              <strong>参考答案：</strong>
              <div class="answer-content">{{ record.answer }}</div>
            </div>
            <div v-if="record.explanation" class="question-note">
              <strong>解析：</strong>
              <div class="explanation-content">{{ record.explanation }}</div>
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
        type="essay"
      />
    </a-modal>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { message } from 'ant-design-vue'
import { useQuestionStore } from '@/store/modules/question'
import QuestionForm from '@/components/question/QuestionForm.vue'
import QuestionImportExport from '@/components/question/QuestionImportExport.vue'
import { cloneDeep } from 'lodash-es'
import { questionApi } from "@/api/question.js"

const columns = [
  {
    title: '题目内容',
    dataIndex: 'title',
    key: 'title',
    ellipsis: true
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
const modalTitle = ref('新增简答题')
const formRef = ref(null)
const currentQuestion = ref(null)
const questions = ref([])
const total = ref(0)
const queryParams = ref({
  current: 1,
  size: 10,
  type: 1,
  keyword: ''
})

// 获取题目列表
const getQuestions = async () => {
  loading.value = true
  try {
    const res = await questionApi.getQuestionList({
      ...queryParams.value,
      type: 1
    })
    questions.value = res.items.records
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
  queryParams.value = {
    ...queryParams.value,
    current: page,
    size: pageSize
  }
  getQuestions()
}

// 显示新增模态框
const showAddModal = () => {
  modalTitle.value = '新增简答题'
  currentQuestion.value = null
  modalVisible.value = true
}

// 编辑题目
const handleEdit = (record) => {
  modalTitle.value = '编辑简答题'
  currentQuestion.value = cloneDeep(record)
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
        type: 'essay'
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
      await questionStore.updateQuestion(currentQuestion.value.id, values)
      message.success('更新成功')
    } else {
      await questionStore.addQuestion(values)
      message.success('添加成功')
    }
    modalVisible.value = false
    getQuestions()
  } catch (error) {
    message.error('操作失败')
  }
}

// 初始化加载
getQuestions()
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

.question-answer {
  margin-top: 12px;
  padding: 12px;
  background-color: #f5f5f5;
  border-radius: 4px;
}

.answer-content {
  margin-top: 8px;
  white-space: pre-wrap;
  color: #595959;
}

.question-note {
  margin-top: 12px;
}

.explanation-content {
  margin-top: 8px;
  color: #595959;
  white-space: pre-wrap;
}

.danger {
  color: #ff4d4f;
}
</style> 
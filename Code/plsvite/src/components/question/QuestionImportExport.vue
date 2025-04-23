<template>
  <div class="question-import-export">
    <a-space>
      <a-upload
        accept=".xlsx,.xls"
        :before-upload="handleImport"
        :show-upload-list="false"
      >
        <a-button>
          <upload-outlined />
          导入题目
        </a-button>
      </a-upload>

      <a-button @click="handleExport">
        <download-outlined />
        导出题目
      </a-button>
    </a-space>

    <a-modal
      v-model:visible="previewVisible"
      title="导入预览"
      @ok="confirmImport"
      :width="800"
    >
      <a-table
        :columns="columns"
        :data-source="previewData"
        :pagination="false"
        :scroll="{ y: 400 }"
      />
    </a-modal>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { message } from 'ant-design-vue'
import { UploadOutlined, DownloadOutlined } from '@ant-design/icons-vue'
import { exportToExcel } from '@/utils'
import * as XLSX from 'xlsx'

const emit = defineEmits(['import'])

const previewVisible = ref(false)
const previewData = ref([])

const columns = [
  { title: '题目类型', dataIndex: 'type', key: 'type' },
  { title: '题目内容', dataIndex: 'title', key: 'title' },
  { title: '选项/答案', dataIndex: 'options', key: 'options' },
  { title: '正确答案', dataIndex: 'answer', key: 'answer' }
]

const handleImport = (file) => {
  const reader = new FileReader()
  reader.onload = (e) => {
    const data = new Uint8Array(e.target.result)
    const workbook = XLSX.read(data, { type: 'array' })
    const worksheet = workbook.Sheets[workbook.SheetNames[0]]
    const jsonData = XLSX.utils.sheet_to_json(worksheet)
    
    previewData.value = jsonData.map(row => ({
      type: row['题目类型'],
      title: row['题目内容'],
      options: row['选项'],
      answer: row['正确答案']
    }))
    
    previewVisible.value = true
  }
  reader.readAsArrayBuffer(file)
  return false
}

const confirmImport = () => {
  emit('import', previewData.value)
  previewVisible.value = false
  message.success('导入成功')
}

const handleExport = () => {
  const data = props.questions.map(q => ({
    '题目类型': q.type === 'choice' ? '选择题' : '简答题',
    '题目内容': q.title,
    '选项': q.type === 'choice' ? q.options.join(';') : '',
    '正确答案': q.answer
  }))
  
  exportToExcel(data, '题库导出')
}
</script> 
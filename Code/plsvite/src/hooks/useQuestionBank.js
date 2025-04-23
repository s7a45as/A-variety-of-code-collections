import { ref, computed } from 'vue'
import { useQuestionStore } from '@/store/modules/question'

export function useQuestionBank() {
  const questionStore = useQuestionStore()
  const currentPage = ref(1)
  const pageSize = ref(10)
  const searchKeyword = ref('')
  const selectedType = ref('')

  const filteredQuestions = computed(() => {
    let result = [...questionStore.questions]
    
    if (searchKeyword.value) {
      result = result.filter(q => 
        q.title.toLowerCase().includes(searchKeyword.value.toLowerCase())
      )
    }
    
    if (selectedType.value) {
      result = result.filter(q => q.type === selectedType.value)
    }
    
    return result
  })

  const paginatedQuestions = computed(() => {
    const start = (currentPage.value - 1) * pageSize.value
    const end = start + pageSize.value
    return filteredQuestions.value.slice(start, end)
  })

  const totalPages = computed(() => 
    Math.ceil(filteredQuestions.value.length / pageSize.value)
  )

  const handlePageChange = (page) => {
    currentPage.value = page
  }

  const handleSearch = (keyword) => {
    searchKeyword.value = keyword
    currentPage.value = 1
  }

  const handleTypeChange = (type) => {
    selectedType.value = type
    currentPage.value = 1
  }

  return {
    currentPage,
    pageSize,
    searchKeyword,
    selectedType,
    filteredQuestions,
    paginatedQuestions,
    totalPages,
    handlePageChange,
    handleSearch,
    handleTypeChange
  }
} 
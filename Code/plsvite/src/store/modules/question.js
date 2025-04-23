import { defineStore } from 'pinia'
import { questionApi } from '@/api/question'

export const useQuestionStore = defineStore('question', {
  state: () => ({
    questions: [],
    currentQuestion: null,
    loading: false,
    total: 0,
    queryParams: {
      page: 1,
      pageSize: 10,
      type: '',
      keyword: ''
    }
  }),


}) 
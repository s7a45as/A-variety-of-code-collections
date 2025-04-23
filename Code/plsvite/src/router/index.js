import { createRouter, createWebHistory } from 'vue-router'
import AppLayout from '../components/layout/AppLayout.vue'

const routes = [
  {
    path: '/',
    component: AppLayout,
    children: [
      {
        path: '',
        name: 'Dashboard',
        component: () => import('../views/dashboard/index.vue')
      },
      {
        path: 'practice',
        children: [
          {
            path: 'sequential',
            name: 'SequentialPractice',
            component: () => import('../views/practice/SequentialPractice.vue')
          },
          {
            path: 'random',
            name: 'RandomPractice',
            component: () => import('../views/practice/RandomPractice.vue')
          }
        ]
      },
      {
        path: 'questions',
        children: [
          {
            path: 'choice',
            name: 'ChoiceQuestions',
            component: () => import('../views/question/ChoiceQuestions.vue')
          },
          {
            path: 'essay',
            name: 'EssayQuestions',
            component: () => import('../views/question/EssayQuestions.vue')
          }
        ]
      }
    ]
  }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router 
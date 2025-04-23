//测试题库
const quizBank = [
  {
    id: 1,
    question: '想象自己正处在一片大森林中，看到面前有一座很旧的小屋。请问这个小屋的门现在是什么状态？',
    options: [
      { value: 'A', text: '开着' },
      { value: 'B', text: '关着' }
    ],
    analysis: {
      'A':'门是开着的：你一个愿意与别人分享的人。',
      'B':'门是关着的：你是一个愿意把事情埋在心底的人。'
    }
  },
  {
    id: 2,
    question: '你走进屋子看到一张桌子，这个桌子的形状是怎样的？',
    options: [
      { value: 'A', text: '圆形/椭圆形' },
      { value: 'B', text: '正方形/长方形' },
      { value: 'C', text: '三角形' }
    ],
    analysis: {
      'A':'圆形/椭圆形：总有朋友在陪伴你。',
      'B':'正方形/长方形：你在交朋友时有点挑剔。',
      'C':'三角形：你的生活里没太多朋友。'
    }
  },
  {
    id: 3,
    question: '桌子上有个花瓶，瓶子里的水有多少呢？',
    options: [
      { value: 'A', text: '空的' },
      { value: 'B', text: '一半' },
      { value: 'C', text: '满的' }
    ],
    analysis: {
      'A':'空的：对目前的生活不满意。',
      'B':'一半：生活只有一半符合你的理想。',
      'C':'满的：对目前的生活非常满意。'
    }
  },
  {
    id: 4,
    question: '瓶子的质地是？',
    options: [
      { value: 'A', text: '玻璃/泥土/陶瓷' },
      { value: 'B', text: '金属/塑料/木头' }
    ],
    analysis: {
      'A':'玻璃/泥土/陶瓷：你一个脆弱的人。',
      'B':'金属/塑料/木头：你是一个坚强的人。',
    }
  },
  {
    id: 5,
    question: '走在森林中突然发现一把钥匙，这把钥匙的材质是？',
    options: [
      { value: 'A', text: '青铜钥匙' },
      { value: 'B', text: '银钥匙' },
      { value: 'C', text: '金钥匙' },
      { value: 'D', text: '水晶钥匙' }
    ],
    analysis: {
      'A':'青铜钥匙：务实主义，注重现实价值',
      'B':'银钥匙：追求品质生活的中产阶级理想',
      'C':'金钥匙：渴望财富与地位的野心家',
      'D':'水晶钥匙：重视精神世界的理想主义者'
    }
  },
  {
    id: 6,
    question: '穿过森林来到海边，你看到的海面是怎样的？',
    options: [
      { value: 'A', text: '风平浪静' },
      { value: 'B', text: '微波荡漾' },
      { value: 'C', text: '惊涛骇浪' }
    ],
    analysis: {
      'A':'风平浪静：情绪稳定的理智派',
      'B':'微波荡漾：偶尔焦虑但总体可控',
      'C':'惊涛骇浪：正处于情绪波动期'
    }
  },
  {
    id: 7,
    question: '沙滩上有个神秘箱子，你会如何打开它？',
    options: [
      { value: 'A', text: '直接掀开' },
      { value: 'B', text: '找工具撬开' },
      { value: 'C', text: '先摇晃听声音' },
      { value: 'D', text: '暂时不打开' }
    ],
    analysis: {
      'A':'直接派：行动果敢但可能欠考虑',
      'B':'工具派：善于利用资源的现实主义者',
      'C':'谨慎派：风险规避型人格',
      'D':'保守派：需要更长时间做决策'
    }
  },
  {
    id: 8,
    question: '如果箱子里只能放一件物品，你希望是？',
    options: [
      { value: 'A', text: '日记本' },
      { value: 'B', text: '宝石' },
      { value: 'C', text: '武器' },
      { value: 'D', text: '镜子' }
    ],
    analysis: {
      'A':'日记本：重视回忆与情感体验',
      'B':'宝石：追求物质保障与安全感',
      'C':'武器：具有强烈自我保护意识',
      'D':'镜子：注重自我认知与内在成长'
    }
  }
]

// 导出题库
module.exports = {
  quizBank: quizBank
}
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5+6;

vector<int>heap;
void solve(){
int n,m;cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        heap.push_back(a);
        push_heap(heap.begin(), heap.end(), greater<int>()); // 逐个插入调整堆  不能一次使用make_heap 
    }


/*

在构建堆时，`push_heap`和`make_heap`的机制不同，导致堆结构差异：
---

### **核心区别**
1. **`make_heap`一次性建堆**  
   ? 将现有数组直接调整为堆结构，时间复杂度 O(n)  
   ? 逻辑：从最后一个非叶子节点开始反向调整（自底向上）  
   ? **结果**：堆结构可能与题目要求的插入顺序不一致

2. **`push_heap`逐次插入**  
   ? 每次在数组末尾插入元素后调整堆，时间复杂度 O(nlogn)  
   ? 逻辑：新元素“上浮”到合适位置（自顶向下调整）  
   ? **结果**：严格遵循插入顺序的堆结构

---

### **示例对比**
假设依次插入元素 `3 → 1 → 2`：

#### 正确做法（逐个插入）：
| 操作 | 插入元素 | 堆调整后数组 | 堆结构 |  
| --- | --- | --- | --- |  
| 1 | 3 | `[3]` | ![3](https://cdn.luogu.com.cn/upload/image_hosting/5p2g4h7c.png) |  
| 2 | 1 | `[1,3]` | ![1-3](https://cdn.luogu.com.cn/upload/image_hosting/7x5o7y3v.png) |  
| 3 | 2 | `[1,3,2]` | ![1-3-2](https://cdn.luogu.com.cn/upload/image_hosting/8v9jz9k7.png) |  

#### 错误做法（`make_heap`一次性建堆）：
| 原始数组 | `make_heap`后数组 | 堆结构 |  
| --- | --- | --- |  
| `[3,1,2]` | `[1,3,2]` | ![1-3-2](https://cdn.luogu.com.cn/upload/image_hosting/8v9jz9k7.png) |  

---

### **看似相同的堆结构，为何结果不同？**
虽然两种方式最终堆结构相同，但 **中间过程不同**，导致某些命题的判断结果可能错误。例如：

假设命题要求判断 `3` 是否是 `2` 的父节点：
? **正确做法**（逐次插入）：`3` 的左右子节点为空，`2` 的父节点是 `1` → **命题为假**  
? **错误做法**（一次性建堆）：`3` 的右子节点是 `2` → **命题为真**

---

### **题目要求的本质**
题目明确要求将元素 **逐个插入初始为空的堆**，意味着必须用 `push_heap` 保证插入顺序的逻辑正确性。若用 `make_heap` 一次性建堆，虽然最终堆结构可能相同，但破坏了插入顺序的中间过程，导致部分命题判断错误。

---

### **修正方法**
逐个插入时正确维护堆结构：
```cpp
vector<int> heap;
for (int i = 0; i < n; i++) {
    heap.push_back(a);        // 插入末尾
    push_heap(heap.begin(), heap.end(), greater<int>()); // 调整堆
}
```

---

### **结论**
`push_heap` 严格保证插入顺序的堆结构演变过程，而 `make_heap` 是数学优化的批量操作。二者的堆结构演变路径不同，导致命题判断结果可能不同。



*/


string s;
getchar();
while(m--){
	int x;
	string tmp;
	cin>>x>>tmp;
	if(tmp=="is"){
		string tmp2;
		cin>>tmp2;
		if(tmp2=="the"){
			string tmp5;cin>>tmp5;
			if(tmp5=="root"){
				if(heap[0]==x)cout<<"T"<<endl;
				else cout<<"F"<<endl;
				
			}else{
				string tmp6;
				int y;
				int t1=0;
				cin>>tmp6>>y;
			
			for(int i=0;i<heap.size();i++){
				if(heap[i]==x){
					if((heap[(2*i)+1]==y)||(heap[(2*i)+2]==y))
					{
					cout<<"T"<<endl;
					t1=1;
					
					break;	
					}
				}
			}
			if(!t1)cout<<"F"<<endl;
				
			}
			
		}else{
			string tmp3,tmp4;
			int y;
			cin>>tmp3>>tmp4>>y;
			int t1=0;
			
			for(int i=0;i<heap.size();i++){
				if(heap[i]==y){
					if((heap[(2*i)+1]==x)||(heap[(2*i)+2]==x))
					{
					cout<<"T"<<endl;
					t1=1;
					
					break;	
					}
				}
			}
			if(!t1)cout<<"F"<<endl;
			
			
		
		}
		
		
	}else{
		int y;
		string tmp1,tmp2;
		cin>>y>>tmp1>>tmp2;
		int t1=0;
		
		for(int i=0;i<heap.size();i++){
			if(((heap[(2*i)+1]==x)&&(heap[(2*i)+2]==y))||((heap[(2*i)+1]==y)&&(heap[(2*i)+2]==x))){
				cout<<"T"<<endl;
				t1=1;
				
				break;
				
			}
			
		}
		if(!t1)cout<<"F"<<endl;
		
	}
	
}
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--){
		solve();
		
	} 
}

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
        push_heap(heap.begin(), heap.end(), greater<int>()); // ������������  ����һ��ʹ��make_heap 
    }


/*

�ڹ�����ʱ��`push_heap`��`make_heap`�Ļ��Ʋ�ͬ�����¶ѽṹ���죺
---

### **��������**
1. **`make_heap`һ���Խ���**  
   ? ����������ֱ�ӵ���Ϊ�ѽṹ��ʱ�临�Ӷ� O(n)  
   ? �߼��������һ����Ҷ�ӽڵ㿪ʼ����������Ե����ϣ�  
   ? **���**���ѽṹ��������ĿҪ��Ĳ���˳��һ��

2. **`push_heap`��β���**  
   ? ÿ��������ĩβ����Ԫ�غ�����ѣ�ʱ�临�Ӷ� O(nlogn)  
   ? �߼�����Ԫ�ء��ϸ���������λ�ã��Զ����µ�����  
   ? **���**���ϸ���ѭ����˳��Ķѽṹ

---

### **ʾ���Ա�**
�������β���Ԫ�� `3 �� 1 �� 2`��

#### ��ȷ������������룩��
| ���� | ����Ԫ�� | �ѵ��������� | �ѽṹ |  
| --- | --- | --- | --- |  
| 1 | 3 | `[3]` | ![3](https://cdn.luogu.com.cn/upload/image_hosting/5p2g4h7c.png) |  
| 2 | 1 | `[1,3]` | ![1-3](https://cdn.luogu.com.cn/upload/image_hosting/7x5o7y3v.png) |  
| 3 | 2 | `[1,3,2]` | ![1-3-2](https://cdn.luogu.com.cn/upload/image_hosting/8v9jz9k7.png) |  

#### ����������`make_heap`һ���Խ��ѣ���
| ԭʼ���� | `make_heap`������ | �ѽṹ |  
| --- | --- | --- |  
| `[3,1,2]` | `[1,3,2]` | ![1-3-2](https://cdn.luogu.com.cn/upload/image_hosting/8v9jz9k7.png) |  

---

### **������ͬ�Ķѽṹ��Ϊ�ν����ͬ��**
��Ȼ���ַ�ʽ���նѽṹ��ͬ���� **�м���̲�ͬ**������ĳЩ������жϽ�����ܴ������磺

��������Ҫ���ж� `3` �Ƿ��� `2` �ĸ��ڵ㣺
? **��ȷ����**����β��룩��`3` �������ӽڵ�Ϊ�գ�`2` �ĸ��ڵ��� `1` �� **����Ϊ��**  
? **��������**��һ���Խ��ѣ���`3` �����ӽڵ��� `2` �� **����Ϊ��**

---

### **��ĿҪ��ı���**
��Ŀ��ȷҪ��Ԫ�� **��������ʼΪ�յĶ�**����ζ�ű����� `push_heap` ��֤����˳����߼���ȷ�ԡ����� `make_heap` һ���Խ��ѣ���Ȼ���նѽṹ������ͬ�����ƻ��˲���˳����м���̣����²��������жϴ���

---

### **��������**
�������ʱ��ȷά���ѽṹ��
```cpp
vector<int> heap;
for (int i = 0; i < n; i++) {
    heap.push_back(a);        // ����ĩβ
    push_heap(heap.begin(), heap.end(), greater<int>()); // ������
}
```

---

### **����**
`push_heap` �ϸ�֤����˳��Ķѽṹ�ݱ���̣��� `make_heap` ����ѧ�Ż����������������ߵĶѽṹ�ݱ�·����ͬ�����������жϽ�����ܲ�ͬ��



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

#include <iostream>
#include <queue>
using namespace std;
//greater 小根堆 
//默认是大根堆
priority_queue<int,vector<int>,greater<int> > heap;
int main(){
	int n,m; 
	cin >> n;
	for(int i = 0 ; i < n;i++){
		cin >> m;
		heap.push(m);
	}
	int ans = 0 ; 
	while(!heap.empty()){
		int t1 = heap.top();
		heap.pop();
		if(heap.empty()) {
			//cout<<(ans)<<endl;
			return ans;
		};
		int t2 = heap.top();
		ans += t1+t2;
		
		heap.pop();
		heap.push(t1+t2);
	}
	return ans;
}
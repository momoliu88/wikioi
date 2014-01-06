#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
struct cmp{
	bool operator()(pair<int,int>a,pair<int,int>b){
		return a.first > b.first;
	}
};
//两个无序数组之和的前N个最小数
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp > heap;
int main(){
	int n ;
	cin >> n;
	int A[n],B[n];
	for(int i = 0 ; i< n;i++)
		cin >> A[i];
	for(int i = 0 ; i< n;i++)
		cin >> B[i];
	sort(A,A+n);
	sort(B,B+n);
	for(int i = 0;i < n;i++)
		heap.push(make_pair(A[i]+B[0],0));
	int k = 0 ;
	while(k<n){
		pair<int,int> tmp = heap.top();
		heap.pop();
		cout<<tmp.first<<" ";
		k++;
		if(tmp.second+1<n)
			heap.push(tmp.first+B[tmp.second+1]-B[tmp.second],tmp.second+1);
	}
	return 0;
}

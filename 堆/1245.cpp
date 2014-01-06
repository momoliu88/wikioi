#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
priority_queue<int,vector<int> > heap;
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
	for(int i = 0 ; i < n;i++)
		heap.push(A[i]+B[0]);
	
	for(int i = 1;i<n;i++){
		for(int j = 0 ; j< i;j++)
		{
			int sum = B[i]+A[j];
			if(heap.size()<n)heap.push(sum);
			else{
				if(sum< heap.top()){
					heap.pop();
					heap.push(sum);
				}
		
			}
	
		}
	}
		
	deque<int> c;
	while(!heap.empty()){
		c.push_front(heap.top());
		heap.pop();
	}
	for(int i = 0 ; i < c.size();i++)
		cout<<c[i]<<" ";
	cout<<endl;
}

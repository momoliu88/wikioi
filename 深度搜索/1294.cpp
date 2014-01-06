//给出一个n, 请输出n的所有全排列

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void compute(vector<bool> &used,vector<int> & p,int n){
	if(p.size() == n){
		for(int i = 0;i < n;i++)
			printf("%d ",p[i]);
		printf("\n");
		return;
	}	
	for(int i = 1; i<=n;i++){
		if(!used[i]){
			used[i] = true;
			p.push_back(i);
			compute(used,p,n);
			used[i] = false;
			p.pop_back();
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	vector<bool> used(n,false);
	vector<int>  p;
	compute(used,p,n);
}
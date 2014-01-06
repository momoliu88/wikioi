/*
给定N（小于等于8）个点的地图，以及地图上各点的相邻关系，请输出用4种颜色将地图涂色的所有方案数（要求相邻两点不能涂成相同的颜色）
数据中0代表不相邻，1代表相邻
*/
#include <stdio.h>
#include <iostream>
using namespace std;
const int MAXN = 10;
void dfs(int t,int n,int &ans,int cors[],int graph[][MAXN]){
	if(t>=n){
		ans++;
		return;
	}
	for(int cor = 1;cor<=4;cor++){
		bool proceed = true;
		for(int i = 0;i<n;i++){
			if(graph[t][i]==1 && cors[i]==cor){
				proceed = false;
				break;
			}
		}
		if(proceed){
			//try
			cors[t] = cor;
			dfs(t+1,n,ans,cors,graph);
			cors[t] = 0;
		}
	}
}
int main()
{
	int graph[MAXN][MAXN],n,cors[MAXN];
	memset(graph,0,sizeof(graph));
	memset(cors,0,sizeof(cors));
	
	cin>> n ;
	for(int i = 0 ; i<n;i++)
		for(int j = 0 ; j < n;j++)
			cin>>graph[i][j];
	int ans = 0 ;
	dfs(0,n,ans,cors,graph);
	cout<<ans<<endl;
	return 0;
}

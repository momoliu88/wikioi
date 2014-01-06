#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 20001
#define MAXM 100001
int pa[MAXN*2];
typedef struct Node{
	int a,b,c;
}Node;

int find(int x){
	if(x==pa[x]) return x;
	pa[x] = find(pa[x]);
	return pa[x];
}
bool join(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx==fy)
		return true;
	pa[fx] = fy;
	return false;
}
bool cmp(Node a,Node b){
	return a.c > b.c;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	Node crime[M];
	for(int i = 1;i<=2*N;i++)
		pa[i] = i;
	for(int i = 0 ; i< M;i++)
	{
		scanf("%d%d%d",&crime[i].a,&crime[i].b,&crime[i].c);
	}
	sort(crime,crime+M,cmp);
	int ans=-1;
	for(int i = 0 ; i < M;i++){
		int fx = find(crime[i].a);
		int fy = find(crime[i].b);
		if(fx == fy)
		{
			ans = i;
			break;
		}
		else{
			pa[fx] = find(crime[i].b+N);
			pa[fy] = find(crime[i].a+N);
		}	
	}
	if(ans==-1)
		printf("0\n");
	else
		printf("%d\n",crime[ans].c);
}
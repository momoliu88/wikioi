//树状数组解决1080
//一行N个方格，开始每个格子里都有一个整数。现在动态地提出一些问题和修改：提问的形式是求某一个特定的子区间[a,b]中所有元素的和；修改的规则是指定某一个格子x，加上或者减去一个特定的值A。现在要求你能对每个提问作出正确的回答。1≤N<100000，,提问和修改的总数m<10000条。
//线段树或者树状数组
#include <iostream>
#include <stdio.h>
#define MAXN 100005
using namespace std;

int c[MAXN];
int lowBit(int x)
{
	return x&(-x);
}
void update(int idx,int d,int N){
	while(idx<MAXN)
	{
		c[idx]+=d;
		idx += lowBit(idx);
	}
}
int getResult(int idx){
	int sum = 0 ;
	while(idx>0){
		sum += c[idx];
		idx -= lowBit(idx);
	}
	return sum;
}
int main(){
	
	freopen("1080.txt","r",stdin);
	int N ;
	scanf("%d",&N);
	for(int i = 0;i<=N;i++)
		c[i] = 0 ;
	int data;
	for(int i = 1;i<=N;i++){
		scanf("%d",&data);		
		update(i,data,N);
	}
	int M;
	scanf("%d",&M);
	for(int i = 1;i<=M;i++)
	{
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if(t==1){
			update(a,b,N);
		}
		else {
			int result = getResult(b)-getResult(a-1);
			printf("%d\n",result);
		}
	}

}
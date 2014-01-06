#include<stdio.h>
#include<iostream>
#include<math.h>
#include<map>
#define LL long long
using namespace std;
const int MAX_N = 31;
const int MAX_T = 1<<15;
map<LL,LL> hash1;
map<LL,LL> hash2;
LL num[MAX_T];
LL length;
LL v[MAX_N]; //砝码的重量
LL N;
LL M; 
LL ans = 1<<30;
LL init()
{
	LL i;
	scanf("%lld %lld",&N,&M);
	for (i=1;i<=N;i++)
		scanf("%lld",&v[i]);
	hash1[0]=hash2[0]=0;
	num[++length]=0;
}
LL dfs1(LL t,LL tmp,LL r,LL q) //t 砝码的idx，tmp 当前的重量 r 砝码的最大标记 q 已经使用的砝码个数
{
	if (tmp>M) return 0;
	if (t>r) 
	{
		if ((hash1.find(tmp)==hash1.end())
			||(hash1[tmp]>q))
				hash1[tmp]=q,num[++length]=tmp;
		return 0;
	}
	dfs1(t+1,tmp,r,q); //不使用当前的t对应的砝码
	dfs1(t+1,tmp+v[t],r,q+1); //使用当前的t对应的砝码 这里是个组合数的递归
}
LL dfs2(LL t,LL tmp,LL r,LL q)
{
	if (tmp>M) return 0;
	if (t>r) {
		if ((hash2.find(tmp)==hash2.end())
			||(hash2[tmp]>q))
				hash2[tmp]=q;
		return 0;
	}
	dfs2(t+1,tmp,r,q);
	dfs2(t+1,tmp+v[t],r,q+1);
}
LL work()
{
	dfs1(1,0,N/2,0);
	dfs2(N/2+1,0,N,0);
	int i;
	for (i=1;i<=length;i++)
		if (hash2.find(M-num[i])!=hash2.end())
			ans = min(ans,hash1[num[i]]+hash2[M-num[i]]);
}
LL put()
{
	printf("%lld",ans);
}
int main()
{
	init();
	work();
	put();
	return 0;
}

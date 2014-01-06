#include <cstdio>
#include <iostream>
#include <cstring>
#define maxn 301
#define maxt 601
using namespace std;
struct node{
	int t,ls,rs,v;
}te[maxn];     //储存树的信息 
int a[maxn][2],f[maxn][maxt],m=0,i,ti;
void build(int r)   //递归建树 
{ 
	te[r].t=2*a[r][0]; //走廊的时间消耗
	te[r].v=a[r][1];	//如果是叶子节点，则v等于画的个数，否则为0
	if (a[r][1]!=0)
	{
		te[r].ls=te[r].rs=-1;
		return;
	}
	te[r].ls=++m;build(m);
	te[r].rs=++m;build(m);
}
int dfs(int r,int i) //f[r][i] => 对于节点r，
{
	if (f[r][i]!=-1) return f[r][i];   //如果已有值，直接返回 
	if (i==0) return f[r][i]=0;        //时间没了，返回 
	if (te[r].ls==-1)       //走到了画室                             
	{
		if (te[r].v*5<i-te[r].t) return te[r].v; //能拿完 
		else return (i-te[r].t)/5;               //不能拿完 
	}
	int lt,rt;
	for (lt=0;lt<=i-te[r].t;lt++)      //枚举不同分法 
	{
		rt=i-te[r].t-lt;
		int s1=dfs(te[r].ls,lt);
		int s2=dfs(te[r].rs,rt);
		f[r][i]=max(f[r][i],s1+s2);
	}
	return f[r][i];
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d",&ti);
	while (scanf("%d%d",&a[i][0],&a[i][1])!=EOF) i++;
	build(m);
	printf("%d",dfs(0,ti));
	return 0;
}

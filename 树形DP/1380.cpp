#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> g[6000];                       //用vector存储每个节点的下属 
int f[60000][2],a[6000],b[6000],n;
void dfs(int k)                             //递归求解 
{
	for (int i=0;i<g[k].size();i++)       //搜索每一个子节点 
	{
		int h=g[k][i];
		dfs(h);
		f[k][0]+=max(f[h][1],f[h][0]);      //取或者不取，选择较大值 
		f[k][1]+=f[h][0];  //f[i][0]表示i不到场，所获得的最大的happy值       
	}
	f[k][1]+=a[k];
}

int main()
{    
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for (int i=1;;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==0&&y==0) break;
		g[y].push_back(x);            //储存y的子节点 
		b[x]=y;                        //储存x的父节点 
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)                //寻找根节点 
		{
			dfs(i);
			printf("%d",max(f[i][0],f[i][1]));
			break;
		}
	}
	return 0;
}

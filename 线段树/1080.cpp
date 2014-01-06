//一行N个方格，开始每个格子里都有一个整数。现在动态地提出一些问题和修改：提问的形式是求某一个特定的子区间[a,b]中所有元素的和；修改的规则是指定某一个格子x，加上或者减去一个特定的值A。现在要求你能对每个提问作出正确的回答。1≤N<100000，,提问和修改的总数m<10000条。
//线段树或者树状数组
#include <iostream>
#include <stdio.h>
#define MAXN 100005
using namespace std;
typedef struct Node{
	int l,h;
	int sum;
}Node;
Node TreeNode[5*MAXN];
int data[MAXN];
void build(int l,int h,int idx){
	TreeNode[idx].l = l;
	TreeNode[idx].h = h;
	TreeNode[idx].sum = 0;
	if(l==h)return;
	int mid = (l+h)>>1;
	build(l,mid,idx<<1);
	build(mid+1,h,idx<<1|1);
}
void update(int idx,int l,int d){
	TreeNode[idx].sum += d;
	if((l==TreeNode[idx].l) && (l == TreeNode[idx].h))
		return;
	int mid = (TreeNode[idx].l+TreeNode[idx].h)>>1;
	if(l<=mid)
		 update(idx<<1,l,d);
	else 
		 update(idx<<1|1,l,d);
}
int getResult(int idx,int l,int h){
	if(l == TreeNode[idx].l && h == TreeNode[idx].h){
		return TreeNode[idx].sum;
	}
	int mid = (TreeNode[idx].l+TreeNode[idx].h)>>1;
	if(h<=mid)
		return getResult(idx<<1,l,h);
	else if(l>mid)
		return getResult(idx<<1|1,l,h);
	else 
		return getResult(idx<<1,l,mid)+getResult(idx<<1|1,mid+1,h);
}
int main(){
	
	freopen("1080.txt","r",stdin);
	int N ;
	scanf("%d",&N);
	build(1,N,1);
	
	int data;
	for(int i = 1;i<=N;i++){
		scanf("%d",&data);		
		update(1,i,data);
	}
	int M;
	scanf("%d",&M);
	for(int i = 1;i<=M;i++)
	{
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if(t==1){
			update(1,a,b);
		}
		else {
			int result = getResult(1,a,b);
			printf("%d\n",result);
		}
	}

}
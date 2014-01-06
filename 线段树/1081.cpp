/*
给你N个数，有两种操作

1：给区间[a,b]的所有数都增加X

2：询问第i个数是什么？

*/
#include <iostream>
#include <stdio.h>
#define MAXN 100005
using namespace std;
typedef struct Node{
	int l,h;
	int sum;
	int added;
}Node;
Node tree[5*MAXN];
void build(int idx,int l,int h){
	tree[idx].l = l;
	tree[idx].h = h;
	tree[idx].sum = 0;
	tree[idx].added = 0;
	
	if(l==h) return ;
	int mid = (l+h)>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,h);
}
void updateS(int idx,int l,int s){
	tree[idx].sum += s;
	if(l==tree[idx].l && l == tree[idx].h){
		return;
	}
	int mid = (tree[idx].l+tree[idx].h)>>1;
	if(l<=mid)
		updateS(idx<<1,l,s);
	else if(l>mid)
		updateS(idx<<1|1,l,s);
}
void update(int idx,int l,int h,int d){
	if(l==tree[idx].l && h ==tree[idx].h){
		tree[idx].added += d;
		return;
	}
	tree[idx].sum += (tree[idx].h-tree[idx].l+1)*d;
	int mid = (tree[idx].l+tree[idx].h)>>1;
	if(h<=mid)
		update(idx<<1,l,h,d);
	else if(l>mid)
		update(idx<<1|1,l,h,d);
	else
	{
		update(idx<<1,l,mid,d);
		update(idx<<1|1,mid+1,h,d);
	}
}
void push_down(int idx,int added){
	tree[idx].added += added;
}
int getResult(int idx,int l){
	if(l==tree[idx].l && l==tree[idx].h)
		return tree[idx].sum+tree[idx].added;
	if(tree[idx].added!=0){ //value of added may be negtive
		tree[idx].sum += (tree[idx].h- tree[idx].l+1)*tree[idx].added;
		push_down(idx<<1,tree[idx].added);
		push_down(idx<<1|1,tree[idx].added);
		tree[idx].added = 0 ;
	}
	int mid = (tree[idx].l+tree[idx].h)>>1;
	if(l<=mid) 
		return getResult(idx<<1,l);
	else
		return getResult(idx<<1|1,l);
}
int main(){
	int n;
	freopen("1081.txt","r",stdin);
	scanf("%d",&n);
	build(1,1,n);
	for(int i = 1;i<=n;i++){
		int d;
		scanf("%d",&d);
		updateS(1,i,d);
	}
	int m;
	scanf("%d",&m);
	for(int i = 1;i<=m;i++){
		int t ;			int a,b,s;

		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&a,&b,&s);
			update(1,a,b,s);
		}
		else
		{
			scanf("%d",&a);
			printf("%d\n",getResult(1,a));
		}
	}
}

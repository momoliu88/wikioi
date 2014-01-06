#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
#define MAXN 30005
typedef struct node{
	int l , h ;
	int s;
}NODE;
NODE tree[MAXN*2];
void build(int idx,int l,int h){
	tree[idx].l = l;
	tree[idx].h = h;
	tree[idx].s = h-l+1;
	if(l==h)
		return ;
	int mid = (l+h)>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,h);
}
int update(int idx,int k){
	if(tree[idx].l == tree[idx].h){
		tree[idx].s -=1;
		return tree[idx].l;
	}
	tree[idx].s -=1;
	
	if(k<=tree[idx<<1].s)
		return update(idx<<1,k);
	else
		return update(idx<<1|1,k-tree[idx<<1].s);
}

vector<string> dequeue(int count, vector<string> queue) {
	int n = queue.size();
	int k = count;
	build(1,1,n);
	vector < string > ret ;
	ret.clear();
	int seq = 1;
	while(tree[1].s>0){
		seq = (seq+k-1)%tree[1].s;
		if(seq==0) seq = tree[1].s;
		int num = update(1,seq);
		ret.push_back(queue[num-1]);
	}
	return ret;
}

int main(){
	freopen("1282.txt","r",stdin);
	 vector < string > queue;
	 queue.push_back("a");
	 queue.push_back("b");
	 queue.push_back("c");
	 queue.push_back("d");
	 queue.push_back("e");
	 queue.push_back("f");
	 queue.push_back("g");
	 queue.push_back("h");
	
	 vector<string>ret = dequeue(4,queue);
	 for(int i = 0 ; i< ret.size();i++)
		 cout<<ret[i]<<endl;
 }
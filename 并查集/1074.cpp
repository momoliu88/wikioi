#include <iostream>
#define MAXN 50010
using namespace std;
int pa[MAXN];
int rank[MAXN];
//rank==2,表示子吃父亲；
//rank==1,表示父亲吃子；
//rank==0,同类
int find(int x){
	
	if(x == pa[x]) return x;
	int t= find(pa[x]);
	rank[x] = (rank[x]+rank[pa[x]])%3;
	pa[x] = t;
	return t;
}
bool join(int x,int y,int d){
	int fa = find(x);
	int fb = find(y);
	if(fa==fb)
		return (rank[x]-rank[y]+3)%3==d;
	pa[fa] = fb;
	rank[fa] = (d+rank[y]-rank[x]+3)%3;
	return true;
}
int main(){
	freopen("1074.txt","r",stdin);
	int N,K;
	cin>> N>>K;
	for(int i = 1; i <=N ;i++)
		pa[i] = i;
	memset(rank,0,sizeof(rank));
	int errors = 0;
	for(int i = 0 ; i< K;i++){
		int x,y,d;
		cin>>d>>x>>y;
		if(x>N || y>N) errors++;
		else if(x==y && d!=1) errors++;
		else if(join(y,x,d-1)==false) errors++;
	}
	cout<<errors<<endl;
}
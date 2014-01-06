#include <iostream>

using namespace std;
int pa[5010];
int find(int x){
	if(x==pa[x]) return x;
	int t = find(pa[x]);
	pa[x] = t;
	return t;
}
void join(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx==fy) return ;
	pa[fx] = fy;
	return ;
}
int main(){
	freopen("1073.txt","r",stdin);
	int n,m,q;
	int x,y;
	cin>>n>>m>>q;
	for(int i = 0 ; i<= n;i++)
		pa[i] = i;
	for(int i = 0 ; i < m;i++){
		cin >> x>>y;
		join(x,y);
	}
	for(int i = 0 ; i< q;i++)
	{
		cin >>x>>y;
		if(find(x)==find(y))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
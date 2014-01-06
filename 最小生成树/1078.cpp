#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Edge{
	int s,e;
	int w;
}Edge;
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
int pa[110];
int find(int x){
	if(x == pa[x]) return x;
	int t = find(pa[x]);
	pa[x] = t ;
	return t;
}
bool join(int a,int b){
	int fa = find(a);
	int fb = find(b);
	if(fa==fb) return false;
	pa[a] = b;
	return true;
}
int main(){
	int n ;
	int x;
	cin >> n;
	vector<Edge>edges;
	for(int i= 1 ; i<= n;i++){
		pa[i] = i;
		for(int j = 1 ; j <= n; j++){
			cin >> x;
			if(j<i){
				Edge edge;
				edge.s = i;
				edge.e = j;
				edge.w = x;
				edges.push_back(edge);
			}
		}
	}
	long long ans = 0 ;
	int l = 1 ; 
	sort(edges.begin(),edges.end(),cmp);
	for(int i = 0 ; i < edges.size();i++)
	{
		if(l<n &&join(edges[i].s,edges[i].e)){
			l++;
			ans += edges[i].w;
		}
	
	}
	cout << ans<<endl;
}
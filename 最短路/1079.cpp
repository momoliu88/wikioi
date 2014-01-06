#include <iostream>
#include <vector>
#include <map>
#include <queue>


using namespace std;
#define INF 0x1fffffff
#define MAXN 55
vector<pair<int,int> > dis[MAXN];
int d[MAXN];
bool inQ[MAXN];
int convert(char s){
	if(s>='a' && s<='z')
		return s-'a';
	if(s>='A' && s<='Z')
		return s-'A'+26;
}
void SPFA(int u){
	queue<int> Q;
	d[u] = 0 ;
	Q.push(u);
	inQ[u] = true;
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		for(int i = 0;i<dis[t].size();i++){
			int et = dis[t][i].first;
			int w = dis[t][i].second;			
			if(d[et]>w+d[t])
			{
				d[et] = w+d[t];
				if(!inQ[et]){
					Q.push(et);
					inQ[et] = true;
				}
			}		
		}
		inQ[t] = false;
	}
}
int main(){
	freopen("1079.txt","r",stdin);
	int N;
	cin>>N;
	char s,e;
	memset(inQ,false,sizeof(inQ));
	for(int i = 0;i<MAXN;i++)
		d[i] = INF;
	for(int i = 0;i<MAXN;i++)
			dis[i].clear();
	
	for(int i = 1;i<=N;i++){
		int t;
		cin>>s>>e>>t;
		int st = convert(s);
		int et = convert(e);	
		dis[st].push_back(make_pair(et,t));
		dis[et].push_back(make_pair(st,t));
	}
	
	int endP = convert('Z');
	SPFA(endP);
	int minN  = INF;
	int label;
	for(int i = 26;i<51;i++){
		if(d[i]< minN){
			minN = d[i];
			label = i;
		}
	}
	cout<<(char)(label-26+'A')<<" "<<minN<<endl;
 
}
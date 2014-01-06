//dp[m][i] = min (dp[m][i-1],dp[m-val[i]][i-1]+1)
#include <iostream>
#include <vector>
#define MAXN 1<<30
using namespace std;
int dp[MAXN][31];
int Fun(vector<int> weights,int m){
	for(int i = 1 ; i<=m;i++)
		for(unsigned int k = 0; k<= weights.size();k++)
			dp[i][k] = MAXN;
	dp[0][0] = 0 ;
	for(int i= 1; i<=m;i++){
		for(unsigned int k = 1; k <= weights.size();k++){
			dp[i][k]=dp[i][k-1];
			if(i>=weights[k-1])
				dp[i][k] = min(dp[i][k],dp[i-weights[k-1]][k-1]+1);
		}
	}
	return dp[m][weights.size()];
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>weights(n);
	for(int i = 0 ;  i < n; i++)
		cin>>weights[i];
	cout << Fun(weights,m)<<endl;
	return 0;
}
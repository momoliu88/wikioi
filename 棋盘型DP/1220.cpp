/*简单的dp 过了。*/
//dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n;
	cin >> n ;
	int num[n][n];
	memset(num,0,sizeof(num));
	for(int i = 0;i<n;i++)
		for(int j = 0 ; j <=i;j++){
			cin >> num[i][j];
		}
	int dp[n+1][n+1];
	for(int i = 0 ; i<=n;i++)
		for(int j = 0 ; j <=n;j++)
			dp[i][j] = -1000000;
	dp[1][1] = num[0][0];
	for(int i = 2; i<=n;i++)
		for(int j = 1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+num[i-1][j-1];
		}	
		int ans = dp[n][1];
		for(int i = 2;i<=n;i++)
			ans = max(ans,dp[n][i]);
		cout<<ans<<endl;
		return 0;
}
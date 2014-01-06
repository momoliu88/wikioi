//floyd
#include <iostream>
#include <string>
using namespace std;
#define MAXN 105
#define INF 100000000

int dis[MAXN][MAXN];
//int A[MAXN][MAXN];
void floyd(int n){
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
	{
			dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			dis[i][j] = INF;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	floyd(n);
	int q;
	scanf("%d",&q);
	for(int i = 1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",dis[a][b]);
	}
	return 0;
}

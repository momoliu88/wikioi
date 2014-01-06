//给出n个正整数，然后有m个询问，每个询问一个整数，询问该整数是否在n个正整数中出现过。
#include <iostream>
#include <set>
#include <string.h>

using namespace std;
bool sets[10^8+1];
int main(){
	int n,m;
	cin >> n>>m;
	memset(sets,false,sizeof(sets));
	for(int i = 0  ; i< n;i++){
		int t;
		cin>>t;
		sets[t] = true;
	}
	for(int i = 0 ; i< m; i++){
		int t ;
		cin >>t;
		if(sets[t])
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}

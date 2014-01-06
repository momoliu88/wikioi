#include <iostream>
#include <queue>

using namespace std;
typedef struct Dishu{
	int t,v;
}Dishu;
//这个一开始就想错了。应该是将地鼠按照时间进行排序，并逆序。将地鼠消失的时间当作地鼠开始出现的时间考虑。
bool cmp(Dishu a,Dishu b){
	if(a.t==b.t) return a.v<b.v;
	return a.t<b.t;
}

priority_queue<int,vector<int> > heap;
int main(){
	int n;
	cin >> n ;
	Dishu dishu[n];
	for(int i = 0 ; i < n ; i++)
		cin >> dishu[i].t;
	for(int i = 0 ; i < n ; i++)
		cin >> dishu[i].v;
	sort(dishu,dishu+n,cmp);
	int i = dishu[n-1].t;
	int j = n-1;
	long long  ans = 0 ;
	for(;i>=1;i--){
		while(j>=0 && dishu[j].t==i)heap.push(dishu[j].v),j--;
		if(heap.size()>0){
			ans += heap.top();
			heap.pop();
		}
	}
	cout<<ans<<endl;
}



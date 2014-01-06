#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cassert>
#include <ctime>
using namespace std;

int N, K;
map<long long,bool>mp;

int main() {
    map<long long,bool>::iterator it;
    int sum;
    while (scanf("%d %d", &N, &K) == 2) {
        sum = 0;
        mp.clear();
        int c;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &c);
            mp[c] = true;
        }
        int cnt;
        long long t;
        for (it = mp.begin(); it != mp.end(); ++it) {
            cnt = 0;
            long long t = it->first;
            while (mp[t]) //1,2,4,8
			{
                mp[t] = false;
                t = K * t;
                ++cnt;
            }
            sum += cnt / 2;
        }
        printf("%d\n", N - sum);
    }
    return 0;
}

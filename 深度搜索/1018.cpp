//http://blog.csdn.net/iwtwiioi/article/details/12913963
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string word[21];
int vis[21]; //2次为访问过2次
int n;
int ans = 0;
void dfs(string str, int o) //o是指是添加哪一个单词的下标
{
	if(vis[o] > 2) return; //如果添加的已经超过了2，则不判断
	//cout << str << endl;
	if(str.size() > ans) ans = str.size(); //更新最大值
	int i, j, k, pos;
	for(i = 1; i <= n; i++)
	{
		if(vis[i] < 2) //如果没有用到2次
		{
			//如果有包含关系 并且要取最后面的！注意！
			//如果两个单词接龙后的单词有多种情况，要尽可能保证接龙后的单词最长。例如cabab和ababc，
			//一定要接成cabababc，为而不是cababc。（也就是说在枚举确定两个单词是否可以相接时可以从后往前枚举）
			pos = -1;
			for(j = 1; j < str.size(); j++)
			{
				if(str[j] == word[i][0])
				{
					for(k = 1; k < word[i].size() && k+j < str.size(); k++)
						if(str[j+k] != word[i][k]) break;
					if(k+j == str.size() && k != word[i].size()) //有重合
						pos = j; //pos记录最后面那个能匹配的下标
				}

			}
			if(pos != -1) //有重合并且下标到最后一个
			{
				string t = str;
				t.append(word[i], k, word[i].size()-k+1); //添加除了重合部分的word进入新串
				if(t == str) continue;
				vis[i]++; //设置标志，this is a try
				dfs(t, i);
				vis[i]--; //清除标志，因为后面可能还会用到i,this is a backward
			}
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> word[i];
	char begin;
	cin >> begin;
	for(int i = 1; i<= n; i++)
		if(word[i][0] == begin)
		{
			vis[i]++; //初始赋值
			dfs(word[i], i);
			memset(vis, 0, sizeof(vis)); //要注意清除
		}
	cout << ans;
	return 0;
}
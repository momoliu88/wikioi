#include <iostream>
#include <stdlib.h>

using namespace std;

char* add(char *a, char *b, int m, int n)
{
	//m为两个字符串中最长的那个。否则代码错误。
	// 为结果分配内存空间。
	char *c = (char*)malloc((m + 2)* sizeof(char));
	memset(c, 0, (m + 2) * sizeof(char));
	// 将字符（0 + 0x30 到 9 + 0x30）转换为数字（0到9）进行计算。
	for (int i = m, j = n - 1; j >= 0; --i, --j)
		c[i] += (b[j] - '0');
	for (int i = m, j = m - 1; j >= 0; --i, --j)
	{
		c[i] += (a[j] - '0');
		if (c[i] > 9)
		{
			c[i - 1] += 1;
			c[i] -= 10;
		}
	}
	// 将由纯数字组成的结果转换为字符串，并去除首部可能还存在的零。
	c[m + 1] = 0;
	for (int i = 0; i < m + 1; ++i)
		c[i] += '0';
	if (c[0] == '0')
		for (int i = 0; c[i]; ++i)
			c[i] = c[i + 1];
	// 返回结果所在内存单元的首地址。
	return c;
}
int main(){
	char a[] = "99";
	char b[] = "99";
	char * c = add(a,b,strlen(a),strlen(b));
	for(int i = 0; c[i];i++)
		printf("%c",c[i]);
}
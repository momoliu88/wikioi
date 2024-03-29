#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
2、素数判断法：
这种方法是对上面方法的改进，上面方法是对2-sqrt(n)之间的数进行判断是否能除尽，而因为有如下算术基本定理，可以减少判断量。
算术基本定理：又称为素数的唯一分解定理，即：每个大于1的自然数均可写为素数的积，而且这些素因子按大小排列之后，写法仅有一种方式。例如:6936 = 2^3×3×17^2，1200 = 2^4×3×5^2。
由算术基本定理知，任何合数都可分解为一些素数的乘积，所以判断一个数能不能被2-sqrt(n)之间的素数整除即可。但是必须知道2-sqrt(n)之间的所有素数。

*/
int prime100[] = 
{
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
};
//若判断10000以内的数，需要知道100以内的所有素数          
int is_prime2(int n)
{
	int i;
	for(i=0;i<25;i++)
		if(n % prime100[i] == 0)
			return 0;
	return 1;
}
/*
这种方法可以找出一定范围内的所有的素数。
思路是，要求10000以内的所有素数，把1-10000这些数都列出来，1不是素数，划掉；2是素数，所有2的倍数都不是素数，划掉；取出下一个幸存的数，划掉它的所有倍数；直到所有幸存的数的倍数都被坏掉为止。

要找出10000以为的所有的素数，则需要一个大小为10000的数组,将其所有元素设置为未标记
首先把1设置为标记，从2开始，标记所有是它倍数的数，然后对下一个没有标记的数进行标记它的倍数。
当标记完成后，所有未标记的数即为素数。
这种算法需要O(n)的空间，不要偶数，可以节省一半的存储空间，标记需要O(n^2/logn)(我写的，不知道对不对),判断是否是素数只需要O(1)的时间。
*/
int a[10005];
void create_table()
{
    int i, tmp;
    memset(a, 0, sizeof(a));
    a[0] = 1;
    a[1] = 1;
    for(i=2;i<10000;i++)
    {
        if(!a[i])
        {
            tmp = i*2;
            while(tmp < 10000)
            {
                a[tmp] = 1;
                tmp += i;
            }
        }
    }
}
int is_prime3(int n)
{
    return !a[n];
}
int main(){
	create_table();
	for(int i = 1;i<10000;i++)
		if(!a[i])
		printf("%d\n",i);
}
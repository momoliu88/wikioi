//http://blog.csdn.net/re_cover/article/details/9499701

#include<stdio.h>
#include<string.h>
#define Max 505
char A[Max], B[Max];
int s[Max] = {0}, len_a, len_b;
void sub()
{
	int i, j;
	for(i = 0; A[i] == '0'; i++);
		j = i;
	for(; i < len_b; i++)
	    A[i] -= B[i] - '0';
	for(i = len_b - 1; i > j; i--)
	    if(A[i] < '0')
	    {
	    	A[i] += 10;
	    	A[i - 1]--;
	    }
}
int main()
{
	int i, j, k;
	scanf("%s %s", A, B);
	len_a = strlen(A);
	len_b = strlen(B);
	if(len_a < len_b || len_a == len_b && strncmp(A, B, len_b) < 0)
		printf("0");
	else
	{
		i = 0;
		while(1)
		{	//模拟的就是除法，如果直接把B配到和A一样长，在不停的减，时间复杂度会很高。
			while(strncmp(A, B, len_b) >= 0)
			{
				sub();
				s[i]++;
			}
			i++;			//商的位数，0是个位，1是十位，以此类推 
			if(len_a == len_b)
			    break;
			for(j = len_b - 1; j >= 0; j--)
		    	B[j + 1] = B[j];
			B[0] = '0';
			len_b++;
			B[len_b] == '\0';//模拟下除法操作就懂了
 		}
		k = 0;
		while(1)
		{
			if(s[k] == 0)
				k++;
			else
			    break;
		}
		for(; k < i; k++)
	    	printf("%d", s[k]);
	}
	return 0;
}
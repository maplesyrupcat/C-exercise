#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//递归求n的k次方
double my_pow(int n,int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k < 0)
	{
		return 1.0/my_pow(n, -k);
	}
	else
		return n*my_pow(n, k - 1);
}
int main()
{
	int n,k;
	scanf("%d%d", &n, &k);
	double pow = my_pow(n, k);
	printf("%.4f\n",pow);
}


//三种方法求二进制位中1的个数
int main()   //方法一
{
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < 32;i++)
	{
		if (((n >> i) & 1) == 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}
//方法二
int main()   
{
	int n,count=0;
	scanf("%d", &n);
	while (n)
	{
		n=n&(n - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}
//方法三
int count(unsigned int n)
{
	int counts=0;
	while (n)
	{
		if ((n & 1) == 1)
			counts++;
		n = n / 2;
	}
	return counts;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", count(n));
	return 0;
}
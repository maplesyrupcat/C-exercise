#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// ½«×Ö·û´®ÄæÐò
#include<string.h> 
#include<assert.h>
char* reverse(const char *pa)
{
	assert(pa);
	int len=strlen(pa);
	char* left = (char*)pa, *right = (char*)pa + len - 1;
	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
	return (char*)pa;
}
int main()
{
	char arr[100];
	gets(arr);
	printf("%s\n", reverse(arr));
	return 0;
}


 //¼ÆËã a+aa+aaa....
#include<math.h>
int main()
{
	int a, n, i;
	scanf("%d%d", &a, &n);
	int sum = 0, mid = a;
	for (i = 1; i <= n; i++)
	{
		sum += mid;
		mid += a*(int)pow(10, i);
	}
	for (i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j <=i ; j++)
		{
			printf("%d", a);
		}
		if (i < n - 1)
			printf("+");
	}
	printf("=%d\n", sum);
	return 0;
}


 //100-10000×ÔÃÝÊý
#include<math.h>
int main()
{
	int n;
	for (n = 100; n <= 100000; n++)
	{
		int ori_n = n;
		int count = 0;
		for (; ori_n>0; count++)
		{
			ori_n /= 10;
		}
		int sum = 0;
		ori_n = n;
		for (; ori_n>0;)
		{
			sum += (int)pow((ori_n % 10),count);
			ori_n /= 10;
		}
		if (!(sum - n))
			printf("%d\n", n);
	}
	return 0;
}
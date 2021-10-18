#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//求10个数最大公约数
int main()
{
	int arr[10] = { 0 };
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int min = arr[0];
	for (i = 0; i < 10; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	int m = 0, c[100];
	for (i = 1; i <= min; i++)
	{
		int j, no = 0;
		for (j = 0; j < 10; j++)
		{
			if (arr[j] % i)
			{
				no++;
				break;
			}
		}
		if (!no)
		{
			c[m] = i;
			m++;
		}
	}
	int max = c[0];
	for (i = 0; i < m; i++)
	{
		if (c[i]>max)
			max = c[i];
	}
	printf("%d\n", max);
	return 0;
}


//交换两个数组内容
#include<assert.h>
void print(int* p,size_t count)
{
	while (count--)
	{
		printf("%d ", *p++);
	}
	printf("\n");
}
void exchange(void* pa, void *pb, size_t count)
{
	assert(pa && pb);
	while (count--)
	{
		int tmp = *(char*)pa;
		*(char*)pa = *(char*)pb;
		*(char*)pb = tmp;
		++(char*)pa;
		++(char*)pb;
	}
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int b[10] = { 0 };
	print(a,10);
	print(b,10);
	exchange(a, b, sizeof(a));
	print(a, 10);
	print(b, 10);
	return 0;
}


//计算 1/1-1/2+1/3-1/4.....+1/99-1/100
int main()
{
	int k = 1;
	double sum = 0;
	int sign = 1;
	for (k = 1; k <= 100; k++)
	{
		sum += sign*(1.0 / k);
		sign *= (-1);
	}
	printf("%.2lf\n", sum);
	return 0;
}


//计算1到100的所有整数中出现多少个数字9
int main()
{
	int num = 9;
	int count = 0;
	for (num = 9; num < 100; num++)
	{
		int ori = num;
		if (!(ori % 10 - 9))
		{
			count++;
		}
		if (num >= 90)
			count++;
	}
	printf("%d\n", count);
	return 0;
}
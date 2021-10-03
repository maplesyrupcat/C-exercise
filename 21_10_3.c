#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include<math.h>
int ver(int age, int n, int k)
{
	int age_n = (int)pow(age, n);
	int count = 0;
	while (age_n)
	{
		age_n /= 10;
		count++;
	}
	if (!(count - k))
		return 1;
	else
		return 0;
}
void sort(int* pa, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int j;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (*(pa + j)>*(pa + j + 1))
			{
				int tmp = *(pa + j);
				*(pa + j) = *(pa + j + 1);
				*(pa + j + 1) = tmp;
			}
		}
	}
}
int ver2(int age, int n1, int n2)
{
	int age_a = (int)pow(age, n1);
	int age_b = (int)pow(age, n2);
	int arr[10] = { 0 };
	int count = 0, i;
	for (i = 0; i < 4; i++)
	{
		arr[i] = age_a % 10;
		age_a /= 10;
	}
	for (i = 4; i < 10; i++)
	{
		arr[i] = age_b % 10;
		age_b /= 10;
	}
	sort(arr, 10);
	for (i = 0; i < 10; i++)
	{
		int *pa = arr;
		if ((*(pa + i) - i))
			return 0;
	}
	return 1;
}
int main()
{
	int age;
	for (age = 10; age <= 40; age++)
	{
		if (!(ver(age, 3, 4) + ver(age, 4, 6) + ver2(age, 3, 4) - 3))
			printf("%d\n", age);
	}
	return 0;
}

#include<malloc.h>
typedef struct
{
	int len;
	int arr[];
}uncertain;
void searching(uncertain* p, int sz, int left, int right, int n)
{
	int no = 0;
	int middle = (right + left) / 2;
	if (left > right)
	{
		printf("找不到 %d\n", n);
		no = 1;
	}
	if ((p->arr[middle]) > n)
		right = middle - 1;
	else if ((p->arr[middle]) < n)
		left = middle + 1;
	else
	{
		printf("找到了 %d\n", n);
		no = 1;
	}
	if (no == 0)
		searching(p, sz, left, right, n);
}
int main()
{
	int len = 20;
	uncertain*p = (uncertain*)malloc(sizeof(uncertain)+sizeof(int)*len);
	int i, n;
	scanf("%d", &n);       //需要查找的数
	p->len = len;
	int sz = p->len;
	int right = sz - 1;
	int left = 0;
	for (i = 0; i <= p->len; i++)
	{
		p->arr[i] = i + i;
	}
	for (i = 0; i <= p->len; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	searching(p, sz, left, right, n);
	return 0;
}

#include<stdlib.h>
int cmp_double(const void*e1, const void*e2)
{
	if (((double*)e1 - (double*)e2) > 0)
		return 1;
	else if (((double*)e1 - (double*)e2) < 0)
		return -1;
	else
		return 0;
}
int main()
{
	double f[] = { 2.3, 3.4, 4, 5, 1.1, 2.8, 4.5, 7 };
	double* p = f;
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(*f), cmp_double);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%.2lf ", *p++);
	}
	return 0;
}
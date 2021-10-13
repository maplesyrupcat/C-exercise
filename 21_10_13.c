#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

¡‚–Œ–«Õº∞∏
int main()
{
	int line,i;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		int j;
		for (j = 0; j <line-i-1 ; j++)
		{
			printf(" ");
		}
		for (j = 0; j <2*(i+1)-1 ; j++)
		{
			printf("*");
		}
		for (j = 0; j <line - i-1; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	for (i = 1; i < line; i++)
	{
		int j;
		for (j = 0; j <i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <2*line-1-2*i; j++)
		{
			printf("*");
		}
		for (j = 0; j <i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}


∆Ê≈º∑÷ø™
#include<assert.h>
int* sort(int* pa, int sz)
{
	assert (pa);
	int i;
	for (i = 0; i < sz-1; i++)
	{
		int j;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (!((*(pa + j)) % 2 ))
			{
				if (!((*(pa + j + 1)) % 2 - 1))
				{
					int tmp = *(pa + j);
					*(pa + j) = *(pa + j + 1);
					*(pa + j + 1) = tmp;
				}
			}
		}
	}
	return pa;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(*arr);
	int*ret = sort(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *ret++);
	}
	return 0;
}


—Óª‘»˝Ω«
#include<assert.h>
int(*triangle(int(*pa)[10]))[10]
{
	assert(pa);
	int i;
	for (i = 0; i < 10; i++)
	{
		int j;
		for (j = 0; j <= i; j++)
		{
			if (!j || !(j-i))
				*((*(pa + i)) + j) = 1;
			else
			{
				if (i >= 2 && j >= 1)
					*((*(pa + i)) + j) = *((*(pa + i - 1)) + j) + *((*(pa + i - 1)) + j - 1);
			}
		}
	}
	return pa;
}
int main()
{
	int arr[10][10];
	int (*pa)[10]= triangle(arr);
	int i;
	for (i = 0; i < 10; i++)
	{
		int j;
		for (j = 0; j <= 10-(i+1); j++)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", *((*(pa + i)) + j));
		}
		printf("\n\n");
	}
	return 0;
}
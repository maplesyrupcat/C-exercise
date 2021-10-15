#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//猜凶手
int main()
{
	char killer;
	for (killer = 'a'; killer <= 'd';killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killer = %c\n", killer);
			break;
		}
	}
	return 0;
}


//字符串左旋，两种方法
#include<string.h>
#include<assert.h>
char* left_move(char *pa, int k)     //1.暴力法
{
	int len = strlen(pa);
	assert(pa);
	assert(k <= len);
	int j;
	for (j = 0; j < k;j++)
	{
		int i;
		int tmp = *pa;
		for (i = 0; i < len - 1; i++)
		{
			*(pa + i) = *(pa + i + 1);
		}
		*(pa + len - 1) = tmp;
	}
	return pa;
}
int main()
{
	char arr[100];
	int k;
	printf("输入一串字符串： ");
	gets(arr);
	printf("输入需要旋转的位数： ");
	scanf("%d", &k);
	char* ret=left_move(arr,k);
	printf("%s\n", ret);
	return 0;
}


#include<string.h>
#include<assert.h>
void reverse(char*p1, char*p2)    //2.三步翻转法
{
	assert(p1 && p2);
	for (; p1<p2; p1++,p2--)
	{
		int tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}
char* left_move(char *pa, int k)
{
	int len = strlen(pa);
	assert(pa && k<=len);
	reverse(pa, pa + k - 1);
	reverse(pa + k, pa + len - 1);
	reverse(pa, pa + len - 1);
	return pa;
}
int main()
{
	char arr[100];
	int k;
	printf("输入一串字符串： ");
	gets(arr);
	printf("输入需要旋转的位数： ");
	scanf("%d", &k);
	char* ret = left_move(arr, k);
	printf("%s\n", ret);
	return 0;
}


//判断一个字符串是否为另一个字符串旋转
#include<assert.h>
#include<string.h>
char* left_move(char* p,int len)     //1.暴力法
{
	int i, tmp = *p;
	for (i = 0; i < len - 1; i++)
	{
		*(p + i) = *(p + i + 1);
	}
	*(p + len - 1) = tmp;
	return p;
}
int is_left_move(char* p1, char* p2)
{
	assert(p1 && p2);
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	if (len1 != len2)
		return 0;
	int i;
	for (i = 0; i < len1; i++)
	{
		if (strcmp(left_move(p1, len1), p2) == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char arr1[100];
	char arr2[100];
	gets(arr1);
	gets(arr2);
	int ret=is_left_move(arr1, arr2);
	if (ret == 1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}

#include<assert.h>
#include<string.h>
int is_left_move(char*p1, char*p2)     //2.子串法
{
	assert(p1 && p2);
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	if (len1 != len2)
		return 0;
	strncat(p1, p1, len1);
	char* ret = strstr(p1, p2);
	if (ret == NULL)
		return 0;
	else
		return 1;
}
int main()
{
	char arr1[100];
	char arr2[100];
	gets(arr1);
	gets(arr2);
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
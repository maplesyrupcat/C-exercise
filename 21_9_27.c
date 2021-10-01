#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//求前n项阶乘的和
int main()
{
	int i = 0;
	int sum = 0;
	int n = 0;
	int ret = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int j = 0, ret = 1;
		for (j = 1; j <= i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n",sum);
	return 0;
}

//定义字符串复制
#include <assert.h>
char* my_strcpy(char* dest, const char* sor)//const保证source指向的值不能被改变
{
	char* init = dest;         //保存destination起始地址
	assert(sor != NULL);       //保证传过来不是空指针
	assert(dest != NULL);
	while (*dest++ = *sor++)      //直到source指向的值为'\0'，对应ASCII码为0，则跳出循环
	{
		;                    //将source指向的值赋值给destination指向的值
	}
	return init;
}
int main()
{
	char a[] = "####################";
	char b[] = "hello world";
	printf("%s\n", my_strcpy(a, b));
	return 0;
}

//定义求字符串长度函数
#include <assert.h>
int my_strlen(const char* pa)
{
	assert(pa != NULL);
	int count = 0;
	while (*pa++!='\0')
	{
		count++;
	}
	return count;
}
int main()
{
	char a[20] = {'0'};
	int i = 0;
	while ((a[i] = getchar())&& (a[i] != '\n'))
	{
		i++;
	}
	a[i] = '\0';
	printf("%d\n", my_strlen(a));
	return 0;
}

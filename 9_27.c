#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//��ǰn��׳˵ĺ�
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

//�����ַ�������
#include <assert.h>
char* my_strcpy(char* dest, const char* sor)//const��֤sourceָ���ֵ���ܱ��ı�
{
	char* init = dest;         //����destination��ʼ��ַ
	assert(sor != NULL);       //��֤���������ǿ�ָ��
	assert(dest != NULL);
	while (*dest++ = *sor++)      //ֱ��sourceָ���ֵΪ'\0'����ӦASCII��Ϊ0��������ѭ��
	{
		;                    //��sourceָ���ֵ��ֵ��destinationָ���ֵ
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

//�������ַ������Ⱥ���
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

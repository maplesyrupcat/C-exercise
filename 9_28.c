#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�жϵ�ǰϵͳ�Ǵ�˴���ģʽ����С�˴���ģʽ
int check_sys()
{
	int a = 1;
	return *(char*)&a;  //��aȡ��ַ��ǿ��ת��Ϊchar*���ͷ���һ���ֽڣ�������һ���ֽڵ�ֵ��ӷ���
}
int main()
{
	int ret = check_sys();   //������Ϊ1�����ʾС�ˣ�������Ϊ0�����ʾ���
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}

int main()       //��ѭ������
{
	unsigned int i;
	for (i = 9; i >= 0; i++)
	{
		printf("%u\n", i);
	}
	return 0;
}

//�ַ�ָ��
int main()
{
	char arr[] = "abcdef";
	char* p = arr;           //arr��ʾ��Ԫ�ص�ַ��&arr��ʾȡ���������ַ
	printf("%s\n", arr);    //����Ԫ�ص�ַ��ʼ�����ַ�����ʽ��ӡ������'\0'����
	printf("%s\n", p);     //�ȼ�
	return 0;
}

int main()
{
	char* p= "abcdef";   //abcdef��ʾ�����ַ�����pʵ�ʴ�����Ԫ�ص�ַ
	printf("%c\n", *p);    //��ӡ��Ԫ��
	printf("%s\n", p);    //��ӡ�ַ��������׵�ַ��ʼ��ӡ��ֱ��'\0'����
	return 0;
}

//ָ������
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 2, 3, 4, 5, 6 };
	int arr3[] = { 3, 4, 5, 6, 7 };
	int* parr[] = { arr1, arr2, arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d  ", *(parr[i] + j));
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5, 6 };
	int c[] = { 7, 8, 9 };
	int* p[] = { a, b, c };   //a,b,c�ֱ��ʾ��Ԫ�ص�ַ
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(p[i] + j));
		}
		printf("\n");
	}
	return 0;
}

void print(int(*p)[5],int x,int y)  //����ָ��
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			//printf("%d ", p[i][j]);              //���ֵȼ�
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", (*(p + i))[j]);
			//printf("%d ", *(p[i] + j));
		}
		printf("\n");
	}
}
int main()
{
	int a[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
	print(a,3,5);
	return 0;
}

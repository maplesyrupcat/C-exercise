#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//判断当前系统是大端储存模式还是小端储存模式
int check_sys()
{
	int a = 1;
	return *(char*)&a;  //对a取地址并强制转化为char*类型访问一个字节，并对这一个字节的值间接访问
}
int main()
{
	int ret = check_sys();   //若返回为1，则表示小端，若返回为0，则表示大端
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}

int main()       //死循环案例
{
	unsigned int i;
	for (i = 9; i >= 0; i++)
	{
		printf("%u\n", i);
	}
	return 0;
}

//字符指针
int main()
{
	char arr[] = "abcdef";
	char* p = arr;           //arr表示首元素地址，&arr表示取整个数组地址
	printf("%s\n", arr);    //从首元素地址开始，以字符串形式打印，遇到'\0'结束
	printf("%s\n", p);     //等价
	return 0;
}

int main()
{
	char* p= "abcdef";   //abcdef表示常量字符串，p实际储存首元素地址
	printf("%c\n", *p);    //打印首元素
	printf("%s\n", p);    //打印字符串，从首地址开始打印，直到'\0'结束
	return 0;
}

//指针数组
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
	int* p[] = { a, b, c };   //a,b,c分别表示首元素地址
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

void print(int(*p)[5],int x,int y)  //数组指针
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			//printf("%d ", p[i][j]);              //四种等价
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

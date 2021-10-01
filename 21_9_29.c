#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void print1(int(*p)[5], int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", p[i][j]);
			//printf("%d ", *(p[i] + j));
			//printf("%d ", (*(p + i))[j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
	print1(arr, 3, 5);
	return 0;
}

void Print1(char* str)    //函数指针
{
	printf("%s\n", str);
}
int main()
{
	void(*p)(char*)=Print1;//&Print
	(*p)("hello world");
	return 0;
}


double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
double mul(double x, double y)
{
	return x * y;
}
double div(double x, double y)
{
	return x / y;
}
void menu()
{
	printf("  ********************************\n");
	printf("         迷 你 计 算 器         \n");
	printf("     1.加法运算    2.减法运算   \n");
	printf("     3.乘法运算    4.除法运算   \n");
	printf("             0.退出             \n");
}
int main()
{
	menu();
	double x, y;
	int input;
	double(*parr[5])(double, double) = { 0, add, sub, mul, div };
	do
	{
		printf("\n\n请输入你需要的选项： ");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("\n请输入两个数字： ");
			scanf("%lf%lf", &x, &y);
			double ret = parr[input](x, y);
			printf("\n计算结果为：%.8lf\n", ret);
		}
		else if (input == 0)
		{
			printf("退出\n");
			break;
		}
		else
			printf("输入错误\n\n");
	} while (input);
	return 0;
}

void print(char* str)
{
	printf("%s\n", str);
}
void test(void(*p)(char*))
{
	p("hello world");
}
int main()
{
	test(print);
	return 0;
}

double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
double mul(double x, double y)
{
	return x*y;
}
double div(double x, double y)
{
	return x / y;
}
int main()
{
	int input;
	double a, b;
	do
	{
		double(*pfarr[])(double, double) = { 0, add, sub, mul, div };
		printf("请输入选项： ");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个数字： ");
			scanf("%lf%lf", &a, &b);
			double ret =(*(*(pfarr+input)))(a,b);
			printf("结果为：%.8lf\n", ret);
		}
		else if (input == 0)
			printf("退出\n");
		else
			printf("\n错误，请重新输入\n");
	} while (input);
	return 0;
}

double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
double mul(double x, double y)
{
	return x*y;
}
double div(double x, double y)
{
	return x / y;
}
void mid(double(*pf)(double, double))
{
	double a, b;
	printf("请输入两个数字： ");
	scanf("%lf%lf", &a, &b);
	double ret=(*pf)(a, b);
	printf("结果为: %.8lf\n", ret);
}
int main()
{
	int input;
	double ret = 0;
	do
	{
		printf("输入选项： ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			mid(add);
			break;
		case 2:
			mid(sub);
			break;
		case 3:
			mid(mul);
			break;
		case 4:
			mid(div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("重新输入\n");
		}
	} while (input);
	return 0;
}
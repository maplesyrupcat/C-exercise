



//1.判断 100-200之间的素数
#include<math.h>
int main()
{
	int num;
	for (num = 101; num < 200; num=num+2)
	{
		int i , no = 0;
		for (i = 2; i < sqrt(num); i++)
		{
			if (!(num%i))
			{
				no++;
				break;
			}
		}
		if (!no)
			printf("%d\n", num);
	}
	return 0;
}


//2.打印乘法口诀表
int main()
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		int j;
		for (j = 1; j <= i; j++)
		{
			printf("%d×%d = %-2d  ", j, i, j*i);
		}
		printf("\n");
	}
	return 0;
}


//3.判断1000-2000年的闰年
int main()
{
	int year = 1000;
	for (year = 1000; year <= 2000; year++)
	{
		if (!(year % 4) && (year % 100))
			printf("%d\n", year);
		else if(!(year % 400))
			printf("%d\n", year);
		else;
	}
	return 0;
}


//4.不创建临时变量，交换两数值
int main()
{
	int a = 10;
	int b = 20;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d,b=%d\n", a, b);
	return 0;
}

//杨氏矩阵查找
#include <assert.h>
int find(int(*pa)[3], int n, int*px, int*py)
{
	assert(pa && px && py);
	int x = *px - *px;
	int y = *py - 1;
	while (x <= *px - 1 && y>=0)
	{
		if (*(*(pa + x) + y) < n)
			x++;
		else if (*(*(pa + x) + y) > n)
			y--;
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n;
	int x = 3, y = 3;
	scanf("%d", &n);
	int ret=find(arr, n, &x, &y);
	if (ret == 1)
	{
		printf("find if %d, its subscript are %d %d\n", n, x, y);
	}
	else
		printf("can't find it\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 2, 3, 4 };
	int c[] = { 3, 4, 5 };
	int* p[] = { a, b, c };
	int i;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 3; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", *(p[i] + j));
		}
		printf("\n");
	}
	return 0;
}

void print(int(*p)[3], int x, int y)
{
	int i;
	for (i = 0; i < x; i++)
	{
		int j;
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));
			printf("%d ", p[i][j]);
			printf("%d ", *(p[i] + j));
			printf("%d ", (*(p + i))[j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	print(arr, 3, 3);
	return 0;
}

#include<string.h>
typedef struct
{
	int age;
	char name[10];
}stu;
void p_int(void*base, int sz)
{
	int*p = (int*)base;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p++);
	}
	printf("\n");
}
void p_double(void*base, int sz)
{
	double*p = (double*)base;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%.2lf ", *p++);
	}
	printf("\n");
}
void p_s_age(void*base, int sz)
{
	stu*p = (stu*)base;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", (p++->age));
	}
	printf("\n");
}
void p_s_name(void*base, int sz)
{
	stu*p = (stu*)base;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", (p++->name));
	}
	printf("\n");
}
int cmp_int(void*e1, void*e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_double(void*e1, void*e2)
{
	if ((*(double*)e1 - *(double*)e2) > 0)
		return 1;
	else if ((*(double*)e1 - *(double*)e2) < 0)
		return -1;
	else
		return 0;
}
int cmp_struct_age(void*e1, void*e2)
{
	return ((stu*)e1)->age - ((stu*)e2)->age;
}
int cmp_strcut_name(void*e1, void*e2)
{
	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
}
void swap(char* b1, char*b2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		int tmp = *b1;
		*b1 = *b2;
		*b2 = tmp;
		b1++;
		b2++;
	}
}
void bubble_sort(void*base, int num, int width, int(*cmp)(void*e1, void*e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
void sort_print(void*base, int sz, int width, int(*cmp)(void*e1, void*e2), int form)
{
	bubble_sort(base, sz, width, cmp);
	void(*pf[])(base, sz) = { p_int, p_double, p_s_age, p_s_name };
	(*(pf + form))(base, sz);
}
int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz_a = sizeof(arr) / sizeof(*arr);
	double lf[] = { 3.3, 2.5, 7.7, 1.9, 3.6, 2.0, 6.6, 12.3, 5.8, 1.2 };
	int sz_lf = sizeof(lf) / sizeof(*lf);
	stu s[] = { { 10, "alice" }, { 20, "bob" }, { 15, "cindy" } };
	int sz_s = sizeof(s) / sizeof(*s);
	sort_print(arr, sz_a, sizeof(*arr), cmp_int, 0);
	sort_print(lf, sz_lf, sizeof(*lf), cmp_double, 1);
	sort_print(s, sz_s, sizeof(*s), cmp_struct_age, 2);
	sort_print(s, sz_s, sizeof(*s), cmp_strcut_name, 3);
	return 0;
}

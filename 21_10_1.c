#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void bubble_sort(int arr[],int sz)
{
	int i;
	for (i = 0; i < sz - 1; i++)
	{
		int j,temp;
		for (j = 0; j < sz - 1-i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int*p = arr;
	int i;
	bubble_sort(arr,sz);
	for (i=0; i < sz; i++,p++)
	{
		printf("%d ", *p);
	}
	return 0;
}

#include<string.h>
#include<stdlib.h>
typedef struct stu
{
	char name[20];
	int age;
}stu;
void p_int(void*a,int sz)
{
	int i, *p = (int*)a;
	for (i = 0; i < sz; i++, p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
}
void p_double(void*a, int sz)
{
	int i;
	double*p = (double*)a;
	for (i = 0; i < sz; i++, p++)
	{
		printf("%.2lf ", *p);
	}
	printf("\n");
}
void p_str_ch(void*a, int sz)
{
	int i;
	stu*p = (stu*)a;
	for (i = 0; i < sz; i++, p++)
	{
		printf("%s ", p->name);
	}
	printf("\n");
}
void p_str_int(void*a, int sz)
{
	int i;
	stu*p = (stu*)a;
	for (i = 0; i < sz; i++, p++)
	{
		printf("%d ", p->age);
	}
	printf("\n");
}
int cmp_arr(const void*e1, const void*e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_lf(const void*e1, const void*e2)
{
	double sub = (*(double*)e1 - *(double*)e2);
	if (sub > 0)
		return 1;
	else if (sub < 0)
		return -1;
	else
		return 0;
}
int cmp_s_age(const void*e1, const void*e2)
{
	return ((stu*)e1)->age - ((stu*)e2)->age;
}
int cmp_s_name(const void*e1, const void*e2)
{
	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
}
void sort_print(int form,void*a, int sz,int one_size,int(*pf)(const void*,const void*))
{
	
	qsort(a, sz, one_size, pf);
	void(*printf_form[])(void*, int) = { p_int, p_double,p_str_int,p_str_ch };
	(*(printf_form + form))(a, sz);
}
int main()
{
	
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };    //�������鼰Ԫ�ظ���
	int sz_a = sizeof(arr) / sizeof(arr[0]);

	double lf[] = { 9.0, 8.88, 7.0, 4.0, 1.1 };   //���������鼰Ԫ�ظ���
	int sz_f = sizeof(lf) / sizeof(lf[0]);

	stu s[] = { { "Alice", 30 }, { "Bob", 20 }, { "Dave", 40 }, { "Cindy", 10 } };
	int sz_s = sizeof(s) / sizeof(s[0]);         //�ṹ�����鼰Ԫ�ظ���

	sort_print(0,arr, sz_a,sizeof(*arr) ,cmp_arr);     //���򼰴�ӡ arr
	sort_print(1,lf, sz_f, sizeof(*lf), cmp_lf);       //���򼰴�ӡ lf
	sort_print(2,s, sz_s, sizeof(*s), cmp_s_age);     //�����������ӡ s
	sort_print(3,s, sz_s, sizeof(*s), cmp_s_name);     //�����������ӡ s
	return 0;
} 
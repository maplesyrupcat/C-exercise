#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// 建立一个顺序表,并完成初始添项，插入，删除
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct     //数据
{
	//一些数据项
	char name[20];
	int _class;
}Elemtype;
#define INIT_SIZE 5    //初始容量
#define SIZE_ADD 2     //每次增加容量
typedef struct       //中间结构体，包含数据结构体及相关关键信息
{
	Elemtype* elem;    //数据储存位置
	int length;        //当前长度
	int listsize;      //当年总容量
}Sqlist;
void Init_list(Sqlist* L)  //初始化
{
	L->elem = (Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));   //分配总容量对应大小的空间
	if (!(L->elem))
		return;
	L->length = 0;               //空表初始长度为0
	L->listsize = INIT_SIZE;     //初始总容量
	return;
}
void Add_list(Sqlist* L)   //加入数据
{
	int choice;
	do
	{
		scanf("%d", &choice);   //输入选择，任意值为添加，0为退出
		if (choice)
		{
			if (L->length >= L->listsize)              //若表已满，长度等于总容量
			{
				Elemtype* newbase = realloc(L->elem,
					(L->listsize + SIZE_ADD)*sizeof(Elemtype));     //增加分配
				if (!newbase)
				{
					printf("%s\n", strerror(errno));     //考虑分配失败情况
					return;
				}
				L->elem = newbase;
				L->listsize += SIZE_ADD;    //分配成功，储存总容量增加
			}
			scanf("%s", (L->elem[L->length]).name);
			scanf("%d", &((L->elem[L->length])._class));      //添加信息
			L->length++;                               //添加完表长+1
		}
	} while (choice);
}
void List_insert(Sqlist* L, int i, Elemtype e)
{
	//在第i个元素前插入新元素，1<=i<=listsize+1  (listsize+1表示插入到末尾）
	if (i<1 || i>L->listsize + 1)
		return;                          //判断i的合法性
	if (L->length >= L->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(L->elem,
			(L->listsize + SIZE_ADD)*sizeof(Elemtype));
		if (!newbase)
		{
			printf("%s\n", strerror(errno));     //考虑分配失败情况
			return;
		}
		L->elem = newbase;
		L->listsize += SIZE_ADD;      //分配成功，储存总容量增加
	}
	int k;
	for (k = L->length - 1; k >= i - 1; k--)   //从最后一位开始右移，直到编号为i-1（第i个）
	{
		L->elem[k + 1] = L->elem[k];
	}
	L->elem[i - 1] = e;       //第i个插入e
	L->length++;            //表长增加
	return;
}
void List_delete(Sqlist* L, int i)
{
	//删除第i个元素
	if (i<1 || i>L->listsize)
		return;                          //判断i的合法性
	int k;
	for (k = i; k < L->length; k++)      //从第i+1个开始，以此往前移动
	{
		L->elem[k - 1] = L->elem[k];
	}
	L->length--;                         //表长减少
	return;
}
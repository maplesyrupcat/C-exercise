#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// ����һ��˳���,����ɳ�ʼ������룬ɾ��
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct     //����
{
	//һЩ������
	char name[20];
	int _class;
}Elemtype;
#define INIT_SIZE 5    //��ʼ����
#define SIZE_ADD 2     //ÿ����������
typedef struct       //�м�ṹ�壬�������ݽṹ�弰��عؼ���Ϣ
{
	Elemtype* elem;    //���ݴ���λ��
	int length;        //��ǰ����
	int listsize;      //����������
}Sqlist;
void Init_list(Sqlist* L)  //��ʼ��
{
	L->elem = (Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));   //������������Ӧ��С�Ŀռ�
	if (!(L->elem))
		return;
	L->length = 0;               //�ձ��ʼ����Ϊ0
	L->listsize = INIT_SIZE;     //��ʼ������
	return;
}
void Add_list(Sqlist* L)   //��������
{
	int choice;
	do
	{
		scanf("%d", &choice);   //����ѡ������ֵΪ��ӣ�0Ϊ�˳�
		if (choice)
		{
			if (L->length >= L->listsize)              //�������������ȵ���������
			{
				Elemtype* newbase = realloc(L->elem,
					(L->listsize + SIZE_ADD)*sizeof(Elemtype));     //���ӷ���
				if (!newbase)
				{
					printf("%s\n", strerror(errno));     //���Ƿ���ʧ�����
					return;
				}
				L->elem = newbase;
				L->listsize += SIZE_ADD;    //����ɹ�����������������
			}
			scanf("%s", (L->elem[L->length]).name);
			scanf("%d", &((L->elem[L->length])._class));      //�����Ϣ
			L->length++;                               //������+1
		}
	} while (choice);
}
void List_insert(Sqlist* L, int i, Elemtype e)
{
	//�ڵ�i��Ԫ��ǰ������Ԫ�أ�1<=i<=listsize+1  (listsize+1��ʾ���뵽ĩβ��
	if (i<1 || i>L->listsize + 1)
		return;                          //�ж�i�ĺϷ���
	if (L->length >= L->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(L->elem,
			(L->listsize + SIZE_ADD)*sizeof(Elemtype));
		if (!newbase)
		{
			printf("%s\n", strerror(errno));     //���Ƿ���ʧ�����
			return;
		}
		L->elem = newbase;
		L->listsize += SIZE_ADD;      //����ɹ�����������������
	}
	int k;
	for (k = L->length - 1; k >= i - 1; k--)   //�����һλ��ʼ���ƣ�ֱ�����Ϊi-1����i����
	{
		L->elem[k + 1] = L->elem[k];
	}
	L->elem[i - 1] = e;       //��i������e
	L->length++;            //������
	return;
}
void List_delete(Sqlist* L, int i)
{
	//ɾ����i��Ԫ��
	if (i<1 || i>L->listsize)
		return;                          //�ж�i�ĺϷ���
	int k;
	for (k = i; k < L->length; k++)      //�ӵ�i+1����ʼ���Դ���ǰ�ƶ�
	{
		L->elem[k - 1] = L->elem[k];
	}
	L->length--;                         //������
	return;
}
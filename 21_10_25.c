#define _CRT_SECURE_NO_WARNINGS 1
#include"����.h"

typedef int Elemtype;

struct SLTNode
{
	Elemtype data;
	struct SLTNode* next;
};
typedef struct SLTNode SLTNode;
void SLTNodePrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuyListNode(Elemtype e)      //����һ���½ڵ�
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) exit(-1);
	newnode->data = e;
	newnode->next = NULL;
	return newnode;
}

void SLTNodePushBack(SLTNode** pphead, Elemtype e)    //β������
{
	SLTNode* newnode = BuyListNode(e);
	if (*pphead == NULL)
		*pphead = newnode;
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SLTNodePushFront(SLTNode** pphead, Elemtype e)   //ͷ������
{
	SLTNode* newnode = BuyListNode(e);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTNodePopBack(SLTNode** pphead)   //β��ɾ��
{
	if (*pphead == NULL)
		return;
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* cur = *pphead;
		SLTNode* prev = NULL;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
		cur = NULL;
	}
}

void SLTNodePopFront(SLTNode** pphead)   //ͷ��ɾ��
{
	if (!*pphead)
		return;
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SLTFind(SLTNode* phead, Elemtype e, Elemtype(*cmp)(Elemtype, Elemtype))   //����
{
	SLTNode* cur = phead;
	while (cur != NULL)    //cur��=NULL �� cur->next!=NULL ����
	{
		if (!cmp(e, cur->data))
			return cur;
		cur = cur->next;
	}
	return NULL;
}
Elemtype cmp(Elemtype e1, Elemtype e2)  //�û��Լ�ʵ�е���Ԫ�رȽϺ���
{
	return e1 - e2;
}

void SLTInsert(SLTNode** pphead, SLTNode *pos, Elemtype e) //��posǰ����Ԫ��
{
	if (pos == *pphead)
	{
		SLTNodePushFront(pphead, e);
		return;
	}
	SLTNode* newnode = BuyListNode(e);
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	newnode->next = prev->next;
	prev->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode *pos)  //ɾ��pos
{
	if (pos == *pphead)
	{
		SLTNodePopFront(pphead);
		return;
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}
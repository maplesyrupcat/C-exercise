#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef int Elemtype;
//1.˫���ͷѭ������ṹ
//  һ��Ԫ�ذ��������֣����������ݣ���һָ�룬��һָ��
struct ListNode
{
	Elemtype data;
	struct ListNode* next;
	struct ListNode* prev;
};
typedef struct ListNode ListNode;

//2. ��ʼ��
//2.1 �����½ڵ㣨�½ڵ�ĳ�ʼ����
//    �½����ڵ㼴����һ��Ԫ�صĿռ䣬��data��Ϊe����prev��ΪNULL����next��ΪNULL
ListNode* BuyListNode(Elemtype e)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = e;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
//2.2 ��ĳ�ʼ���������ڱ�λ��
//    ��ͷ������Ҫ��ʼ����������һ���ڱ���˫��ѭ����ͷ�����ڱ���next��prev��ָ���Լ�������������ʹ������������
void Init_List(ListNode** pphead)  //��һ�ַ�ʽ������NULL�������ڱ����ö���ָ�����(�ı��ⲿpheadֵ)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
ListNode* Init_List2()             //�ڶ��ַ�ʽ�������Σ�ֱ���ں����ڽ����ڱ������أ��ٺ��������
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//�벻��ͷ������ȣ�������ĵ�һ��Ԫ��Ϊphead->next,��ΪpheadΪ�ڱ�����ǰ�������һ��Ԫ��Ϊphead
//ǰ������ձ�״̬ΪNULL����������ձ�״̬Ϊphead=�ڱ�


//3.������
//3.1 β������
void ListPushBack(ListNode* phead, Elemtype e)
{
	assert(phead);
	ListNode* newnode = BuyListNode(e);
	ListNode*tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	//�ڱ���prev�ҵ�β������ִ�в���
}

//3.2 ͷ������
void ListPushFront(ListNode* phead, Elemtype e)
{
	assert(phead);
	ListNode* newnode = BuyListNode(e);
	ListNode* first = phead->next;    //���Բ�����first��ֱ����������ʾ������Ҫע��˳��
	first->prev = newnode;
	newnode->next = first;
	phead->next = newnode;
	newnode->prev = phead;
	//�ڱ���next�ҵ�ͷ������ִ�в���
}

//3.3 β��ɾ��
void ListPopBack(ListNode* phead)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	if (phead->next == phead) return;  //����û�����ݵ������ֻʣ�ڱ���
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}

//3.4 ͷ��ɾ��
void ListPopFront(ListNode* phead)
{
	assert(phead);
	ListNode* first = phead->next;
	if (phead->next == phead) return; //����û�����ݵ������ֻʣ�ڱ���
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
	first = NULL;
}

//3.5 ����
Elemtype cmp(Elemtype e1, Elemtype e2)
{
	return e1 - e2;
}
ListNode* ListFind(ListNode* phead, Elemtype e)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (!cmp(e, cur->data))
			return cur;
		cur = cur->next;
	}
	return NULL;
	//ע�⣬cur��phead->next��ʼ����
}


//3.6 �в�����
void ListInsert(ListNode* pos, Elemtype e)   //���������ӱ�ͷ��ʼ����˫���������ֱ�Ӵ�pos��ʼ��ǰ���Ԫ�ض����ҵ�
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode*newnode = BuyListNode(e);
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
	//ͷ��β��Ҳ���Ե��������������pos�ֱ�Ϊphead��phead->prev
}

//3.7 �в�ɾ��
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
	//ͷɾβɾҲ���Ե��������������pos�ֱ�Ϊphead->next��phead->prev
}

//3.8 ��ӡ
void ListPrint(ListNode* phead)  //������Ҳ����������
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//3.9 �鲢 ��

//4. �ܽ�
//���ŵ�����ṹ��������λ�ò���ɾ������ʱ�临�ӶȾ�ΪO(1)������ΪO(N);(��������Ϊ��AVL�������������ϣ��B����B+����)
//�����ṹ������data����һָ��prev����һָ��next�������½ڵ��ʼ��ʱ��data=e��prev��next=NULL
//��ǰһ��������ȣ�����������Ҫ��ʼ�����������ڱ����ڱ��Ĵ��켴�ɱ�֤��ʼ�ղ�Ϊ��NULL�����ձ�״̬Ϊֻ���ڱ���״̬,��һ��Ԫ��Ϊphead->next
//�ڱ���prev��next��ָ���Լ���ʹɾ�����������Ҫ���ǵ����⣨��ֻʣһ��Ԫ�أ��ձ�ȣ�����
//��������ȫ�̲����У���Ҫ��֤�����phead��ΪNULL�����ڱ����ڵ����
//����phead������Ҫ������ָ�룬��Ϊ����Ҫ�ı��ⲿ��phead
//ɾ��Ԫ��ͬʱҪ��֤������Ԫ�أ���phead->next��=phead���������ڱ�ɾ��
//�в������ɾ������ֱ�Ӵ���pos����������һ������һ����ͷ��ʼѰ��pos

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef int Elemtype;
//1.双向带头循环链表结构
//  一个元素包含三部分，即所需数据，下一指针，上一指针
struct ListNode
{
	Elemtype data;
	struct ListNode* next;
	struct ListNode* prev;
};
typedef struct ListNode ListNode;

//2. 初始化
//2.1 创建新节点（新节点的初始化）
//    新建立节点即开辟一个元素的空间，将data置为e，将prev置为NULL，将next置为NULL
ListNode* BuyListNode(Elemtype e)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = e;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
//2.2 表的初始化（创造哨兵位）
//    带头链表需要初始化，即建立一个哨兵，双向循环带头链表，哨兵的next和prev均指向自己，此做法可以使后续操作大大简化
void Init_List(ListNode** pphead)  //第一种方式，传入NULL，建立哨兵，用二级指针接受(改变外部phead值)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
ListNode* Init_List2()             //第二种方式，不传参，直接在函数内建立哨兵并返回，再函数外接受
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//与不带头链表相比，此链表的第一个元素为phead->next,因为phead为哨兵；而前种链表第一个元素为phead
//前种链表空表状态为NULL，此种链表空表状态为phead=哨兵


//3.链表建立
//3.1 尾部插入
void ListPushBack(ListNode* phead, Elemtype e)
{
	assert(phead);
	ListNode* newnode = BuyListNode(e);
	ListNode*tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	//哨兵的prev找到尾，即可执行操作
}

//3.2 头部插入
void ListPushFront(ListNode* phead, Elemtype e)
{
	assert(phead);
	ListNode* newnode = BuyListNode(e);
	ListNode* first = phead->next;    //可以不定义first，直接用连续表示，但是要注意顺序
	first->prev = newnode;
	newnode->next = first;
	phead->next = newnode;
	newnode->prev = phead;
	//哨兵的next找到头，即可执行操作
}

//3.3 尾部删除
void ListPopBack(ListNode* phead)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	if (phead->next == phead) return;  //考虑没有数据的情况（只剩哨兵）
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}

//3.4 头部删除
void ListPopFront(ListNode* phead)
{
	assert(phead);
	ListNode* first = phead->next;
	if (phead->next == phead) return; //考虑没有数据的情况（只剩哨兵）
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
	first = NULL;
}

//3.5 查找
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
	//注意，cur从phead->next开始查找
}


//3.6 中部插入
void ListInsert(ListNode* pos, Elemtype e)   //单链表必须从表头开始，而双向链表可以直接从pos开始，前后的元素都能找到
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode*newnode = BuyListNode(e);
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
	//头插尾插也可以调用这个函数，让pos分别为phead、phead->prev
}

//3.7 中部删除
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
	//头删尾删也可以调用这个函数，让pos分别为phead->next、phead->prev
}

//3.8 打印
void ListPrint(ListNode* phead)  //空链表也不会有问题
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//3.9 归并 略

//4. 总结
//最优的链表结构，在任意位置插入删除数据时间复杂度均为O(1)，查找为O(N);(查找最优为：AVL树，红黑树，哈希表，B树，B+树等)
//三个结构，数据data，上一指针prev，下一指针next；创立新节点初始化时，data=e，prev和next=NULL
//与前一种链表相比，此种链表需要初始化，即创造哨兵，哨兵的创造即可保证表始终不为（NULL），空表状态为只有哨兵的状态,第一个元素为phead->next
//哨兵的prev和next均指向自己，使删除插入操作需要考虑的问题（如只剩一个元素，空表等）大大简化
//链表建立的全程操作中，需要保证传入的phead不为NULL，即哨兵存在的情况
//传入phead均不需要传二级指针，因为不需要改变外部的phead
//删除元素同时要保证至少有元素，即phead->next！=phead，否则误将哨兵删除
//中部插入和删除可以直接传入pos，不用像上一个链表一样从头开始寻找pos

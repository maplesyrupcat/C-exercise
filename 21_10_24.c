#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

//��̬˳���Ĵ���

#define INIT_SIZE 5     //��ʼ����
#define SIZE_ADD 3       //ÿ��������
typedef int Elemtype;    //���������������

//1.��̬˳���ṹ
typedef struct
{
	Elemtype * elem;     //�����ڴ�λ�ã�����������ݣ�
	int length;          //������ǰ���ȣ�
	int listsize;        //�������������������ݣ�
}SqList;

//2.˳���ĳ�ʼ������������Ҫ��ʼ����ÿ����Ӽ�����(malloc)��ɾ�����ͷ�(free)��
void Init_SqList(SqList* List)
{
	List->elem = (Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));    //��elem�������ڴ棬���ǿ���ʧ�����
	if (!(List->elem)) return;
	List->length = 0;                                              //��ʼ��Ϊ0
	List->listsize = INIT_SIZE;                                    //��ʼ���� INIT_SIZE
}

//3.˳���Ľ���                                      //˳����У�ÿ��Ԫ�ص����һ��
//3.1 β����������
void ListPushBack(SqList* List, Elemtype e)           //����ʱ��ֻ��Ҫ���ǿռ�������������ﵽ������
{
	if (List->length >= List->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(List->elem,
			(List->listsize + SIZE_ADD)*sizeof(Elemtype));   //���ռ�������realloc��������reallocʧ���������ֹ��ʧ���ݺ��ڴ�й©
		if (!newbase) return;
		List->elem = newbase;
		List->listsize += SIZE_ADD;                          //���ٿռ������׷��SIZE_ADD
	}
	List->elem[List->length] = e;                            //β����������
	List->length++;                                          //������
}
//3.2 ͷ����������
void ListPushFront(SqList* List, Elemtype e)     //˳����������ݣ����ǿռ��������  
{
	if (List->length >= List->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(List->elem,
			(List->listsize + SIZE_ADD)*sizeof(Elemtype));   //���ռ�������realloc��������reallocʧ���������ֹ��ʧ���ݺ��ڴ�й©
		if (!newbase) return;
		List->elem = newbase;
		List->listsize += SIZE_ADD;
	}
	int i;
	for (i = List->length - 1; i >= 0; i--)
	{
		List->elem[i + 1] = List->elem[i];         //ÿ��Ԫ�����κ��ƣ��Ӻ���ǰ����
	}
	List->elem[0] = e;                             //ͷ����������
	List->length++;                                //������
}
//3.3 β��ɾ������
void ListPopBack(SqList* List)                     //ɾ��ʱ������Ϊ�ձ�����
{
	if (List->length == 0)
		return;
	List->length--;                                //����һ��ɾ��ĩβ����
}
//3.4 ͷ��ɾ������
void ListPopFront(SqList* List)
{
	if (List->length == 0)                  //���ǿձ�����
		return;
	int i;
	for (i = 1; i < List->length; i++)
	{
		List->elem[i - 1] = List->elem[i];         //ÿ��Ԫ������ǰ�ƣ���ǰ�������
	}
	List->length--;                         //����һ��ɾ��ͷ������
}
//3.5 �м��������
void ListInsert(SqList* List, int k, Elemtype e)  //�ڵ�k��Ԫ��ǰ���룬���������1.k�ĺϷ��ԣ�2.�ռ��Ƿ�����
{
	if (k<1 || k>List->length + 1)    //1.�ж�k�ĺϷ��ԣ��ڵ�һ��Ԫ��ǰ����Ϊͷ�����ڵ�length+1��ǰ��������Ϊβ��
		return;
	if (List->length >= List->listsize)     //2.�жϿռ��Ƿ�����
	{
		Elemtype* newbase = (Elemtype*)realloc(List->elem,
			(List->listsize + SIZE_ADD)*sizeof(Elemtype));
		if (!newbase) return;
		List->elem = newbase;
		List->listsize += SIZE_ADD;
	}
	int i;
	for (i = List->length - 1; i >= k - 1; i--)
	{
		List->elem[i + 1] = List->elem[i];      //����k����֮���Ԫ�������ƣ��Ӻ���ǰ����
	}
	List->elem[k - 1] = e;     //�ڵ�k��λ�ò�������
	List->length++;            //������
	//����ѭ������ͷ��β�����������
}
//3.6 �м�ɾ������
void ListErase(SqList* List, int k)    //ɾ����k�����ݣ����������1.k�ĺϷ��ԣ�2.�ռ��Ƿ�Ϊ��
{
	if (k<1 || k>List->length)     //1.����k�ĺϷ���
		return;
	if (List->length == 0)         //2.���Ǳ��Ƿ�Ϊ��
		return;
	int i;
	for (i = k - 1 + 1; i < List->length; i++)
	{
		List->elem[i - 1] = List->elem[i];
	}
	List->length--;
	//��������ͷ��ɾ����β��ɾ��������
}

//3.7 �鲢�����˳���
//3.7.1�������µı�c,˫ָ��ķ�ʽ������a�ͱ�b�����ݷ����c��
//3.7.2����ab�����鲢����a����a�ĳ�����ҪΪa+b�ĳ��ȣ�������ָ��ķ�ʽ���

//4. ��ӡ
void ListPrint(SqList* List)
{
	int i;
	for (i = 0; i < List->length; i++)
	{
		printf("%d ", List->elem[i]);
	}
	printf("\n");
}

//5.�ܽ�
// ˳����и���Ԫ�����һ��
// 1. ˳���Ľṹ�弴Ϊ��|Ԫ������ָ�룬���ȣ����� |�����֣���������趨��ʼ����������������
// 2. ��ʼ����Ϊ��|���٣���ʼ�������ռ䣨����ʧ�ܣ���������Ϊ0��������Ϊ��ʼ| ������
// 3.1. β�����ӣ�1.���������Ƿ������������ݣ�����+=ADD_SIZE����2.���λ���������ݣ�3.��++
// 3.2. ͷ�����ӣ�1.���������Ƿ������������ݣ�����+=ADD_SIZE����2.ȫ�������ƶ�������ǰ����3.ͷ���������ݣ�4.��++
// 3.3. β��ɾ����1.�����Ƿ�Ϊ�գ�2.��--
// 3.4. ͷ��ɾ����1.�����Ƿ�Ϊ�գ�2.ȫ����ǰ�ƶ���ǰ��󣩣�3.��--
// 3.5. �м���룺1.����k�Ϸ��ԣ�2.���ǿռ��Ƿ�������3.��kλ�������ƶ���4.�������ݣ�5.��++
// 3.6. �м�ɾ����1.����k�Ϸ��ԣ�2.���ǿռ��Ƿ�Ϊ�գ�3.��k+1λ����ǰ�ƶ���4.��--
// 3.7. �鲢������˼·
// 4. ˳���ӡ
// ע�����
//     ���ٿռ�Ҫ����ʧ�����
//     �����������ݣ���Ҫ���ǿռ��������򿪱٣����ٺ��������ӣ����Ԫ�غ������
//     ����ɾ�����ݣ���Ҫ���ǿռ��Ƿ�Ϊ�գ�ɾ��Ԫ�غ������
//     �����м��������Ҫ����λ�õĺϷ���

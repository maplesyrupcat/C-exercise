#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

//动态顺序表的创建

#define INIT_SIZE 5     //初始容量
#define SIZE_ADD 3       //每次扩容量
typedef int Elemtype;    //所需表内数据类型

//1.动态顺序表结构
typedef struct
{
	Elemtype * elem;     //开辟内存位置（储存表内数据）
	int length;          //表长（当前长度）
	int listsize;        //表容量（若不够则扩容）
}SqList;

//2.顺序表的初始化（链表则不需要初始化，每次添加即新增(malloc)，删除则释放(free)）
void Init_SqList(SqList* List)
{
	List->elem = (Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));    //在elem处开辟内存，考虑开辟失败情况
	if (!(List->elem)) return;
	List->length = 0;                                              //初始表长为0
	List->listsize = INIT_SIZE;                                    //初始容量 INIT_SIZE
}

//3.顺序表的建立                                      //顺序表中，每个元素的情况一样
//3.1 尾部增加数据
void ListPushBack(SqList* List, Elemtype e)           //增加时则只需要考虑空间满的情况（表长达到容量）
{
	if (List->length >= List->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(List->elem,
			(List->listsize + SIZE_ADD)*sizeof(Elemtype));   //若空间满，则realloc，并考虑realloc失败情况，防止丢失数据和内存泄漏
		if (!newbase) return;
		List->elem = newbase;
		List->listsize += SIZE_ADD;                          //开辟空间后，容量追加SIZE_ADD
	}
	List->elem[List->length] = e;                            //尾部增加数据
	List->length++;                                          //表长增加
}
//3.2 头部增加数据
void ListPushFront(SqList* List, Elemtype e)     //顺序表增加数据，考虑空间已满情况  
{
	if (List->length >= List->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(List->elem,
			(List->listsize + SIZE_ADD)*sizeof(Elemtype));   //若空间满，则realloc，并考虑realloc失败情况，防止丢失数据和内存泄漏
		if (!newbase) return;
		List->elem = newbase;
		List->listsize += SIZE_ADD;
	}
	int i;
	for (i = List->length - 1; i >= 0; i--)
	{
		List->elem[i + 1] = List->elem[i];         //每个元素依次后移，从后往前进行
	}
	List->elem[0] = e;                             //头部增加数据
	List->length++;                                //表长增加
}
//3.3 尾部删除数据
void ListPopBack(SqList* List)                     //删除时，考虑为空表的情况
{
	if (List->length == 0)
		return;
	List->length--;                                //表长减一，删除末尾数据
}
//3.4 头部删除数据
void ListPopFront(SqList* List)
{
	if (List->length == 0)                  //考虑空表的情况
		return;
	int i;
	for (i = 1; i < List->length; i++)
	{
		List->elem[i - 1] = List->elem[i];         //每个元素依次前移，从前往后进行
	}
	List->length--;                         //表长减一，删除头部数据
}
//3.5 中间插入数据
void ListInsert(SqList* List, int k, Elemtype e)  //在第k个元素前插入，考虑情况：1.k的合法性，2.空间是否已满
{
	if (k<1 || k>List->length + 1)    //1.判断k的合法性，在第一个元素前增则为头增，在第length+1的前面增，即为尾增
		return;
	if (List->length >= List->listsize)     //2.判断空间是否已满
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
		List->elem[i + 1] = List->elem[i];      //将第k个及之后的元素往后移，从后往前进行
	}
	List->elem[k - 1] = e;     //在第k个位置插入数据
	List->length++;            //表长增加
	//上述循环对于头部尾部插入均满足
}
//3.6 中间删除数据
void ListErase(SqList* List, int k)    //删除第k个数据，考虑情况：1.k的合法性，2.空间是否为空
{
	if (k<1 || k>List->length)     //1.考虑k的合法性
		return;
	if (List->length == 0)         //2.考虑表是否为空
		return;
	int i;
	for (i = k - 1 + 1; i < List->length; i++)
	{
		List->elem[i - 1] = List->elem[i];
	}
	List->length--;
	//上述对于头部删除和尾部删除均满足
}

//3.7 归并有序的顺序表
//3.7.1，创立新的表c,双指针的方式，将表a和表b的数据放入表c；
//3.7.2，将ab，都归并进表a，则a的长度需要为a+b的长度，采用三指针的方式完成

//4. 打印
void ListPrint(SqList* List)
{
	int i;
	for (i = 0; i < List->length; i++)
	{
		printf("%d ", List->elem[i]);
	}
	printf("\n");
}

//5.总结
// 顺序表中各个元素情况一样
// 1. 顺序表的结构体即为：|元素类型指针，长度，容量 |三部分（定义宏来设定初始容量和增容容量）
// 2. 初始化即为：|开辟（初始容量）空间（考虑失败），长度置为0，容量置为初始| 三部分
// 3.1. 尾部增加：1.考虑容量是否已满否则扩容（容量+=ADD_SIZE），2.最后位置增加数据，3.表长++
// 3.2. 头部增加：1.考虑容量是否已满否则扩容（容量+=ADD_SIZE），2.全部往后移动（后向前），3.头部增加数据，4.表长++
// 3.3. 尾部删除：1.考虑是否为空，2.表长--
// 3.4. 头部删除：1.考虑是否为空，2.全部往前移动（前向后），3.表长--
// 3.5. 中间插入：1.考虑k合法性，2.考虑空间是否已满，3.从k位置往后移动，4.插入数据，5.表长++
// 3.6. 中间删除：1.考虑k合法性，2.考虑空间是否为空，3.从k+1位置往前移动，4.表长--
// 3.7. 归并：两种思路
// 4. 顺序打印
// 注意事项：
//     开辟空间要考虑失败情况
//     凡是增加数据，都要考虑空间已满否则开辟，开辟后容量增加，添加元素后表长增加
//     凡是删除数据，都要考虑空间是否为空，删除元素后表长减少
//     凡是中间操作，都要考虑位置的合法性

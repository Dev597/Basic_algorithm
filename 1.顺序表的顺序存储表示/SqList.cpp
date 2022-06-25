#include "SqList.h"

//顺序表L的初始化
Status InitList_Sq(SqList &L)
{
	//构造一个空的顺序表
	L.elem = new ElemType[MAXSIZE];//为顺序表分配空间
	if (!L.elem)
		exit(OVERFLOW);
	//存储分配失败
	L.length = 0;
	//空表长度为0
	return OK;
}

//销毁顺序表L
void DestroyList(SqList &L)
{
	if (L.elem)
		delete L.elem;//释放存储空间
}

//清空线性表L
void ClearList(SqList &L)
{
	L.length = 0;
	//将线性表的长度置为0
}

//求线性表L的长度
int GetLength(SqList L)
{
	return(L.length);
}

//判断线性表L是否为空
int IsEmpty(SqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

//顺序表的取值（根据位置i获取相应位置数据元素的内容
int GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length)//判断i值是否合理，若不合理，返回ERROR
		return ERROR;
	e = L.elem[i - 1];//第i-1的单元存储着第1个数据
	return OK;
}

//顺序表的查找
/**
	在线性表L中查找与指定值e相同的数据元素的位置
	从表的一端开始，逐个进行记录的关键字和给定值的比较。找到，返
	回该元素的位置序号，未找到，返回0。

	顺序表的查找算法分析
	基本操作：关键字同给定值比较,求平均查找次数
	平均查找长度ASL(Average Search Length):为确定记录在表中的位置，需要与给定值进行比较的关键字的个数的期望值叫做查找算法的平均查找长度。
	
 */
int LocateELem(SqList L, ElemType e)
{
	//在线性表L中查找值为e的数据元素，返回其序号（是第几个元素）
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;//查找成功，返回序号
	}
	return FALSE;//查找失败，返回0
}

//在线性表L中第i个位置插入新元素e
/**
算法思想：
	①判断插入位置i是否合法。
	②判断顺序表的存储空间是否已满，若已满返回ERROR。
	③将第n至第i位的元素依次向后移动一个位置，空出第个位置。
	④将要插入的新元素e放入第个位置。
	⑤表长加1,插入成功返回OK。
*/
Status Listlnsert_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1 ) 
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j >= i-1 ; --j)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

//删除线性表L中第个位置元素，用e返回
/**
	算法思想：
	①判断删除位置i是否合法（合法值为1≤i≤n)。
	②将欲删除的元素保留在e中。
	③将第i+1至第n位的元素依次向前移动一个位置。
	④表长减1,删除成功返回OK。 
 */
Status ListDelete_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j <= L.length - 1; ++j)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

Status ListShow_Sq(SqList L)
{
	if (L.length > 0)
	{
		for (int i = 0; i < L.length ; i++)
		{
			printf("%c  ", L.elem[i]);
		}
		printf("\n");
		return OK;
	}
	else
	{
		return ERROR;
	}
	
}
	
void test01()  
{ 
	//初始化顺序表
	SqList L;
	ElemType elem;
	Status isinit = InitList_Sq(L);
	if (isinit)
	{
		Listlnsert_Sq(L,1,'a');
		Listlnsert_Sq(L, 2, 'b');
		Listlnsert_Sq(L, 3, 'c');
		Listlnsert_Sq(L, 4, 'd');
		Listlnsert_Sq(L, 5, 'e');
	}
	
	ListShow_Sq(L);
	printf("顺序表的长度为%d\n", GetLength(L));

	

	if (!IsEmpty(L))
	{
		int i = 5;
		if (GetElem(L, i, elem))
		{
			printf("L[%d]值为%c\n", i,elem);
		}
	}

	ListDelete_Sq(L, 1, elem);
	printf("删除1后L 为");
	ListShow_Sq(L);

	printf("在1插入a L为");
	Listlnsert_Sq(L, 1, 'a');
	ListShow_Sq(L);

	ListDelete_Sq(L, 2, elem);
	printf("删除2后L 为");
	ListShow_Sq(L);

	ListDelete_Sq(L, 3, elem);
	printf("删除3后L 为");
	ListShow_Sq(L);

	printf("在2插入V L为");
	Listlnsert_Sq(L, 2, 'V');
	ListShow_Sq(L);

		
	int n = LocateELem(L, 'c');
	printf("c的位置是%d\n", n);



	printf("清空L\n");
	ClearList(L);
	ListShow_Sq(L);

	DestroyList(L);

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}
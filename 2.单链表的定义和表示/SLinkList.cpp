#include "SLinkList.h"

Status InitList_L(LinkList &L)
{
	L = new Lnode;
	L->next = NULL;
	return OK;
}

int ListEmpty(LinkList L)
{
	if (L->next)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

Status DestroyList_L(LinkList &L)//销毁单链表L
{
	Lnode* p;
	while (L)
	{
		p = L;//////
		L = L->next;
		delete(p);
	}
	return OK;
}

Status ClearList_L(LinkList &L)
{
	Lnode* p;
	Lnode* q;
#if 0
	while (L->next != NULL)
	{
		p = L->next;//////
		q = p->next;
		delete(p);
		L->next = q;
	}

#endif

#if 1
	p = L->next;

	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->data = NULL;
	return OK;
#endif

}

int ListLength(LinkList &L)
{
	Lnode* p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem_L(LinkList &L, int i, ElemType &e)
{
	Lnode *p = L->next;

#if 0
	if (!p || i < 0 || i > ListLength(L))
		return ERROR;
	for (int j = 1; j <= i; j++)
	{
		p = p->next;
	}
	e = p->data;
	return OK;
#endif

#if 1
	int j = 1;
	//初始化
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;//第i个元素不存在
	e = p->data;//取第1个元素
	return OK;
#endif
}


void test01()
{
	LinkList L;
	InitList_L(L);
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;

}
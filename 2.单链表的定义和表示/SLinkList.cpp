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
	Lnode* p ;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;	
	}
	return OK;
}

Status ClearList_L(LinkList &L)
{
	Lnode* p;
	Lnode* q;
	p = L->next;

	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
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

}

int  LocateELem_L(LinkList L, ElemType e)
{
	Lnode * p = L->next;
	int j = 1;
	while (p && p->data != e)
	{
		j++;
		p = p->next;
		
	}
	if (p)
	{
		return j;
	}
	else
	{
		return 0;
	}
}

Status Listlnsert_L(LinkList &L, int i, ElemType e)
{
	Lnode *p = L;
	int j = 0;
	while (p && j < i-1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return ERROR; 
	}
	Lnode *s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
	Lnode *p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p->next || j > i - 1)
	{
		return ERROR;
	}
	Lnode *q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}

void CreateList_H(LinkList &L, int n)
{
	Lnode * p;
	L = new Lnode;
	L->next = NULL;
	ElemType data;
	for (int i = n; i > 0; --i)
	{
		p = new Lnode;
		scanf(" %d", &data); //%d前面的空格代表清除制表符回车等符号
		p->data = data;
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_R(LinkList &L, int n)
{
	Lnode * p;

	L = new Lnode;
	L->next = NULL;
	ElemType data;

	Lnode * r = L;


	for (int i = 0; i < n; ++i)
	{
		p = new Lnode;
		scanf(" %d", &data); //%d前面的空格代表清除制表符回车等符号
		p->data = data;
		p->next = NULL;

		r->next = p;
		r = p;
	}
}

void ShowLinkList_Lint(LinkList L)
{
	Lnode *p = L->next;
	while (p)
	{
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("\n");
}

void test01()
{
	LinkList L;
	InitList_L(L);
	if (ListEmpty(L))
	{
		Listlnsert_L(L, 1, 1);
		Listlnsert_L(L, 2, 2);
		Listlnsert_L(L, 3, 3);
		Listlnsert_L(L, 3, 1); 
		Listlnsert_L(L, 2, 2); 
		Listlnsert_L(L, 1, 3);
	}
	ShowLinkList_Lint(L);
	printf("Linklist Length is %d\n", ListLength(L));
	ElemType elem;
	int i = 2;
	if (GetElem_L(L, i, elem))
	{
		printf("第%d个node的值为：%d\n", i, elem);
	}
	i = 5;
	if (GetElem_L(L, i, elem))
	{
		printf("第%d个node的值为：%d\n", i, elem);
	}
	printf("元素2在第%d个节点\n", LocateELem_L(L, 2));
	printf("元素3在第%d个节点\n", LocateELem_L(L, 3));

	ListDelete_L(L, 4, elem);
	printf("删除的第4个元素为%d\n", elem);
	
	if (ClearList_L(L))
	{
		printf("链表已清空\n");
	}
	Listlnsert_L(L, 1, 1);
	ShowLinkList_Lint(L);


	if (DestroyList_L(L))
	{
		printf("链表已销毁\n");
	}
	ShowLinkList_Lint(L);
	
}

void test02()
{
	LinkList L;

	CreateList_R(L, 3);
	
	ShowLinkList_Lint(L);
	Listlnsert_L(L, 3, 6);
	Listlnsert_L(L, 3, 6);
	Listlnsert_L(L, 3, 6);
	ShowLinkList_Lint(L);
	if (DestroyList_L(L))
	{
		printf("链表已销毁\n");
	}
}

void test03()
{
	LinkList L;

	CreateList_H(L, 3);

	ShowLinkList_Lint(L);
	Listlnsert_L(L, 3, 6);
	Listlnsert_L(L, 3, 6);
	Listlnsert_L(L, 3, 6);
	ShowLinkList_Lint(L);
	if (DestroyList_L(L))
	{
		printf("链表已销毁\n");
	}
}
int main()
{
	//test01();
	test03(); 
	system("pause");
	return EXIT_SUCCESS;

}
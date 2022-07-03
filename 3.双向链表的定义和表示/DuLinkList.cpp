#include "DuLinkList.h"

Status InitList_Du(DuLinkList &L)
{
	L = new DuLNode;
	L->data = 0;
	L->next = L->prior = L;
	return OK;
}

int ListEmpty_Du(DuLinkList L)
{
	if (L->next == L && L->prior == L)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Status DestroyList_Du(DuLinkList &L)//销毁单链表L
{
	DuLNode * p;
	DuLNode * q;
	p = L->next;
	while (p && p != L)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->prior = L->next = L;
	delete L;
	return OK;
}

Status ClearList_Du(DuLinkList &L)
{
	DuLNode * p;
	DuLNode * q;
	p = L->next;
	while (p && p != L)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->prior = L->next = L;
	return OK;

}

int ListLength_Du(DuLinkList &L)
{
	DuLNode * p = L->next;
	int i = 0;
	while (p && p!=L)
	{
		p = p->next;
		i++;
	}
	return i;
}

Status GetElem_Du(DuLinkList &L, int i, ElemType &e)
{
	DuLNode * p = L->next;
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


int  LocateELem_Du(DuLinkList L, ElemType e)
{
	DuLNode * p = L->next;
	int j = 1;
	//初始化
	while (p && p->data != e)
	{
		p = p->next;
		++j;
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

Status Listlnsert_Du(DuLinkList &L, int i, ElemType e)
{


	DuLNode * p = L;
	int j = 0;
	//初始化
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}

	DuLNode *s = new DuLNode;
	s->data = e;

	s->next = p->next;
	s->prior = p;
	p->next = s;
	p->next->prior = s;
	return OK;
}

Status Headlnsert_Du(DuLinkList &L, ElemType e)
{
	DuLNode *s = new DuLNode;
	s->data = e;

	s->next = L->next;
	s->prior = L->prior;

	L->next->prior = s;
	L->next = s;
	return OK;

}

Status Taillnsert_Du(DuLinkList &L, ElemType e)
{

	DuLNode* p = L;
	while (p->next != L) {
		p = p->next;
	}
	DuLNode* s = new DuLNode;
	s->data = e;
	s->prior = p;
	s->next = L;

	L->prior = s;
	p->next = s;
	return OK;

}

Status ListDelete_Du(DuLinkList &L, int i, ElemType &e)
{
	DuLNode * p = L;
	int j = 0;
	//初始化
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	DuLNode * pfree = p->next;
	e = pfree->data;

	p->next = p->next->next;
	p->next->next->prior = p;

	delete pfree;
	return OK;
}

void ShowLinkList_Du(DuLinkList L)
{
	DuLNode *p = L->next;
	while (p && p != L)
	{
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("\n");
}

void test01()
{
	DuLinkList M;
	InitList_Du(M);
	if (M)
	{
		printf("链表初始化完成\n");
	}

	Listlnsert_Du(M, 1, 1);
	Listlnsert_Du(M, 2, 3);
	Listlnsert_Du(M, 3, 4);
	Listlnsert_Du(M, 2, 2);
	Listlnsert_Du(M, 1, 0);

	printf("双向循环链表的长度为：%d\n", ListLength_Du(M));
	ShowLinkList_Du(M);

	ElemType elem = 0;
	ListDelete_Du(M, 1, elem);
	printf("删除第一个元素%d  后链表为\n", elem);
	ShowLinkList_Du(M);

	printf("使用头插法添加6后链表为\n");
	Headlnsert_Du(M, 6);
	ShowLinkList_Du(M);

	printf("使用尾插法添加7后链表为\n");
	Taillnsert_Du(M, 7);
	ShowLinkList_Du(M);

	ClearList_Du(M);
	if (ListEmpty_Du(M))
	{
		cout << "链表已经清空" << endl;
	}
	//DestroyList_Du(M);

}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;

}
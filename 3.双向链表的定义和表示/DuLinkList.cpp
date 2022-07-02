#include "DuLinkList.h"

Status InitList_Du(DuLinkList &L)
{
	L = new DuLNode;
	L->next = NULL;
	L->prior = NULL;
	return OK;
}

int ListEmpty_Du(DuLinkList L)
{
	if (L->next == L && L->next == L)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Status DestroyList_Du(DuLinkList &L);
{
	DuLNode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

Status ClearList_Du(DuLinkList &L);

int ListLength_Du(DuLinkList &L);

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


int  LocateELem_Du(DuLinkList L, ElemType e);

Status Listlnsert_Du(DuLinkList &L, int i, ElemType e)
{
	DuLNode * p = L->next;
	int j = 1;
	if (p && j < i)
	{

	}
}

Status ListDelete_Du(DuLinkList &L, int i, ElemType &e);

void ShowLinkList_Du(DuLinkList L);

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;

}
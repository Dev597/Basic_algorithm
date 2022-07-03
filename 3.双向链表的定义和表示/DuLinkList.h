#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


//函数结果状态代码 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;

}DuLNode, *DuLinkList;//表示类型

					 
Status InitList_Du(DuLinkList &L);


int ListEmpty_Du(DuLinkList L);


Status DestroyList_Du(DuLinkList &L);

Status ClearList_Du(DuLinkList &L);


int ListLength_Du(DuLinkList &L);


Status GetElem_Du(DuLinkList &L, int i, ElemType &e);



int  LocateELem_Du(DuLinkList L, ElemType e);



Status Listlnsert_Du(DuLinkList &L, int i, ElemType e);

Status Headlnsert_Du(DuLinkList &L, ElemType e);
Status Taillnsert_Du(DuLinkList &L, ElemType e);


Status ListDelete_Du(DuLinkList &L, int i, ElemType &e);




void ShowLinkList_Du(DuLinkList L);
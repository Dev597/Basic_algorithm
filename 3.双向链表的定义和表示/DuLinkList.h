#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


//�������״̬���� 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;

}DuLNode, *DuLinkList;//��ʾ����

					 
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
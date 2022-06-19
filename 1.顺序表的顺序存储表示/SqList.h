#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数结果状态代码 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;

#define MAXSIZE 100
//typedef  int  ElemType;

typedef struct
{
	ElemType *elem;//动态分配内存
	//ElemType elem[MAXSIZE];//静态分配内存
	int length;
}SqList;




//动态创建SqList
/**
C语言操作：
	malloc,free
		SqList L;
		L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
		free(L.elem);
C++语言操作：
	new,delete
	int *p1 = new int(10);
L.elem = new ElemType[MAXSIZE];
*/

//顺序表L的初始化
Status InitList_Sq(SqList &L);

//销毁顺序表L
void DestroyList(SqList &L);

//清空线性表L
void ClearList(SqList &L);

//求线性表L的长度
int GetLength(SqList L);

//判断线性表L是否为空
int IsEmpty(SqList L);

//顺序表的取值（根据位置i获取相应位置数据元素的内容
int GetElem(SqList L, int i, ElemType &e);

//顺序表的查找
int LocateELem(SqList L, ElemType e);

//在线性表L中第i个位置插入新元素e
Status Listlnsert_Sq(SqList &L, int i, ElemType e);

//删除线性表L中第个位置元素，用e返回
Status ListDelete_Sq(SqList &L, int i, ElemType e);

//输出顺序表
Status ListShow_Sq(SqList L);
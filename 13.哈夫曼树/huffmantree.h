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
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

typedef char  ElemType;

typedef struct TreeNode 
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}TreeNode;

typedef struct HFTree
{
	TreeNode *data;
	int length;
}HFTree;

HFTree* initTree(int* weight, int length);

int* selectMin(HFTree* T);

void createHFTree(HFTree* T);

void preOrder(HFTree* T, int index);
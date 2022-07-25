#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�������״̬���� 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
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
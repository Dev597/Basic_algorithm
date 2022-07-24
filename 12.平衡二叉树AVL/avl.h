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

typedef struct TreeNode {
	int data;
	int height;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

int getHeight(TreeNode* node);

int max(int a, int b);

void rrRotation(TreeNode* node, TreeNode** root);

void llRotation(TreeNode* node, TreeNode** root);

void avlInsert(TreeNode** T, int data);

void preOrder(TreeNode* T);


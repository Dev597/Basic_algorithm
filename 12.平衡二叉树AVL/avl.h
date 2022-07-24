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


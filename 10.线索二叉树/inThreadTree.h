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
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	struct TreeNode* parent;
	int ltag;
	int rtag;
}TreeNode;

void createTree(TreeNode** T, char* data, int* index);

void inThreadTree(TreeNode* T, TreeNode** pre);

TreeNode* getFirst_in(TreeNode* T);

TreeNode* getNext_in(TreeNode* node);
//////
void preThreadTree(TreeNode* T, TreeNode** pre);

TreeNode* getNext_pre(TreeNode* node);

//////////////////////////////////////////////////////////////////////////
void createTree_post(TreeNode** T, char* data, int* index, TreeNode* parent);

void postThreadTree(TreeNode* T, TreeNode** pre);

TreeNode* getFirst_post(TreeNode* T);

TreeNode* getNext_post(TreeNode* node);




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
	ElemType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

void createTree(TreeNode** T, char* data, int* index);

void preOrder(TreeNode* T);

void inOrder(TreeNode* T);

void postOrder(TreeNode* T);


//////////////////////////////////////////////////////////////////////////
//层次遍历
typedef struct QueueNode {
	TreeNode* data;
	struct QueueNode* pre;
	struct QueueNode* next;
}QueueNode;

QueueNode* initQueue();

void enQueue(TreeNode* data, QueueNode* Q);

int isEmpty(QueueNode* Q);

QueueNode* deQueue(QueueNode* Q);

void levelTraverse(QueueNode* Q, TreeNode* T);

//////////////////////////////////////////////////////////////////////////
//非递归遍历
typedef struct StackNode {
	TreeNode* data;
	struct StackNode* next;
}StackNode;

StackNode* initStack();

void push(TreeNode* data, StackNode* S);

int isEmpty(StackNode* S);

StackNode* pop(StackNode* S);

StackNode* getTop(StackNode* S);

void preOrder_noRecurs(TreeNode* T);

void inOrder_noRecurs(TreeNode* T);

void postOrder_noRecurs(TreeNode* T);
//////////////////////////////////////////////////////////////////////////



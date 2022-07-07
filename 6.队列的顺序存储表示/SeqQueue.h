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
#define MAXSIZE 10
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
// 循环队列的最大长度，最多可以存放MAXSIZE个元素。

typedef int ElemType;    // 自定义循环队列的数据元素为整数。

typedef struct
{
	ElemType data[MAXSIZE];   // 用数组存储循环队列中的元素。
	int front;                // 队列的头指针。
	int rear;                 // 队列的尾指针，指向队尾的下一个元素。
	int length;               // 队列的实际长度。    // xxx
}SeqQueue, *PSeqQueue;

// 循环队列QQ的初始化操作。
void InitQueue(PSeqQueue QQ);

// 销毁循环队列QQ。
void DestroyQueue(PSeqQueue QQ);

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType *ee);

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType *ee);

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PSeqQueue QQ);

// 清空循环队列。
void Clear(PSeqQueue QQ);

// 判断循环队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PSeqQueue QQ);

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqQueue QQ);

// 打印循环队列中全部的元素。
void PrintQueue(PSeqQueue QQ);

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PSeqQueue QQ, ElemType *ee);

  

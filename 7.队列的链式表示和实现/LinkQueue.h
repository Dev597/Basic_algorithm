#pragma once
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
#define MAXSIZE 20
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
#define MAXSIZE 10       // 循环队列的最大长度，最多可以存放MAXSIZE个元素。

typedef int ElemType;    // 自定义循环队列的数据元素为整数。
typedef struct LNode
{
	ElemType data;         // 存储队列中的元素。
	struct LNode *next;    // next指针。
}LNode;

typedef struct
{
	LNode *front, *rear;     // 队列的头指针和尾指针。
}LinkQueue, *PLinkQueue;

// 队列QQ的初始化操作。
int InitQueue(PLinkQueue QQ);

// 销毁队列QQ。
void DestroyQueue(PLinkQueue QQ);

// 清空队列。
void Clear(PLinkQueue QQ);

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PLinkQueue QQ, ElemType *ee);

// 打印队列中全部的元素。
void PrintQueue(PLinkQueue QQ);

// 求队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PLinkQueue QQ);

// 判断队列是否已满，链式队列不存在队满的说法。
int IsFull(PLinkQueue QQ);

// 判断队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PLinkQueue QQ);

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PLinkQueue QQ, ElemType *ee);

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PLinkQueue QQ, ElemType *ee);

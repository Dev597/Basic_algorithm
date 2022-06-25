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

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;

}Lnode,*LinkList;//表示类型

/**
 * 单链表(带头结点的单链表）的初始化
   即构造一个如图的空表
算法步骤
(1)生成新结点作头结点，用头指针L指向头结点。
(2)将头结点的指针域置空。
 */
Status InitList_L(LinkList &L);

/**
判断链表是否为空：
空表：链表中无元素，称为空链表（头指针和头结点仍然在）
算法思路
判断头结点指针域是否为空,是空返回1，非空返回0
 */
int ListEmpty(LinkList L);

/**
单链表的销毁：链表销毁后不存在
从头结点开始，依次释放所有元素
循环条件：L != NULL;
 */
Status DestroyList_L(LinkList &L);//销毁单链表L

/**
清空链表：链表存在，但无元素，成为空链表头指针和头结点仍然存在
依次释放所有节点，头结点指针域设置为空
 */
Status ClearList_L(LinkList &L);

/**
求单链表的表长
从首元节点开始依次计数
 */
int ListLength(LinkList &L);

/**
取值：取表中第i个元素
从链表的头指针出发，顺着链域next逐个结点往下搜索，直至搜索到第个
结点为止。因此，链表不是随机存取结构
【算法步骤】
1.从第1个结点（L->next)顺链扫描，用指针p指向当前扫描到的结点，p初值p=L->next。
2.j做计数器，累计当前扫描过的结点数，j初值为1。
3.当p指向扫描到的下一结点时，计数器j加1。
4.当j==i时，p所指的结点就是要找的第i个结点。
*/
Status GetElem_L(LinkList &L, int i, ElemType &e);


/**
查找按值:根据指定数据获取数据所在位置

 */

 /**
 查找按位置;
 */

/**
插入
 */

/**
删除
 */

/**
建立：
头插
尾插
 */
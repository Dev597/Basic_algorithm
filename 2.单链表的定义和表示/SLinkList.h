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
#define OVERFLOW -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;

}Lnode,*LinkList;//��ʾ����

/**
 * ������(��ͷ���ĵ������ĳ�ʼ��
   ������һ����ͼ�Ŀձ�
�㷨����
(1)�����½����ͷ��㣬��ͷָ��Lָ��ͷ��㡣
(2)��ͷ����ָ�����ÿա�
 */
Status InitList_L(LinkList &L);

/**
�ж������Ƿ�Ϊ�գ�
�ձ���������Ԫ�أ���Ϊ������ͷָ���ͷ�����Ȼ�ڣ�
�㷨˼·
�ж�ͷ���ָ�����Ƿ�Ϊ��,�ǿշ���1���ǿշ���0
 */
int ListEmpty(LinkList L);

/**
����������٣��������ٺ󲻴���
��ͷ��㿪ʼ�������ͷ�����Ԫ��
ѭ��������L != NULL;
 */
Status DestroyList_L(LinkList &L);//���ٵ�����L

/**
�������������ڣ�����Ԫ�أ���Ϊ������ͷָ���ͷ�����Ȼ����
�����ͷ����нڵ㣬ͷ���ָ��������Ϊ��
 */
Status ClearList_L(LinkList &L);

/**
������ı�
����Ԫ�ڵ㿪ʼ���μ���
 */
int ListLength(LinkList &L);

/**
ȡֵ��ȡ���е�i��Ԫ��
�������ͷָ�������˳������next����������������ֱ���������ڸ�
���Ϊֹ����ˣ������������ȡ�ṹ
���㷨���衿
1.�ӵ�1����㣨L->next)˳��ɨ�裬��ָ��pָ��ǰɨ�赽�Ľ�㣬p��ֵp=L->next��
2.j�����������ۼƵ�ǰɨ����Ľ������j��ֵΪ1��
3.��pָ��ɨ�赽����һ���ʱ��������j��1��
4.��j==iʱ��p��ָ�Ľ�����Ҫ�ҵĵ�i����㡣
*/
Status GetElem_L(LinkList &L, int i, ElemType &e);


/**
���Ұ�ֵ:����ָ�����ݻ�ȡ��������λ��

 */

 /**
 ���Ұ�λ��;
 */

/**
����
 */

/**
ɾ��
 */

/**
������
ͷ��
β��
 */
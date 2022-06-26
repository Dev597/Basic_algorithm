#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cin;


//�������״̬���� 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//#define OVERFLOW -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef int ElemType;

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
���㷨���衿
1.�ӵ�һ����������κ�e��Ƚϡ�
2.����ҵ�һ����ֵ��e��ȵ�����Ԫ�أ��򷵻����������еġ�λ�á���
��ַ��
3.��������������û���ҵ���ֵ��e��ȵ�Ԫ�أ��򷵻�0��
"NULL"��
 */
int  LocateELem_L(LinkList L, ElemType e);


/**
����: ��L�е�1��Ԫ��֮ǰ��������Ԫ��e
���㷨���衿
1�������ҵ�ai-1�Ĵ洢λ��p��
2������һ��������Ϊe���½��s��
3�������½�㣺
	���½���ָ����ָ����ai
	�ڽ��ai-1��ָ����ָ���½��
 */
Status Listlnsert_L(LinkList &L, int i, ElemType e);



/**
ɾ��:ɾ����i���ڵ�
���㷨���衿
1�������ҵ�ai-1�Ĵ洢λ��p,����Ҫɾ����ai��ֵ��
2����p->nextָ��ai+1��
3���ͷŽ��a�Ŀռ䡣
 */
Status ListDelete_L(LinkList &L, int i, ElemType &e);

/**
������
ͷ��:����������ͷ�巨����Ԫ�ز���������ͷ��,Ҳ��ǰ�巨
���㷨��
1.��һ���ձ�ʼ���ظ���������
2.�����½�㣬���������ݴ�ŵ��½�����������
3.�����һ����㿪ʼ�����ν��������뵽�����ǰ��
β��
 */
void CreateList_H(LinkList &L, int n);

/**
����������β�巨����Ԫ�ز���������β��
1.��һ���ձ�L��ʼ�����½��������뵽�����β����βָ��rָ������
��β��㡣
2.��ʼʱ��rͬL��ָ��ͷ��㡣ÿ����һ������Ԫ��������һ���½�㣬
���½����뵽β����rָ���½�㡣
*/
void CreateList_R(LinkList &L, int n);

void ShowLinkList_Lint(LinkList L);
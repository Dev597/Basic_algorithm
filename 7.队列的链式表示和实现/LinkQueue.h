#pragma once
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
#define MAXSIZE 20
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
#define MAXSIZE 10       // ѭ�����е���󳤶ȣ������Դ��MAXSIZE��Ԫ�ء�

typedef int ElemType;    // �Զ���ѭ�����е�����Ԫ��Ϊ������
typedef struct LNode
{
	ElemType data;         // �洢�����е�Ԫ�ء�
	struct LNode *next;    // nextָ�롣
}LNode;

typedef struct
{
	LNode *front, *rear;     // ���е�ͷָ���βָ�롣
}LinkQueue, *PLinkQueue;

// ����QQ�ĳ�ʼ��������
int InitQueue(PLinkQueue QQ);

// ���ٶ���QQ��
void DestroyQueue(PLinkQueue QQ);

// ��ն��С�
void Clear(PLinkQueue QQ);

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PLinkQueue QQ, ElemType *ee);

// ��ӡ������ȫ����Ԫ�ء�
void PrintQueue(PLinkQueue QQ);

// ����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PLinkQueue QQ);

// �ж϶����Ƿ���������ʽ���в����ڶ�����˵����
int IsFull(PLinkQueue QQ);

// �ж϶����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PLinkQueue QQ);

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PLinkQueue QQ, ElemType *ee);

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PLinkQueue QQ, ElemType *ee);

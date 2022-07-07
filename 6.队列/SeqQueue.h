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
#define MAXSIZE 10
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
// ѭ�����е���󳤶ȣ������Դ��MAXSIZE��Ԫ�ء�

typedef int ElemType;    // �Զ���ѭ�����е�����Ԫ��Ϊ������

typedef struct
{
	ElemType data[MAXSIZE];   // ������洢ѭ�������е�Ԫ�ء�
	int front;                // ���е�ͷָ�롣
	int rear;                 // ���е�βָ�룬ָ���β����һ��Ԫ�ء�
	int length;               // ���е�ʵ�ʳ��ȡ�    // xxx
}SeqQueue, *PSeqQueue;

// ѭ������QQ�ĳ�ʼ��������
void InitQueue(PSeqQueue QQ);

// ����ѭ������QQ��
void DestroyQueue(PSeqQueue QQ);

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType *ee);

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType *ee);

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PSeqQueue QQ);

// ���ѭ�����С�
void Clear(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ);

// ��ӡѭ��������ȫ����Ԫ�ء�
void PrintQueue(PSeqQueue QQ);

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PSeqQueue QQ, ElemType *ee);

  

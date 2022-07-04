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
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];   // ������洢˳��ջ�е�Ԫ�ء�
	int top;                  // ջ��ָ�룬��0��MAXSIZE-1��-1��ʾ��ջ��
							  // Ҳ���Դ�1��MAXSIZE��0��ʾ��ջ��
}SeqStack, *PSeqStack;

// ˳��ջSS�ĳ�ʼ��������
Status InitStack(PSeqStack SS);

// ����˳��ջSS��
void DestroyStack(PSeqStack SS);

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType *ee);

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType *ee);

// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS);

// ���˳��ջ��
void Clear(PSeqStack SS);

// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS);

// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS);

// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS);

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType *ee);
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

#define MAXSIZE 100
//typedef  int  ElemType;

typedef struct
{
	ElemType *elem;//��̬�����ڴ�
	//ElemType elem[MAXSIZE];//��̬�����ڴ�
	int length;
}SqList;




//��̬����SqList
/**
C���Բ�����
	malloc,free
		SqList L;
		L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
		free(L.elem);
C++���Բ�����
	new,delete
	int *p1 = new int(10);
L.elem = new ElemType[MAXSIZE];
*/

//˳���L�ĳ�ʼ��
Status InitList_Sq(SqList &L);

//����˳���L
void DestroyList(SqList &L);

//������Ա�L
void ClearList(SqList &L);

//�����Ա�L�ĳ���
int GetLength(SqList L);

//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L);

//˳����ȡֵ������λ��i��ȡ��Ӧλ������Ԫ�ص�����
int GetElem(SqList L, int i, ElemType &e);

//˳���Ĳ���
int LocateELem(SqList L, ElemType e);

//�����Ա�L�е�i��λ�ò�����Ԫ��e
Status Listlnsert_Sq(SqList &L, int i, ElemType e);

//ɾ�����Ա�L�еڸ�λ��Ԫ�أ���e����
Status ListDelete_Sq(SqList &L, int i, ElemType e);

//���˳���
Status ListShow_Sq(SqList L);
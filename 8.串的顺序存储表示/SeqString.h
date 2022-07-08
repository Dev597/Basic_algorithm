#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

//�������״̬���� 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAXSIZE 255
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;

typedef struct String
{
	//char data[MAXSIZE];
	char *data;
	unsigned int length;//�ַ�����ʵ�ʳ��ȡ�
}myString;

Status InitString(myString &S);//��ʼ��

Status StrAssign(myString &T,char *chars);//����ֵ

int StrCompare(myString S, myString T);//���Ƚ�

int StrLength(myString S);//�󴮳�

Status Concat(myString &T, myString S1, myString S2);//������

Status  SubString(myString &Sub, myString S, int pos,int  len);//���Ӵ� 

Status myStrCopy(myString &T, myString S);//������

int StrEmpty(myString S);//���п�

Status ClearString(myString &S);//��մ�

int Index_BF(myString S, myString T, int  pos);//�Ӵ���λ��

Status  Replace(myString &S, myString T, myString V);//���滻

Status Strlnsert(myString &S, int pos, myString T);//�Ӵ�����

Status StrDelete(myString &S,int  pos, int  len);//�Ӵ�ɾ��

Status DestroyString(myString &S);//������



String *initString();
Status StrAssign(myString *S, char *data);
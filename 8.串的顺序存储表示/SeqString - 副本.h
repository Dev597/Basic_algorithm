#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

//函数结果状态代码 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAXSIZE 255
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

typedef struct String
{
	//char data[MAXSIZE];
	char *data;
	unsigned int length;//字符串的实际长度。
}myString;

Status InitString(myString &S);//初始化

Status StrAssign(myString &T,char *chars);//串赋值

int StrCompare(myString S, myString T);//串比较

int StrLength(myString S);//求串长

Status Concat(myString &T, myString S1, myString S2);//串连结

Status  SubString(myString &Sub, myString S, int pos,int  len);//求子串 

Status myStrCopy(myString &T, myString S);//串拷贝

int StrEmpty(myString S);//串判空

Status ClearString(myString &S);//清空串

int Index_BF(myString S, myString T, int  pos);//子串的位置

Status  Replace(myString &S, myString T, myString V);//串替换

Status Strlnsert(myString &S, int pos, myString T);//子串插入

Status StrDelete(myString &S,int  pos, int  len);//子串删除

Status DestroyString(myString &S);//串销毁



String *initString();
Status StrAssign(myString *S, char *data);
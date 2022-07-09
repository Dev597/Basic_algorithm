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


typedef struct String {
	char* data;
	int len;
} String;

Status StrAssign(String *S, char *data);

void printString(String* s);

void forceMatch(String* master, String* sub);

int* getNext(String* s);

void kmpMatch(String* master, String* sub, int* next);
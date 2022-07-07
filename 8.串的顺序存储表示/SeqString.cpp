#include "SeqString.h"
Status InitString(myString &S)
{
	if (&S == NULL)
	{
		return ERROR;
	}
	memset(S.data, 0, MAXSIZE);
	S.length = 0;
	return OK;
}

Status StrAssign(myString &T, char *chars)
{
	if (&T == NULL || chars == NULL)
	{
		return ERROR;
	}
	int lenchars = sizeof(chars) / sizeof(char) ;  //字符个数+1    （加结束符）
	if ( MAXSIZE < lenchars ) 
	{
		printf("chars过长\n");
		return ERROR;
	}
	for (int i = 0; i < lenchars; i ++)
	{
		T.data[i] = chars[i];
	}
	T.length = lenchars - 1;//不算结束符
	return OK;
}


/*
 * StrCompare(myString *S, myString *T)
	S>T return 1
	S<T return -1
	S=T return 0;
 */
 
int StrCompare(myString *S, myString *T)
{
	if (T == NULL || S == NULL)
	{
		return ERROR;
	}
	int i = 0, j = 0;
	while ( (S->data[i] != '\0') && (S->data[i] == T->data[j]))
	{
		i++;
		j++;
	}
	int t = S->data[i] - T->data[j];
	if (t == 0)
		return 0;
	if (t > 0)
		return 1;
	if (t < 0)
		return -1;
}

int StrLength(myString S)
{
	if (&S == NULL)
	{
		return ERROR;
	}
	return S.length;
}
/**
* S1拼接在S2后返回T
*/
Status Concat(myString &T, myString S1, myString S2)
{
	if (&S1 == NULL || &S2 == NULL ||  &T == NULL)
	{
		return ERROR;
	}
	if (MAXSIZE < (S1.length - 1) + (S2.length - 1) )
	{
		return ERROR;
	}
	int i = 0, j = 0, k = 0;
	for (i; i < S1.length; i++)
	{
		T.data[i] = S1.data[i];
	}
	for (j; j < S2.length; j++)
	{
		T.data[i + j] = S2.data[j];
	}
	T.length = S1.length + S2.length;
	T.data[T.length + 1] = '\0';
	return OK;
}

Status  SubString(myString &Sub, myString S, int pos, int  len)
{
	if (&S == NULL || &Sub == NULL)
	{
		return ERROR;
	}
	for (int i = 0, j = pos - 1; i < len ; i++,j++)
	{
		Sub.data[i] = S.data[j];
	}
	Sub.length = len;
	return OK;

}

Status myStrCopy(myString &T, myString S)
{
	if (&S == NULL || &T == NULL)
	{
		return ERROR;
	}
	memcpy(&T.data, &S.data, S.length);
	T.length = S.length;
	return OK;
}

int StrEmpty(myString S)
{
	if (&S == NULL )
	{
		return ERROR;
	}
	if (S.length == 0)
	{
		return 1;
	}
	return 1;
}

Status ClearString(myString &S)
{
	if (&S == NULL)
	{
		return ERROR;
	}
	memset(&S.data, 0, MAXSIZE);
	return OK;
}

//////////////////////////////////使用BF算法
int Index_BF(myString S, myString T, int pos)
{
	if (&S == NULL || &T == NULL)
	{
		return -1;
	}
	int i = 0, j = 0;
	while (i < S.length && j< T.length)
	{
		if (S.data[i] == T.data[j])
		{
			i++;
			j++;
		}
		else
		{
			
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == T.length)
	{
		pos = i - T.length;
		return pos;
		printf("匹配成功\n");
	}
	else
	{
		printf("匹配失败\n");
		return ERROR;
	}
		
}
//////////////////////////////////使用KMP算法

Status DestroyString(myString *S)
{
	if (S == NULL)
	{
		return ERROR;
	}
	memset(S->data, 0, MAXSIZE);
	S->length = 0;
	delete S;
}

void show(myString S)
{
	printf("%s\n", S.data);
}

void test01()
{
	myString A;
	InitString(A);
	StrAssign(A, "abc");
	printf("A长度为%d   ",StrLength(A));
	show(A);
	myString B;
	InitString(B);
	StrAssign(B, "abb");
	printf("B长度为%d   ", StrLength(B));
	show(B);
	if (StrCompare(&A,&B))
	{
		printf("A 大于 B\n");
	}
	myString C;
	InitString(C);
	Concat(C, A, B);
	printf("AB合并\n");
	show(C);
	printf("截取子串\n");
	myString D;
	InitString(D);
	SubString(D, C, 1, 3);
	show(D);
	printf("Bcopy给A\n");
	ClearString(A);
	if (StrEmpty(A))
	{
		myStrCopy(A, B);
	}
	show(A);
	int in = 0;
	in = Index_BF(C, B, in);
	printf("B在C中的位置:%d\n", in);


}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}
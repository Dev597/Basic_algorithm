#include "SeqString.h"

#if 0
Status InitString(myString &S)
{
	if (&S == NULL)
	{
		return ERROR;
	}
	memset(S.data, 0, sizeof(S.data));
	S.length = 0;
	return OK;
}

Status StrAssign(myString &T, char *chars)
{
	if (&T == NULL || chars == NULL)
	{
		return ERROR;
	}
	int lenchars = sizeof(chars) / sizeof(char);  //字符个数+1    （加结束符）
	if (MAXSIZE < lenchars)
	{
		printf("chars过长\n");
		return ERROR;
	}
	for (int i = 0; i < lenchars; i++)
	{
		T.data[i] = chars[i];
	}
	T.length = lenchars - 1;//不算结束符
	return OK;

	/**
	* S1拼接在S2后返回T
	*/
	Status Concat(myString &T, myString S1, myString S2)
	{
		if (&S1 == NULL || &S2 == NULL || &T == NULL)
		{
			return ERROR;
		}
		if (MAXSIZE < (S1.length - 1) + (S2.length - 1))
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
		for (int i = 0, j = pos - 1; i < len; i++, j++)
		{
			Sub.data[i] = S.data[j];
		}
		Sub.length = len;
		return OK;
	}


	void show(myString S)
	{
		printf("%s\n", S.data);
	}


	Status DestroyString(myString *S)
	{
		if (S == NULL)
		{
			return ERROR;
		}
		memset(S->data, 0, sizeof(S->data));
		S->length = 0;
		free(S);
		S = NULL;
	}

	void test01()
	{
		myString A;
		InitString(A);
		StrAssign(A, "abc");
		printf("A长度为%d   ", StrLength(A));
		show(A);
		myString B;
		InitString(B);
		StrAssign(B, "abb");
		printf("B长度为%d   ", StrLength(B));
		show(B);
		if (StrCompare(&A, &B))
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
}
#endif


#if 1

String *initString()
{
	myString *S = (myString *)malloc(sizeof(myString));
	S->length = 0;
	S->data = NULL;
	return S;
}

Status StrAssign(myString *S, char *data)
{
	if (&S == NULL || data == NULL)
	{
		delete data;
		return ERROR;
	}
	int len = 0;
	char * temp = data;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (len == 0)
	{
		S->data = NULL;
		S->length = 0;
	}
	else
	{
		temp = data;
		S->length = len ;
		S->data = (char *)malloc(sizeof(char) * (len + 1));
		for (int i = 0; i < len; i++, temp++)
		{
			S->data[i] = *temp;
		}
	}
}

void printString(String *S)
{
	for (size_t i = 0; i < S->length; i++)
	{
		printf(i == 0 ? "%c" : " -> %c", S->data[i]);
	}
	printf("\n");
}

#endif




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
	while ((S->data[i] != '\0') && (S->data[i] == T->data[j]))
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
	if (&S == NULL)
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
	memset(S.data, 0, sizeof(S.data));
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
	while (i < S.length && j < T.length)
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
		pos = i - T.length ;
		printf("匹配成功\n");
		return pos;
	}
	else
	{
		printf("匹配失败\n");
		return ERROR;
	}

}
//////////////////////////////////使用KMP算法
// 根据模式串tstr，计算next数组，字符串的起始位置从0开始。
 void getNext(myString *S,int *next)
//void getNext(myString *S, int next[])
{
	if ((S == 0) || (next == 0)) return;  // 判断空指针。

	int tlen = S->length;//  // 模式串的长度。

							  // 如果模式串的长度小于3，无需计算next数组，直接返回。
	if (tlen == 0) return;
	if (tlen == 1) { next[0] = -1; return; }
	if (tlen == 2) { next[0] = -1; next[1] = 0; return; }

	next[0] = -1;  // 位置0直接填入-1。
	next[1] = 0;   // 位置1直接填入0。

				   // 如果想调试本函数，放开// xxx就可以了。

	int ii;

	// 循环从2开始，位置0和1不必计算。
	for (ii = 2; ii < tlen; ii++)
	{
		// 显示子串。
		// xxx char p0[tlen]; 
		// xxx memset(p0,0,sizeof(p0));
		// xxx strncpy(p0,tstr,ii); 
		// xxx printf("p0=%s  ",p0);

		int maxlen = 0;  // 最长公共前后缀的长度。

						 // 用一个循环，得到全部的前缀和后缀，并判断最长公共前后缀。
		int jj = 1;
		for (jj = 1; jj < ii; jj++)
		{
			char *p1 = (char *)malloc(S->length);
			char *p2 = (char *)malloc(S->length);
			memset(p1, 0, sizeof(p1));
			memset(p2, 0, sizeof(p2));

			strncpy(p1, S->data, jj);       // 取前缀。
			strncpy(p2, S->data + ii - jj, jj); // 取后缀。

											 // xxx printf("%s %s    ",p1,p2);

											 // 判断前后缀是否相同，相同就记下jj的值。
			if (strcmp(p1, p2) == 0) maxlen = jj;
		}

		// xxx printf(" maxlen=%d\n",maxlen);  
		next[ii] = maxlen;
	}

	// xxx printf("next "); int kk;for (kk=0;kk<strlen(tstr);kk++) printf("%d ",next[kk]); printf("\n");

	return;
}

// 根据模式串tstr和next数组计算nextval数组，字符串的起始位置从0开始。
 void getnextval(char *tstr,int *next,int *nextval)
//void getnextval(char tstr[], int next[], int nextval[])
{
	if ((tstr == 0) || (next == 0) || (nextval == 0)) return;  // 判断空指针。

	int tlen = strlen(tstr);  // 模式串的长度。

	nextval[0] = -1;   // 位置0直接填入-1。

	int ii;

	// 从第1个位置开始扫描。
	for (ii = 1; ii < tlen; ii++)
	{
		if (tstr[ii] == tstr[next[ii]])
			nextval[ii] = nextval[next[ii]];
		else
			nextval[ii] = next[ii];
	}
}
//////////////////////////////////////////////////////////////////////////
int Index_KMP(myString S, myString T, int pos)
{
	if (&S == NULL || &T == NULL)
	{
		return -1;
	}
	int * next = (int *)malloc(T.length);
	getNext(&T, next);
	for (int kk = 0; kk < T.length; kk++)
		printf("%d ", next[kk]);

	int i = 0, j = 0;
	while (i < S.length && j < T.length)
	{
		if ((j == -1) || S.data[i] == T.data[j])
		{
			i++; j++;  // 继续比较后面的字符。
		}
		else
		{
			j = next[j]; // 根据nextval数组模式串指针回溯。
		}
	}
	if (j == T.length)
	{
		pos = i - T.length;
		printf("匹配成功\n");
		return pos;
	}
	else
	{
		printf("匹配失败\n");
		return ERROR;
	}

}



void test02()
{
	myString *A = initString();
	printf("主串A:\n");
	StrAssign(A, "abaabbabc");

	printString(A);
	printf("长度为%d\n", StrLength(*A));
	//////////////////////////////////////////////////////////////////////////
	myString *B = initString();
	printf("子串B:\n");
	StrAssign(B, "bba");

	printString(B);
	printf("长度为%d\n", StrLength(*B));
	//////////////////////////////////////////////////////////////////////////
	if (StrCompare(B, A))
	{
		printf("B 大于 A\n");
	}

//////////////////////////////////////////////////////////////////////////
	myString *D = initString();
	printf("串D:\n");
	StrAssign(D, "ababa");
	//printf("%C", D->data[0]);
	printString(D);
	printf("长度为%d\n", StrLength(*D));

	
	int * next = (int *)malloc(D->length) ;
	getNext(D, next);
	printf("next "); 
	int kk; 
	for (kk = 0; kk < D->length; kk++) 
		printf("%d ", next[kk]); 
	printf("\n");


	//////////////////////////////////////////////////////////////////////////
	myString *C = initString();
	printf("串C:\n");
	StrAssign(C, "c");
	ClearString(*C);
	if (StrEmpty(*C))
	{
		myStrCopy(*C, *B);
	}
	printf("B  copy  给 C\n");
	printString(C);
	printf("长度为%d\n", StrLength(*C));

	int in = 0;
	in = Index_KMP(*A, *B, in);
	printf("B在A中的位置:%d\n", in);




}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;

}
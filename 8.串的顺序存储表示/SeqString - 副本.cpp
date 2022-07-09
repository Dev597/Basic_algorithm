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
	int lenchars = sizeof(chars) / sizeof(char);  //�ַ�����+1    ���ӽ�������
	if (MAXSIZE < lenchars)
	{
		printf("chars����\n");
		return ERROR;
	}
	for (int i = 0; i < lenchars; i++)
	{
		T.data[i] = chars[i];
	}
	T.length = lenchars - 1;//���������
	return OK;

	/**
	* S1ƴ����S2�󷵻�T
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
		printf("A����Ϊ%d   ", StrLength(A));
		show(A);
		myString B;
		InitString(B);
		StrAssign(B, "abb");
		printf("B����Ϊ%d   ", StrLength(B));
		show(B);
		if (StrCompare(&A, &B))
		{
			printf("A ���� B\n");
		}
		myString C;
		InitString(C);
		Concat(C, A, B);
		printf("AB�ϲ�\n");
		show(C);
		printf("��ȡ�Ӵ�\n");
		myString D;
		InitString(D);
		SubString(D, C, 1, 3);
		show(D);
		printf("Bcopy��A\n");
		ClearString(A);
		if (StrEmpty(A))
		{
			myStrCopy(A, B);
		}
		show(A);
		int in = 0;
		in = Index_BF(C, B, in);
		printf("B��C�е�λ��:%d\n", in);


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

//////////////////////////////////ʹ��BF�㷨
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
		printf("ƥ��ɹ�\n");
		return pos;
	}
	else
	{
		printf("ƥ��ʧ��\n");
		return ERROR;
	}

}
//////////////////////////////////ʹ��KMP�㷨
// ����ģʽ��tstr������next���飬�ַ�������ʼλ�ô�0��ʼ��
 void getNext(myString *S,int *next)
//void getNext(myString *S, int next[])
{
	if ((S == 0) || (next == 0)) return;  // �жϿ�ָ�롣

	int tlen = S->length;//  // ģʽ���ĳ��ȡ�

							  // ���ģʽ���ĳ���С��3���������next���飬ֱ�ӷ��ء�
	if (tlen == 0) return;
	if (tlen == 1) { next[0] = -1; return; }
	if (tlen == 2) { next[0] = -1; next[1] = 0; return; }

	next[0] = -1;  // λ��0ֱ������-1��
	next[1] = 0;   // λ��1ֱ������0��

				   // �������Ա��������ſ�// xxx�Ϳ����ˡ�

	int ii;

	// ѭ����2��ʼ��λ��0��1���ؼ��㡣
	for (ii = 2; ii < tlen; ii++)
	{
		// ��ʾ�Ӵ���
		// xxx char p0[tlen]; 
		// xxx memset(p0,0,sizeof(p0));
		// xxx strncpy(p0,tstr,ii); 
		// xxx printf("p0=%s  ",p0);

		int maxlen = 0;  // �����ǰ��׺�ĳ��ȡ�

						 // ��һ��ѭ�����õ�ȫ����ǰ׺�ͺ�׺�����ж������ǰ��׺��
		int jj = 1;
		for (jj = 1; jj < ii; jj++)
		{
			char *p1 = (char *)malloc(S->length);
			char *p2 = (char *)malloc(S->length);
			memset(p1, 0, sizeof(p1));
			memset(p2, 0, sizeof(p2));

			strncpy(p1, S->data, jj);       // ȡǰ׺��
			strncpy(p2, S->data + ii - jj, jj); // ȡ��׺��

											 // xxx printf("%s %s    ",p1,p2);

											 // �ж�ǰ��׺�Ƿ���ͬ����ͬ�ͼ���jj��ֵ��
			if (strcmp(p1, p2) == 0) maxlen = jj;
		}

		// xxx printf(" maxlen=%d\n",maxlen);  
		next[ii] = maxlen;
	}

	// xxx printf("next "); int kk;for (kk=0;kk<strlen(tstr);kk++) printf("%d ",next[kk]); printf("\n");

	return;
}

// ����ģʽ��tstr��next�������nextval���飬�ַ�������ʼλ�ô�0��ʼ��
 void getnextval(char *tstr,int *next,int *nextval)
//void getnextval(char tstr[], int next[], int nextval[])
{
	if ((tstr == 0) || (next == 0) || (nextval == 0)) return;  // �жϿ�ָ�롣

	int tlen = strlen(tstr);  // ģʽ���ĳ��ȡ�

	nextval[0] = -1;   // λ��0ֱ������-1��

	int ii;

	// �ӵ�1��λ�ÿ�ʼɨ�衣
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
			i++; j++;  // �����ȽϺ�����ַ���
		}
		else
		{
			j = next[j]; // ����nextval����ģʽ��ָ����ݡ�
		}
	}
	if (j == T.length)
	{
		pos = i - T.length;
		printf("ƥ��ɹ�\n");
		return pos;
	}
	else
	{
		printf("ƥ��ʧ��\n");
		return ERROR;
	}

}



void test02()
{
	myString *A = initString();
	printf("����A:\n");
	StrAssign(A, "abaabbabc");

	printString(A);
	printf("����Ϊ%d\n", StrLength(*A));
	//////////////////////////////////////////////////////////////////////////
	myString *B = initString();
	printf("�Ӵ�B:\n");
	StrAssign(B, "bba");

	printString(B);
	printf("����Ϊ%d\n", StrLength(*B));
	//////////////////////////////////////////////////////////////////////////
	if (StrCompare(B, A))
	{
		printf("B ���� A\n");
	}

//////////////////////////////////////////////////////////////////////////
	myString *D = initString();
	printf("��D:\n");
	StrAssign(D, "ababa");
	//printf("%C", D->data[0]);
	printString(D);
	printf("����Ϊ%d\n", StrLength(*D));

	
	int * next = (int *)malloc(D->length) ;
	getNext(D, next);
	printf("next "); 
	int kk; 
	for (kk = 0; kk < D->length; kk++) 
		printf("%d ", next[kk]); 
	printf("\n");


	//////////////////////////////////////////////////////////////////////////
	myString *C = initString();
	printf("��C:\n");
	StrAssign(C, "c");
	ClearString(*C);
	if (StrEmpty(*C))
	{
		myStrCopy(*C, *B);
	}
	printf("B  copy  �� C\n");
	printString(C);
	printf("����Ϊ%d\n", StrLength(*C));

	int in = 0;
	in = Index_KMP(*A, *B, in);
	printf("B��A�е�λ��:%d\n", in);




}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;

}